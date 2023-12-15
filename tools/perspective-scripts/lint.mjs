// ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
// ┃ ██████ ██████ ██████       █      █      █      █      █ █▄  ▀███ █       ┃
// ┃ ▄▄▄▄▄█ █▄▄▄▄▄ ▄▄▄▄▄█  ▀▀▀▀▀█▀▀▀▀▀ █ ▀▀▀▀▀█ ████████▌▐███ ███▄  ▀█ █ ▀▀▀▀▀ ┃
// ┃ █▀▀▀▀▀ █▀▀▀▀▀ █▀██▀▀ ▄▄▄▄▄ █ ▄▄▄▄▄█ ▄▄▄▄▄█ ████████▌▐███ █████▄   █ ▄▄▄▄▄ ┃
// ┃ █      ██████ █  ▀█▄       █ ██████      █      ███▌▐███ ███████▄ █       ┃
// ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
// ┃ Copyright (c) 2017, the Perspective Authors.                              ┃
// ┃ ╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌╌ ┃
// ┃ This file is part of the Perspective library, distributed under the terms ┃
// ┃ of the [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0). ┃
// ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

import sh from "./sh.mjs";
import * as url from "url";
import dotenv from "dotenv";

dotenv.config({ path: "./.perspectiverc" });

export function lint(task = sh`--check`) {
    const cmd = sh`prettier ${task} "examples/**/*.js" "examples/**/*.tsx" "tools/perspective-scripts/*.mjs" "rust/**/*.ts" "rust/**/*.js" "packages/**/*.js" "packages/**/*.ts" "cpp/**/*.js"`;
    cmd.sh`prettier --prose-wrap=always ${task} "docs/docs/*.md"`;
    cmd.sh`prettier ${task} "**/*.yml"`;
    cmd.sh`prettier ${task} "**/less/*.less"`;
    cmd.sh`prettier ${task} "**/html/*.html"`;
    cmd.sh`prettier ${task} "packages/**/package.json" "rust/**/package.json" "examples/**/package.json" "docs/package.json"`;

    // cmd.sh`node tools/perspective-scripts/fix_cpp.mjs`;

    cmd.runSync();
}

if (import.meta.url.startsWith("file:")) {
    if (process.argv[1] === url.fileURLToPath(import.meta.url)) {
        if (
            !process.env.PSP_LINT_ONLY ||
            process.env.PSP_LINT_ONLY === "python"
        ) {
            await import("./lint_python.mjs");
        }
        if (!process.env.PSP_LINT_ONLY || process.env.PSP_LINT_ONLY === "cpp") {
            try {
                const module = await import("./lint_cpp.mjs");
                module.lint();
            } catch (e) {
                console.warn("C++ linting failed, skipping");
            }
        }
        const { default: run } = await import("./lint_headers.mjs");
        const exit_code = await run(false);
        if (!process.env.PSP_LINT_ONLY || process.env.PSP_LINT_ONLY === "js") {
            lint(sh`--check`);
        }
        process.exit(exit_code);
    }
}
