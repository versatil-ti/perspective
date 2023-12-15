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
import * as fs from "fs";
import * as url from "url";
import * as os from "os";
import glob from "glob";

const __dirname = url.fileURLToPath(new URL(".", import.meta.url)).slice(0, -1);

export function lint() {
    if (process.env.PSP_PROJECT === "js") {
        const cppPath = sh.path`${__dirname}/../../cpp/perspective`;
        const cppDistPath = sh.path`${cppPath}/dist/release`;
        tidy(cppDistPath, sh.path`${cppPath}/src`);
    } else if (process.env.PSP_PROJECT === "python") {
        const cppPath = sh.path`${__dirname}/../../python/perspective`;
        const cppDistPath = sh.path`${cppPath}/build/last_build`;
        tidy(cppDistPath, sh.path`${cppPath}/perspective`);
    } else {
        console.error("Unknown project type, skipping lint");
    }
}

/** @typedef {import('./sh.mjs').Command} Command */

/**
 * Runs clang tidy on the source directory using the compile_commands.json
 * from the build directory.
 *
 * @param {string} buildDir
 * @param {string} sourceDir
 */
function tidy(buildDir, sourceDir) {
    if (!checkClangTidy()) {
        console.warn("run-clang-tidy not found, skipping lint");
        return;
    }
    if (fs.existsSync(buildDir)) {
        const jobs = os.cpus().length;
        const sources = glob.sync(`${sourceDir}/**/*.{cpp,h}`);
        const cmd = sh`run-clang-tidy -use-color -p${buildDir} -j${jobs} ${sources}`;
        // const cmd = sh`run-clang-tidy -p${buildDir} -j${jobs} ${sourceDir}/**/*.{cpp,h}`;
        cmd.runSync();
    } else {
        console.warn("No C++ build directory found, skipping lint");
    }
}

function checkClangTidy() {
    try {
        sh`which -s run-clang-tidy`.runSync();
        return true;
    } catch (e) {
        return false;
    }
}
