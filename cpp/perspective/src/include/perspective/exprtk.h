/******************************************************************************
 *
 * Copyright (c) 2019, the Perspective Authors.
 *
 * This file is part of the Perspective library, distributed under the terms of
 * the Apache License 2.0.  The full license can be found in the LICENSE file.
 *
 */

#pragma once

#include <perspective/scalar.h>
#include <perspective/type_check.h>

namespace exprtk {

using perspective::mknone;
using perspective::mktscalar;
using perspective::t_tscalar;
using perspective::t_type_check_result;

namespace details {
    namespace numeric {
        namespace details {

            /**
             * Allows for tag dispatching so that the overloads in this header
             * are called for t_tscalar operations.
             */
            struct t_tscalar_type_tag;
            struct t_type_check_result_type_tag;

            template <typename T>
            inline T const_pi_impl(t_tscalar_type_tag);
            template <typename T>
            inline T const_e_impl(t_tscalar_type_tag);

            template <typename T>
            inline int to_int32_impl(const T& v, t_tscalar_type_tag);

            template <typename T>
            inline long long int to_int64_impl(const T& v, t_tscalar_type_tag);

            template <typename T>
            inline T const_pi_impl(t_type_check_result_type_tag);
            template <typename T>
            inline T const_e_impl(t_type_check_result_type_tag);

            template <typename T>
            inline int to_int32_impl(const T& v, t_type_check_result_type_tag);

            template <typename T>
            inline long long int to_int64_impl(
                const T& v, t_type_check_result_type_tag);

#define define_unary_function_impl_header(FunctionName)                        \
    template <typename T>                                                      \
    inline T FunctionName##_impl(const T v, t_tscalar_type_tag);               \
    template <typename T>                                                      \
    inline T FunctionName##_impl(const T v, t_type_check_result_type_tag);

            // clang-format off

    define_unary_function_impl_header(abs)
    define_unary_function_impl_header(acos)
    define_unary_function_impl_header(acosh)
    define_unary_function_impl_header(asin)
    define_unary_function_impl_header(asinh)
    define_unary_function_impl_header(atan)
    define_unary_function_impl_header(atanh)
    define_unary_function_impl_header(ceil)
    define_unary_function_impl_header(cos)
    define_unary_function_impl_header(cosh)
    define_unary_function_impl_header(exp)
    define_unary_function_impl_header(expm1)
    define_unary_function_impl_header(floor)
    define_unary_function_impl_header(log)
    define_unary_function_impl_header(log10)
    define_unary_function_impl_header(log2)
    define_unary_function_impl_header(log1p)
    define_unary_function_impl_header(neg)
    define_unary_function_impl_header(pos)
    define_unary_function_impl_header(round)
    define_unary_function_impl_header(sin)
    define_unary_function_impl_header(sinc)
    define_unary_function_impl_header(sinh)
    define_unary_function_impl_header(sqrt)
    define_unary_function_impl_header(tan)
    define_unary_function_impl_header(tanh)
    define_unary_function_impl_header(cot)
    define_unary_function_impl_header(sec)
    define_unary_function_impl_header(csc)
    define_unary_function_impl_header(r2d)
    define_unary_function_impl_header(d2r)
    define_unary_function_impl_header(d2g)
    define_unary_function_impl_header(g2d)
    define_unary_function_impl_header(notl)
    define_unary_function_impl_header(sgn)
    define_unary_function_impl_header(erf)
    define_unary_function_impl_header(erfc)
    define_unary_function_impl_header(ncdf)
    define_unary_function_impl_header(frac)
    define_unary_function_impl_header(trunc)

            // clang-format on

#undef define_unary_function_impl_header

#define define_binary_function_impl_header(FunctionName)                       \
    template <typename T>                                                      \
    inline T FunctionName##_impl(const T v0, const T v1, t_tscalar_type_tag);  \
    template <typename T>                                                      \
    inline T FunctionName##_impl(                                              \
        const T v0, const T v1, t_type_check_result_type_tag);

                // clang-format off
    // except reserved words: and, or, xor
    define_binary_function_impl_header(min)
    define_binary_function_impl_header(max)
    define_binary_function_impl_header(equal)
    define_binary_function_impl_header(nequal)
    define_binary_function_impl_header(modulus)
    define_binary_function_impl_header(pow)
    define_binary_function_impl_header(logn)
    define_binary_function_impl_header(root)
    define_binary_function_impl_header(roundn)
    define_binary_function_impl_header(hypot)
    define_binary_function_impl_header(atan2)
    define_binary_function_impl_header(shr)
    define_binary_function_impl_header(shl)
    define_binary_function_impl_header(nand)
    define_binary_function_impl_header(nor)
    define_binary_function_impl_header(xnor)
            // clang-format on

#undef define_binary_function_impl_header

                                                    template <typename T>
                                                    inline T
                and_impl(const T v0, const T v1, t_tscalar_type_tag);

            template <typename T>
            inline T or_impl(const T v0, const T v1, t_tscalar_type_tag);

            template <typename T>
            inline T xor_impl(const T v0, const T v1, t_tscalar_type_tag);

            template <typename T>
            inline bool is_integer_impl(const T& v, t_tscalar_type_tag);

            template <typename T>
            inline T and_impl(
                const T v0, const T v1, t_type_check_result_type_tag);

            template <typename T>
            inline T or_impl(
                const T v0, const T v1, t_type_check_result_type_tag);

            template <typename T>
            inline T xor_impl(
                const T v0, const T v1, t_type_check_result_type_tag);

            template <typename T>
            inline bool is_integer_impl(
                const T& v, t_type_check_result_type_tag);

            // #if (defined(_MSC_VER) && (_MSC_VER >= 1900)) ||
            // !defined(_MSC_VER)
            // #define exprtk_define_erf(TT,impl)           \
// inline TT erf_impl(TT v) { return impl(v); } \

            // exprtk_define_erf(      float,::erff)
            // exprtk_define_erf(     double,::erf )
            // exprtk_define_erf(long double,::erfl)
            // #undef exprtk_define_erf
            // #endif

            // #if (defined(_MSC_VER) && (_MSC_VER >= 1900)) ||
            // !defined(_MSC_VER)
            // #define exprtk_define_erfc(TT,impl)           \
// inline TT erfc_impl(TT v) { return impl(v); } \

            // exprtk_define_erfc(      float,::erfcf)
            // exprtk_define_erfc(     double,::erfc )
            // exprtk_define_erfc(long double,::erfcl)
            // #undef exprtk_define_erfc
            // #endif

        } // end namespace details
    }     // end namespace numeric

    inline bool is_true(const t_tscalar& v);
    inline bool is_true(const t_type_check_result& v);

    inline bool is_false(const t_tscalar& v);
    inline bool is_false(const t_type_check_result& v);

    template <typename Iterator>
    inline bool string_to_real(Iterator& itr_external, const Iterator end,
        t_tscalar& t, numeric::details::t_tscalar_type_tag);

    template <typename Iterator>
    inline bool string_to_real(Iterator& itr_external, const Iterator end,
        t_type_check_result& t, numeric::details::t_type_check_result_type_tag);

} // end namespace details
} // end namespace exprtk

// exprtk needs to be imported after the type tags have been declared.
// #define exprtk_enable_debugging

// for some reason, break/continue will break expression.value() when it is
// called, but enabling this ifdef creates a litany of compiler warnings
// about misleading indentation inside exprtk.hpp. Considering that the UI
// will not allow while/continue to be used, this should be ok.
// #define exprtk_disable_break_continue

#define exprtk_disable_return_statement
#define exprtk_disable_rtl_io_file
#include <exprtk.hpp>

namespace exprtk {
namespace details {
    namespace numeric {
        namespace details {

#define UNARY_STD_FUNCTION_BODY(FUNC)                                          \
    t_tscalar rval;                                                            \
    rval.clear();                                                              \
    rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;                         \
    if (!v.is_numeric()) {                                                     \
        rval.m_status = perspective::t_status::STATUS_CLEAR;                   \
    }                                                                          \
    if (!v.is_valid())                                                         \
        return rval;                                                           \
    rval.set(static_cast<double>(std::FUNC(v.to_double())));                   \
    return rval;

#define UNARY_STD_TYPE_CHECK_FUNCTION_BODY(FUNC)                               \
    t_type_check_result rval;                                                  \
    rval.clear();   \
    rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;                         \
    if (v.is_numeric() && v.is_valid()) {                                    \
        rval.m_status = perspective::t_status::STATUS_VALID;                 \
    }                                                                          \
    return rval;

/**
 * @brief a function that returns none for all types besides float.
 *
 */
#define UNARY_STD_FLOAT_FUNCTION_BODY(FUNC)                                    \
    t_tscalar rval;                                                            \
    rval.clear();                                                              \
    rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;                         \
    if (!v.is_numeric()) {                                                     \
        rval.m_status = perspective::t_status::STATUS_CLEAR;                   \
    }                                                                          \
    if (!v.is_valid())                                                         \
        return rval;                                                           \
    switch (v.get_dtype()) {                                                   \
        case perspective::t_dtype::DTYPE_FLOAT64: {                            \
            rval.set(static_cast<double>(std::FUNC(v.get<double>())));         \
        } break;                                                               \
        case perspective::t_dtype::DTYPE_FLOAT32: {                            \
            rval.set(static_cast<double>(std::FUNC(v.get<float>())));          \
        } break;                                                               \
        default:                                                               \
            return rval;                                                       \
    }                                                                          \
    return rval;

#define UNARY_STD_FLOAT_TYPE_CHECK_FUNCTION_BODY(FUNC)                         \
    t_type_check_result rval;                                                  \
    rval.clear();           \
    rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;                         \
    perspective::t_dtype dtype = v.get_dtype();                                             \
    if ((dtype == perspective::t_dtype::DTYPE_FLOAT64                           \
        || dtype == perspective::t_dtype::DTYPE_FLOAT32) && v.is_valid()) {   \
        rval.m_status = perspective::t_status::STATUS_VALID;                   \
    }                                                                          \
    return rval;

            struct t_tscalar_type_tag {};
            struct t_type_check_result_type_tag {};

            template <>
            struct number_type<t_tscalar> {
                typedef t_tscalar_type_tag type;
                number_type() {}
            };

            template <>
            struct number_type<t_type_check_result> {
                typedef t_type_check_result_type_tag type;
                number_type() {}
            };

            template <>
            inline t_tscalar
            const_pi_impl(t_tscalar_type_tag) {
                t_tscalar rval;
                rval.set(constant::pi);
                return rval;
            };

            template <>
            inline t_tscalar
            const_e_impl(t_tscalar_type_tag) {
                t_tscalar rval;
                rval.set(constant::e);
                return rval;
            };

            template <>
            struct epsilon_type<t_tscalar> {
                static inline t_tscalar
                value() {
                    t_tscalar rval;
                    rval.set(0.0000000001);
                    return rval;
                }
            };

            inline bool
            is_nan_impl(const t_tscalar& v, t_tscalar_type_tag) {
                return v.is_nan();
            }

            inline bool
            is_nan_impl(
                const t_type_check_result& v, t_type_check_result_type_tag) {
                return v.is_numeric();
            }

            template <>
            inline int
            to_int32_impl(const t_tscalar& v, t_tscalar_type_tag) {
                if (!v.is_valid())
                    return std::numeric_limits<int>::quiet_NaN();
                switch (v.get_dtype()) {
                    case perspective::t_dtype::DTYPE_INT64:
                        return static_cast<int>(v.get<std::int64_t>());
                    case perspective::t_dtype::DTYPE_INT32:
                        return static_cast<int>(v.get<std::int32_t>());
                    case perspective::t_dtype::DTYPE_INT16:
                        return static_cast<int>(v.get<std::int16_t>());
                    case perspective::t_dtype::DTYPE_INT8:
                        return static_cast<int>(v.get<std::int8_t>());
                    case perspective::t_dtype::DTYPE_UINT64:
                        return static_cast<int>(v.get<std::uint64_t>());
                    case perspective::t_dtype::DTYPE_UINT32:
                        return static_cast<int>(v.get<std::uint32_t>());
                    case perspective::t_dtype::DTYPE_UINT16:
                        return static_cast<int>(v.get<std::uint16_t>());
                    case perspective::t_dtype::DTYPE_UINT8:
                        return static_cast<int>(v.get<std::uint8_t>());
                    case perspective::t_dtype::DTYPE_FLOAT64:
                        return static_cast<int>(v.get<double>());
                    case perspective::t_dtype::DTYPE_FLOAT32:
                        return static_cast<int>(v.get<float>());
                    default:
                        return std::numeric_limits<int>::quiet_NaN();
                }
            }

            template <>
            inline long long int
            to_int64_impl(const t_tscalar& v, t_tscalar_type_tag) {
                if (!v.is_valid())
                    return std::numeric_limits<long long int>::quiet_NaN();
                switch (v.get_dtype()) {
                    case perspective::t_dtype::DTYPE_INT64:
                        return static_cast<long long int>(
                            v.get<std::int64_t>());
                    case perspective::t_dtype::DTYPE_INT32:
                        return static_cast<long long int>(
                            v.get<std::int32_t>());
                    case perspective::t_dtype::DTYPE_INT16:
                        return static_cast<long long int>(
                            v.get<std::int16_t>());
                    case perspective::t_dtype::DTYPE_INT8:
                        return static_cast<long long int>(v.get<std::int8_t>());
                    case perspective::t_dtype::DTYPE_UINT64:
                        return static_cast<long long int>(
                            v.get<std::uint64_t>());
                    case perspective::t_dtype::DTYPE_UINT32:
                        return static_cast<long long int>(
                            v.get<std::uint32_t>());
                    case perspective::t_dtype::DTYPE_UINT16:
                        return static_cast<long long int>(
                            v.get<std::uint16_t>());
                    case perspective::t_dtype::DTYPE_UINT8:
                        return static_cast<long long int>(
                            v.get<std::uint8_t>());
                    case perspective::t_dtype::DTYPE_FLOAT64:
                        return static_cast<long long int>(v.get<double>());
                    case perspective::t_dtype::DTYPE_FLOAT32:
                        return static_cast<long long int>(v.get<float>());
                    default:
                        return std::numeric_limits<long long int>::quiet_NaN();
                }
            }

            template <>
            inline int
            to_int32_impl(
                const t_type_check_result& v, t_type_check_result_type_tag) {
                if (!v.is_valid())
                    return std::numeric_limits<int>::quiet_NaN();
                switch (v.get_dtype()) {
                    // case perspective::t_dtype::DTYPE_INT64:
                    //     return static_cast<int>(v.get<std::int64_t>());
                    // case perspective::t_dtype::DTYPE_INT32:
                    //     return static_cast<int>(v.get<std::int32_t>());
                    // case perspective::t_dtype::DTYPE_INT16:
                    //     return static_cast<int>(v.get<std::int16_t>());
                    // case perspective::t_dtype::DTYPE_INT8:
                    //     return static_cast<int>(v.get<std::int8_t>());
                    // case perspective::t_dtype::DTYPE_UINT64:
                    //     return static_cast<int>(v.get<std::uint64_t>());
                    // case perspective::t_dtype::DTYPE_UINT32:
                    //     return static_cast<int>(v.get<std::uint32_t>());
                    // case perspective::t_dtype::DTYPE_UINT16:
                    //     return static_cast<int>(v.get<std::uint16_t>());
                    // case perspective::t_dtype::DTYPE_UINT8:
                    //     return static_cast<int>(v.get<std::uint8_t>());
                    // case perspective::t_dtype::DTYPE_FLOAT64:
                    //     return static_cast<int>(v.get<double>());
                    // case perspective::t_dtype::DTYPE_FLOAT32:
                    //     return static_cast<int>(v.get<float>());
                    default:
                        return std::numeric_limits<int>::quiet_NaN();
                }
            }

            template <>
            inline long long int
            to_int64_impl(
                const t_type_check_result& v, t_type_check_result_type_tag) {
                if (!v.is_valid())
                    return std::numeric_limits<long long int>::quiet_NaN();
                switch (v.get_dtype()) {
                    // case perspective::t_dtype::DTYPE_INT64:
                    // case perspective::t_dtype::DTYPE_INT32:
                    // case perspective::t_dtype::DTYPE_INT16:
                    // case perspective::t_dtype::DTYPE_INT8:
                    // case perspective::t_dtype::DTYPE_UINT64:
                    // case perspective::t_dtype::DTYPE_UINT32:
                    // case perspective::t_dtype::DTYPE_UINT16:
                    // case perspective::t_dtype::DTYPE_UINT8:
                    // case perspective::t_dtype::DTYPE_FLOAT64:
                    // case perspective::t_dtype::DTYPE_FLOAT32:
                    default:
                        return std::numeric_limits<long long int>::quiet_NaN();
                }
            }

            /******************************************************************************
             *
             * Unary functions
             */
            template <>
            inline t_tscalar
            abs_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FUNCTION_BODY(abs)
            }
            template <>
            inline t_tscalar
            acos_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(acos)
            }
            template <>
            inline t_tscalar
            acosh_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(acosh)
            }
            template <>
            inline t_tscalar
            asin_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(asin)
            }
            template <>
            inline t_tscalar
            asinh_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(asinh)
            }
            template <>
            inline t_tscalar
            atan_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(atan)
            }
            template <>
            inline t_tscalar
            atanh_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(atanh)
            }
            template <>
            inline t_tscalar
            ceil_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FUNCTION_BODY(ceil)
            }
            template <>
            inline t_tscalar
            cos_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(cos)
            }
            template <>
            inline t_tscalar
            cosh_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(cosh)
            }
            template <>
            inline t_tscalar
            exp_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FUNCTION_BODY(exp)
            }
            template <>
            inline t_tscalar
            expm1_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FUNCTION_BODY(expm1)
            }
            template <>
            inline t_tscalar
            floor_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FUNCTION_BODY(floor)
            }
            template <>
            inline t_tscalar
            log_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FUNCTION_BODY(log)
            }
            template <>
            inline t_tscalar
            log10_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FUNCTION_BODY(log10)
            }
            template <>
            inline t_tscalar
            log2_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FUNCTION_BODY(log2)
            }
            template <>
            inline t_tscalar
            log1p_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FUNCTION_BODY(log1p)
            }
            template <>
            inline t_tscalar
            round_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FUNCTION_BODY(round)
            }

            template <>
            inline t_tscalar
            neg_impl(const t_tscalar v, t_tscalar_type_tag) {
                return -v;
            }
            template <>
            inline t_tscalar
            pos_impl(const t_tscalar v, t_tscalar_type_tag) {
                return +v;
            }

            template <>
            inline t_tscalar
            sgn_impl(const t_tscalar v, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_INT32;

                if (!v.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_CLEAR;
                }

                if (!v.is_valid()) {
                    return rval;
                }

                switch (v.get_dtype()) {
                    case perspective::t_dtype::DTYPE_INT64: {
                        std::int64_t val = v.get<std::int64_t>();
                        if (val == 0) {
                            rval.set(static_cast<std::int32_t>(val));
                        } else {
                            rval.set(static_cast<std::int32_t>(
                                (0 < val) - (val < 0)));
                        }
                    } break;
                    case perspective::t_dtype::DTYPE_INT32: {
                        std::int32_t val = v.get<std::int32_t>();
                        if (val == 0) {
                            rval.set(val);
                        } else {
                            rval.set((0 < val) - (val < 0));
                        }
                    } break;
                    case perspective::t_dtype::DTYPE_INT16: {
                        std::int16_t val = v.get<std::int16_t>();
                        if (val == 0) {
                            rval.set(static_cast<std::int32_t>(val));
                        } else {
                            rval.set(static_cast<std::int32_t>(
                                (0 < val) - (val < 0)));
                        }
                    } break;
                    case perspective::t_dtype::DTYPE_INT8: {
                        std::int8_t val = v.get<std::int8_t>();
                        if (val == 0) {
                            rval.set(static_cast<std::int32_t>(val));
                        } else {
                            rval.set(static_cast<std::int32_t>(
                                (0 < val) - (val < 0)));
                        }
                    } break;
                    case perspective::t_dtype::DTYPE_UINT64: {
                        std::uint64_t val = v.get<std::uint64_t>();
                        if (val == 0) {
                            rval.set(static_cast<std::int32_t>(val));
                        } else {
                            rval.set(static_cast<std::int32_t>(
                                (0 < val) - (val < 0)));
                        }
                    } break;
                    case perspective::t_dtype::DTYPE_UINT32: {
                        std::uint32_t val = v.get<std::uint32_t>();
                        if (val == 0) {
                            rval.set(static_cast<std::int32_t>(val));
                        } else {
                            rval.set(static_cast<std::int32_t>(
                                (0 < val) - (val < 0)));
                        }
                    } break;
                    case perspective::t_dtype::DTYPE_UINT16: {
                        std::uint16_t val = v.get<std::uint16_t>();
                        if (val == 0) {
                            rval.set(static_cast<std::int32_t>(val));
                        } else {
                            rval.set(static_cast<std::int32_t>(
                                (0 < val) - (val < 0)));
                        }
                    } break;
                    case perspective::t_dtype::DTYPE_UINT8: {
                        std::uint8_t val = v.get<std::uint8_t>();
                        if (val == 0) {
                            rval.set(static_cast<std::int32_t>(val));
                        } else {
                            rval.set(static_cast<std::int32_t>(
                                (0 < val) - (val < 0)));
                        }
                    } break;
                    case perspective::t_dtype::DTYPE_FLOAT64: {
                        double val = v.get<double>();
                        if (val == 0) {
                            rval.set(static_cast<std::int32_t>(val));
                        } else {
                            rval.set(static_cast<std::int32_t>(
                                (0 < val) - (val < 0)));
                        }
                    } break;
                    case perspective::t_dtype::DTYPE_FLOAT32: {
                        float val = v.get<float>();
                        if (val == 0) {
                            rval.set(static_cast<std::int32_t>(val));
                        } else {
                            rval.set(static_cast<std::int32_t>(
                                (0 < val) - (val < 0)));
                        }
                    } break;
                    default:
                        return rval;
                }

                return rval;
            }

            template <>
            inline t_tscalar
            sin_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(sin)
            }

            template <>
            inline t_tscalar
            sinc_impl(const t_tscalar v, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (!v.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_CLEAR;
                }

                if (!v.is_valid()) {
                    return rval;
                }

                double x = v.to_double();

                if (x == 0) {
                    rval.set(static_cast<double>(1.0));
                } else {
                    rval.set(std::sin(x) / x);
                }

                return rval;
            }
            template <>
            inline t_tscalar
            sinh_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(sinh)
            }
            template <>
            inline t_tscalar
            sqrt_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FUNCTION_BODY(sqrt)
            }
            template <>
            inline t_tscalar
            tan_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(tan)
            }
            template <>
            inline t_tscalar
            tanh_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(tanh)
            }

            template <>
            inline t_tscalar
            cot_impl(const t_tscalar v, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (!v.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_CLEAR;
                }

                if (!v.is_valid()) {
                    return rval;
                }

                rval.set(static_cast<double>(1.00 / std::tan(v.to_double())));

                return rval;
            }

            template <>
            inline t_tscalar
            sec_impl(const t_tscalar v, t_tscalar_type_tag) {
                return mknone();
            }
            template <>
            inline t_tscalar
            csc_impl(const t_tscalar v, t_tscalar_type_tag) {
                return mknone();
            }

            template <>
            inline t_tscalar
            r2d_impl(const t_tscalar v, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (!v.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_CLEAR;
                }

                if (!v.is_valid()) {
                    return rval;
                }

                // radians to degrees
                rval.set(v.to_double()
                    * 57.29577951308232087679815481410517033240547246656443);
                return rval;
            }

            template <>
            inline t_tscalar
            d2r_impl(const t_tscalar v, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (!v.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_CLEAR;
                }

                if (!v.is_valid()) {
                    return rval;
                }

                // degrees to radians
                rval.set(v.to_double()
                    * 0.01745329251994329576923690768488612713442871888542);
                return rval;
            }

            template <>
            inline t_tscalar
            d2g_impl(const t_tscalar v, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (!v.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_CLEAR;
                }

                if (!v.is_valid()) {
                    return rval;
                }

                // degrees to gradians
                rval.set(v.to_double() * (20.0 / 9.0));
                return rval;
            }

            template <>
            inline t_tscalar
            g2d_impl(const t_tscalar v, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (!v.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_CLEAR;
                }

                if (!v.is_valid()) {
                    return rval;
                }

                // gradians to degrees
                rval.set(v.to_double() * (9.0 / 20.0));
                return rval;
            }
            template <>
            inline t_tscalar
            notl_impl(const t_tscalar v, t_tscalar_type_tag) {
                return mknone();
            }

            template <>
            inline t_tscalar
            frac_impl(const t_tscalar v, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (!v.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_CLEAR;
                }

                if (!v.is_valid()) {
                    return rval;
                }

                double intpart;

                switch (v.get_dtype()) {
                    case perspective::t_dtype::DTYPE_INT64:
                    case perspective::t_dtype::DTYPE_INT32:
                    case perspective::t_dtype::DTYPE_INT16:
                    case perspective::t_dtype::DTYPE_INT8:
                    case perspective::t_dtype::DTYPE_UINT64:
                    case perspective::t_dtype::DTYPE_UINT32:
                    case perspective::t_dtype::DTYPE_UINT16:
                    case perspective::t_dtype::DTYPE_UINT8: {
                        rval.set(static_cast<double>(0));
                    }; break;
                    case perspective::t_dtype::DTYPE_FLOAT64:
                    case perspective::t_dtype::DTYPE_FLOAT32: {
                        rval.set(std::modf(v.to_double(), &intpart));
                    } break;
                    default:
                        return rval;
                }

                return rval;
            }

            template <>
            inline t_tscalar
            trunc_impl(const t_tscalar v, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_INT64;

                if (!v.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_CLEAR;
                }

                if (!v.is_valid()) {
                    return rval;
                }

                rval.set(static_cast<std::int64_t>(v.to_double()));

                return rval;
            }

            template <>
            inline t_tscalar
            erf_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(erf)
            }
            template <>
            inline t_tscalar
            erfc_impl(const t_tscalar v, t_tscalar_type_tag) {
                UNARY_STD_FLOAT_FUNCTION_BODY(erfc)
            }
            template <>
            inline t_tscalar
            ncdf_impl(const t_tscalar v, t_tscalar_type_tag) {
                return mknone();
            }

            // Type-check binary functions

            template <>
            inline t_type_check_result
            abs_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(abs)
            }
            template <>
            inline t_type_check_result
            acos_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_FLOAT_TYPE_CHECK_FUNCTION_BODY(acos)
            }
            template <>
            inline t_type_check_result
            acosh_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_FLOAT_TYPE_CHECK_FUNCTION_BODY(acosh)
            }
            template <>
            inline t_type_check_result
            asin_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_FLOAT_TYPE_CHECK_FUNCTION_BODY(asin)
            }
            template <>
            inline t_type_check_result
            asinh_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_FLOAT_TYPE_CHECK_FUNCTION_BODY(asinh)
            }
            template <>
            inline t_type_check_result
            atan_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_FLOAT_TYPE_CHECK_FUNCTION_BODY(atan)
            }
            template <>
            inline t_type_check_result
            atanh_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_FLOAT_TYPE_CHECK_FUNCTION_BODY(atanh)
            }
            template <>
            inline t_type_check_result
            ceil_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(ceil)
            }
            template <>
            inline t_type_check_result
            cos_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_FLOAT_TYPE_CHECK_FUNCTION_BODY(cos)
            }
            template <>
            inline t_type_check_result
            cosh_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_FLOAT_TYPE_CHECK_FUNCTION_BODY(cosh)
            }
            template <>
            inline t_type_check_result
            exp_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(exp)
            }
            template <>
            inline t_type_check_result
            expm1_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(expm1)
            }
            template <>
            inline t_type_check_result
            floor_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(floor)
            }
            template <>
            inline t_type_check_result
            log_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(log)
            }
            template <>
            inline t_type_check_result
            log10_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(log10)
            }
            template <>
            inline t_type_check_result
            log2_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(log2)
            }
            template <>
            inline t_type_check_result
            log1p_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(log1p)
            }
            template <>
            inline t_type_check_result
            round_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(round)
            }

            template <>
            inline t_type_check_result
            neg_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(neg)
            }
            template <>
            inline t_type_check_result
            pos_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(pos)
            }

            template <>
            inline t_type_check_result
            sgn_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(sgn)
            }

            template <>
            inline t_type_check_result
            sin_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_FLOAT_TYPE_CHECK_FUNCTION_BODY(sin)
            }

            template <>
            inline t_type_check_result
            sinc_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(sinc)
            }
            template <>
            inline t_type_check_result
            sinh_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_FLOAT_TYPE_CHECK_FUNCTION_BODY(sinh)
            }
            template <>
            inline t_type_check_result
            sqrt_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(sqrt)
            }
            template <>
            inline t_type_check_result
            tan_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_FLOAT_TYPE_CHECK_FUNCTION_BODY(tan)
            }
            template <>
            inline t_type_check_result
            tanh_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_FLOAT_TYPE_CHECK_FUNCTION_BODY(tanh)
            }

            template <>
            inline t_type_check_result
            cot_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(cot)
            }

            template <>
            inline t_type_check_result
            sec_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                t_type_check_result rval;
                rval.clear();
                return rval;
            }
            template <>
            inline t_type_check_result
            csc_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                t_type_check_result rval;
                rval.clear();
                return rval;
            }

            template <>
            inline t_type_check_result
            r2d_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(r2d)
            }

            template <>
            inline t_type_check_result
            d2r_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(d2r)
            }

            template <>
            inline t_type_check_result
            d2g_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(d2g)
            }

            template <>
            inline t_type_check_result
            g2d_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(g2d)
            }
            template <>
            inline t_type_check_result
            notl_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                t_type_check_result rval;
                rval.clear();
                return rval;
            }

            template <>
            inline t_type_check_result
            frac_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(frac)
            }

            template <>
            inline t_type_check_result
            trunc_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(trunc)
            }

            template <>
            inline t_type_check_result
            erf_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(erf)
            }
            template <>
            inline t_type_check_result
            erfc_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                UNARY_STD_TYPE_CHECK_FUNCTION_BODY(erfc)
            }
            template <>
            inline t_type_check_result
            ncdf_impl(
                const t_type_check_result v, t_type_check_result_type_tag) {
                t_type_check_result rval;
                rval.clear();
                return rval;
            }

            /******************************************************************************
             *
             * Binary functions
             */
            template <>
            inline t_tscalar
            min_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (!v0.is_valid() || !v1.is_valid() || !v0.is_numeric()
                    || !v1.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_INVALID;
                    return rval;
                }

                double x = v0.to_double();
                double y = v1.to_double();

                rval.set(x < y ? x : y);
                return rval;
            }

            template <>
            inline t_tscalar
            max_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (!v0.is_valid() || !v1.is_valid() || !v0.is_numeric()
                    || !v1.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_INVALID;
                    return rval;
                }

                double x = v0.to_double();
                double y = v1.to_double();

                rval.set(x > y ? x : y);
                return rval;
            }

            template <>
            inline t_tscalar
            equal_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.m_type = perspective::t_dtype::DTYPE_BOOL;

                if (!v0.is_valid() || !v1.is_valid() || v0.is_none()
                    || v1.is_none()) {
                    rval.m_status = perspective::t_status::STATUS_INVALID;
                    return rval;
                }

                rval.set(v0 == v1);
                return rval;
            }
            template <>
            inline t_tscalar
            nequal_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.m_type = perspective::t_dtype::DTYPE_BOOL;

                if (!v0.is_valid() || !v1.is_valid() || v0.is_none()
                    || v1.is_none()) {
                    rval.m_status = perspective::t_status::STATUS_INVALID;
                    return rval;
                }

                rval.set(v0 != v1);
                return rval;
            }

            template <>
            inline t_tscalar
            modulus_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                return v0 % v1;
            }

            template <>
            inline t_tscalar
            pow_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (!v1.is_numeric() || !v1.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_CLEAR;
                }

                if (!v0.is_valid() || !v1.is_valid()) {
                    return rval;
                }

                rval.set(std::pow(v0.to_double(), v1.to_double()));

                return rval;
            }

            template <>
            inline t_tscalar
            logn_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (!v1.is_numeric() || !v1.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_CLEAR;
                }

                if (!v0.is_valid() || !v1.is_valid()) {
                    return rval;
                }

                double base = v1.to_double();

                if (base < 0) {
                    return rval;
                }

                double result = std::log(v0.to_double()) / std::log(base);

                rval.set(result);
                return rval;
            }

            template <>
            inline t_tscalar
            root_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (!v1.is_numeric() || !v1.is_numeric()) {
                    rval.m_status = perspective::t_status::STATUS_CLEAR;
                }

                if (!v0.is_valid() || !v1.is_valid()) {
                    return rval;
                }

                double x = v0.to_double();
                std::int64_t y = static_cast<std::int64_t>(v1.to_double());

                if (y < 0 || (x < 0 && y % 2 == 0)) {
                    return mknone();
                }

                double result
                    = std::pow(v0.to_double(), (1.0 / v1.to_double()));

                rval.set(result);
                return rval;
            }

            template <>
            inline t_tscalar
            roundn_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                return mknone();
            }
            template <>
            inline t_tscalar
            hypot_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                return mknone();
            }
            template <>
            inline t_tscalar
            atan2_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                return mknone();
            }
            template <>
            inline t_tscalar
            shr_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                return mknone();
            }
            template <>
            inline t_tscalar
            shl_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                return mknone();
            }

            template <>
            inline t_tscalar
            and_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.set(v0.as_bool() && v1.as_bool());
                return rval;
            }

            template <>
            inline t_tscalar
            or_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.set(v0.as_bool() || v1.as_bool());
                return rval;
            }

            template <>
            inline t_tscalar
            xor_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.set(!v0.as_bool() != !v1.as_bool());
                return rval;
            }

            template <>
            inline t_tscalar
            nand_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.set(!(v0.as_bool() && v1.as_bool()));
                return rval;
            }

            template <>
            inline t_tscalar
            nor_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.set(!(v0.as_bool() || v1.as_bool()));
                return rval;
            }

            template <>
            inline t_tscalar
            xnor_impl(
                const t_tscalar v0, const t_tscalar v1, t_tscalar_type_tag) {
                t_tscalar rval;
                rval.set(v0.as_bool() == v1.as_bool());
                return rval;
            }

            template <>
            inline bool
            is_integer_impl(const t_tscalar& v, t_tscalar_type_tag) {
                switch (v.get_dtype()) {
                    case perspective::t_dtype::DTYPE_INT64:
                    case perspective::t_dtype::DTYPE_INT32:
                    case perspective::t_dtype::DTYPE_INT16:
                    case perspective::t_dtype::DTYPE_INT8:
                    case perspective::t_dtype::DTYPE_UINT64:
                    case perspective::t_dtype::DTYPE_UINT32:
                    case perspective::t_dtype::DTYPE_UINT16:
                    case perspective::t_dtype::DTYPE_UINT8:
                        return true;
                    case perspective::t_dtype::DTYPE_FLOAT64:
                    case perspective::t_dtype::DTYPE_FLOAT32:
                        return false;
                    default:
                        return false;
                }
            };

            template <>
            inline t_type_check_result
            min_impl(const t_type_check_result v0, const t_type_check_result v1,
                t_type_check_result_type_tag) {
                t_type_check_result rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (v0.is_numeric() && v0.is_valid() && v1.is_numeric()
                    && v1.is_valid()) {
                    rval.m_status = perspective::t_status::STATUS_VALID;
                }

                return rval;
            }

            template <>
            inline t_type_check_result
            max_impl(const t_type_check_result v0, const t_type_check_result v1,
                t_type_check_result_type_tag) {
                t_type_check_result rval;
                rval.clear();
                rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                if (v0.is_numeric() && v0.is_valid() && v1.is_numeric()
                    && v1.is_valid()) {
                    rval.m_status = perspective::t_status::STATUS_VALID;
                }

                return rval;
            }

            template <>
            inline t_type_check_result
            equal_impl(const t_type_check_result v0,
                const t_type_check_result v1, t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.clear();
                    rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                    if (v0.is_valid() && v1.is_valid()) {
                        rval.m_status = perspective::t_status::STATUS_VALID;
                    }

                    return rval;
                }

                template <>
                inline t_type_check_result nequal_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.clear();
                    rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                    if (v0.is_valid() && v1.is_valid()) {
                        rval.m_status = perspective::t_status::STATUS_VALID;
                    }

                    return rval;
                }

                template <>
                inline t_type_check_result modulus_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.clear();
                    rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                    if (v0.is_numeric() && v0.is_valid() && v1.is_numeric()
                        && v1.is_valid()) {
                        rval.m_status = perspective::t_status::STATUS_VALID;
                    }

                    return rval;
                }

                template <>
                inline t_type_check_result pow_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.clear();
                    rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                    if (v0.is_numeric() && v0.is_valid() && v1.is_numeric()
                        && v1.is_valid()) {
                        rval.m_status = perspective::t_status::STATUS_VALID;
                    }

                    return rval;
                }

                template <>
                inline t_type_check_result logn_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.clear();
                    rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                    if (v0.is_numeric() && v0.is_valid() && v1.is_numeric()
                        && v1.is_valid()) {
                        rval.m_status = perspective::t_status::STATUS_VALID;
                    }

                    return rval;
                }

                template <>
                inline t_type_check_result root_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.clear();
                    rval.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                    if (v0.is_numeric() && v0.is_valid() && v1.is_numeric()
                        && v1.is_valid()) {
                        rval.m_status = perspective::t_status::STATUS_VALID;
                    }

                    return rval;
                }

                template <>
                inline t_type_check_result roundn_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.clear();
                    return rval;
                }

                template <>
                inline t_type_check_result hypot_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.clear();
                    return rval;
                }

                template <>
                inline t_type_check_result atan2_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.clear();
                    return rval;
                }

                template <>
                inline t_type_check_result shr_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.clear();
                    return rval;
                }

                template <>
                inline t_type_check_result shl_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.clear();
                    return rval;
                }

                template <>
                inline t_type_check_result and_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                    rval.m_status = perspective::t_status::STATUS_VALID;
                    return rval;
                }

                template <>
                inline t_type_check_result or_impl(const t_type_check_result v0,
                    const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                    rval.m_status = perspective::t_status::STATUS_VALID;
                    return rval;
                }

                template <>
                inline t_type_check_result xor_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                    rval.m_status = perspective::t_status::STATUS_VALID;
                    return rval;
                }

                template <>
                inline t_type_check_result nand_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                    rval.m_status = perspective::t_status::STATUS_VALID;
                    return rval;
                }

                template <>
                inline t_type_check_result nor_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                    rval.m_status = perspective::t_status::STATUS_VALID;
                    return rval;
                }

                template <>
                inline t_type_check_result xnor_impl(
                    const t_type_check_result v0, const t_type_check_result v1,
                    t_type_check_result_type_tag) {
                    t_type_check_result rval;
                    rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                    rval.m_status = perspective::t_status::STATUS_VALID;
                    return rval;
                }

                template <>
                inline bool is_integer_impl(const t_type_check_result& v,
                    t_type_check_result_type_tag) {
                    switch (v.m_type) {
                        case perspective::t_dtype::DTYPE_INT64:
                        case perspective::t_dtype::DTYPE_INT32:
                        case perspective::t_dtype::DTYPE_INT16:
                        case perspective::t_dtype::DTYPE_INT8:
                        case perspective::t_dtype::DTYPE_UINT64:
                        case perspective::t_dtype::DTYPE_UINT32:
                        case perspective::t_dtype::DTYPE_UINT16:
                        case perspective::t_dtype::DTYPE_UINT8:
                            return true;
                        default:
                            return false;
                    }
                };

#undef UNARY_STD_FUNCTION_BODY
#undef UNARY_STD_FLOAT_FUNCTION_BODY
#undef UNARY_STD_TYPE_CHECK_FUNCTION_BODY

                /**
                 * @brief Get the result of applying the given operator to
                 * two scalars. Explicitly specialize the template here so
                 * we return scalars of DTYPE_BOOL instead of the default
                 * DTYPE_FLOAT64 from the function-style cast.
                 *
                 * @tparam
                 * @param operation
                 * @param arg0
                 * @param arg1
                 * @return t_tscalar
                 */
                template <>
                inline t_tscalar process_impl(const operator_type operation,
                    const t_tscalar arg0, const t_tscalar arg1) {
                    // use the scalar type tag to dispatch to the right fns
                    t_tscalar_type_tag scalar_type_tag;

                    switch (operation) {
                        case e_add:
                            return (arg0 + arg1);
                        case e_sub:
                            return (arg0 - arg1);
                        case e_mul:
                            return (arg0 * arg1);
                        case e_div:
                            return (arg0 / arg1);
                        case e_mod:
                            return modulus_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_pow:
                            return pow_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_atan2:
                            return atan2_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_min:
                            return min_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_max:
                            return max_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_logn:
                            return logn_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_lt: {
                            perspective::t_tscalar rval;
                            rval.set(arg0 < arg1);
                            return rval;
                        };
                        case e_lte: {
                            perspective::t_tscalar rval;
                            rval.set(arg0 <= arg1);
                            return rval;
                        };
                        case e_eq: {
                            perspective::t_tscalar rval;
                            rval.set(std::equal_to<t_tscalar>()(arg0, arg1));
                            return rval;
                        };
                        case e_ne: {
                            perspective::t_tscalar rval;
                            rval.set(
                                std::not_equal_to<t_tscalar>()(arg0, arg1));
                            return rval;
                        };
                        case e_gte: {
                            perspective::t_tscalar rval;
                            rval.set(arg0 >= arg1);
                            return rval;
                        };
                        case e_gt: {
                            perspective::t_tscalar rval;
                            rval.set(arg0 > arg1);
                            return rval;
                        };
                        case e_and:
                            return and_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_nand:
                            return nand_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_or:
                            return or_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_nor:
                            return nor_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_xor:
                            return xor_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_xnor:
                            return xnor_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_root:
                            return root_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_roundn:
                            return roundn_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_equal:
                            return equal_impl(arg0, arg1, scalar_type_tag);
                        case e_nequal:
                            return nequal_impl(arg0, arg1, scalar_type_tag);
                        case e_hypot:
                            return hypot_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_shr:
                            return shr_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        case e_shl:
                            return shl_impl<t_tscalar>(
                                arg0, arg1, scalar_type_tag);
                        default:
                            // return scalar of DTYPE_NONE
                            return std::numeric_limits<t_tscalar>::quiet_NaN();
                    }
                }

                template <>
                inline t_type_check_result process_impl(
                    const operator_type operation,
                    const t_type_check_result arg0,
                    const t_type_check_result arg1) {
                    t_type_check_result_type_tag type_check_result_type_tag;
                    t_type_check_result rval;
                    rval.clear();

                    switch (operation) {
                        case e_add:
                            return (arg0 + arg1);
                        case e_sub:
                            return (arg0 - arg1);
                        case e_mul:
                            return (arg0 * arg1);
                        case e_div:
                            return (arg0 / arg1);
                        case e_mod:
                            return modulus_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_pow:
                            return pow_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_atan2:
                            return atan2_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_min:
                            return min_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_max:
                            return max_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_logn:
                            return logn_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_lt:
                        case e_lte:
                        case e_eq:
                        case e_ne:
                        case e_gte:
                        case e_gt: {
                            rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                            rval.m_status = perspective::t_status::STATUS_VALID;
                            return rval;
                        };
                        case e_and:
                            return and_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_nand:
                            return nand_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_or:
                            return or_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_nor:
                            return nor_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_xor:
                            return xor_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_xnor:
                            return xnor_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_root:
                            return root_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_roundn:
                            return roundn_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_equal:
                            return equal_impl(
                                arg0, arg1, type_check_result_type_tag);
                        case e_nequal:
                            return nequal_impl(
                                arg0, arg1, type_check_result_type_tag);
                        case e_hypot:
                            return hypot_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_shr:
                            return shr_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        case e_shl:
                            return shl_impl<t_type_check_result>(
                                arg0, arg1, type_check_result_type_tag);
                        default: {
                            return rval;
                        }
                    }
                }

                } // end namespace details
                } // end namespace numeric

                /**
                 * Override the comparison operators to return a `t_tscalar` of
                 * DTYPE_BOOL instead of the default DTYPE_FLOAT64 from the
                 * function-style cast.
                 */
                template <>
                struct lt_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(Type t1, Type t2) {
                        t_tscalar rval;
                        rval.set(t1 < t2);
                        return rval;
                    }

                    static inline t_tscalar
                    process(const std::string& t1, const std::string& t2) {
                        t_tscalar rval;
                        rval.set(t1 < t2);
                        return rval;
                    }

                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_lt;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_lt;
                    }
                };

                template <>
                struct lte_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(Type t1, Type t2) {
                        t_tscalar rval;
                        rval.set(t1 <= t2);
                        return rval;
                    }
                    static inline t_tscalar
                    process(const std::string& t1, const std::string& t2) {
                        t_tscalar rval;
                        rval.set(t1 <= t2);
                        return rval;
                    }
                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_lte;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_lte;
                    }
                };

                template <>
                struct gt_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(Type t1, Type t2) {
                        t_tscalar rval;
                        rval.set(t1 > t2);
                        return rval;
                    }

                    static inline t_tscalar
                    process(const std::string& t1, const std::string& t2) {
                        t_tscalar rval;
                        rval.set(t1 > t2);
                        return rval;
                    }

                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_gt;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_gt;
                    }
                };

                template <>
                struct gte_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(Type t1, Type t2) {
                        t_tscalar rval;
                        rval.set(t1 >= t2);
                        return rval;
                    }

                    static inline t_tscalar
                    process(const std::string& t1, const std::string& t2) {
                        t_tscalar rval;
                        rval.set(t1 >= t2);
                        return rval;
                    }

                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_gte;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_gte;
                    }
                };

                template <>
                struct eq_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;
                    static inline t_tscalar
                    process(Type t1, Type t2) {
                        t_tscalar rval;
                        rval.set(std::equal_to<t_tscalar>()(t1, t2));
                        return rval;
                    }
                    static inline t_tscalar
                    process(const std::string& t1, const std::string& t2) {
                        t_tscalar rval;
                        rval.set(t1 == t2);
                        return rval;
                    }
                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_eq;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_eq;
                    }
                };

                template <>
                struct equal_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(Type t1, Type t2) {
                        t_tscalar rval;
                        rval.set(std::equal_to<t_tscalar>()(t1, t2));
                        return rval;
                    }
                    static inline t_tscalar
                    process(const std::string& t1, const std::string& t2) {
                        t_tscalar rval;
                        rval.set(t1 == t2);
                        return rval;
                    }
                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_eq;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_equal;
                    }
                };

                template <>
                struct ne_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(Type t1, Type t2) {
                        t_tscalar rval;
                        rval.set(std::not_equal_to<t_tscalar>()(t1, t2));
                        return rval;
                    }
                    static inline t_tscalar
                    process(const std::string& t1, const std::string& t2) {
                        t_tscalar rval;
                        rval.set(t1 != t2);
                        return rval;
                    }
                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_ne;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_ne;
                    }
                };

                template <>
                struct and_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(Type t1, Type t2) {
                        t_tscalar rval;
                        rval.set(is_true(t1) && is_true(t2));
                        return rval;
                    }
                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_and;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_and;
                    }
                };

                template <>
                struct nand_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(Type t1, Type t2) {
                        t_tscalar rval;
                        rval.set(!(is_true(t1) && is_true(t2)));
                        return rval;
                    }
                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_nand;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_nand;
                    }
                };

                template <>
                struct or_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(Type t1, Type t2) {
                        t_tscalar rval;
                        rval.set(is_true(t1) || is_true(t2));
                        return rval;
                    }
                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_or;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_or;
                    }
                };

                template <>
                struct nor_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(Type t1, Type t2) {
                        t_tscalar rval;
                        rval.set(!(is_true(t1) || is_true(t2)));
                        return rval;
                    }
                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_nor;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_nor;
                    }
                };

                template <>
                struct xor_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(Type t1, Type t2) {
                        return numeric::xor_opr<t_tscalar>(t1, t2);
                    }

                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_nor;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_xor;
                    }
                };

                template <>
                struct xnor_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(Type t1, Type t2) {
                        return numeric::xnor_opr<t_tscalar>(t1, t2);
                    }
                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_nor;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_xnor;
                    }
                };

                /**
                 * We don't use ExprTk std::string literals (strings are passed
                 * into intern() automatically), so disable the string literal
                 * comparison operations. The only time we use string literals
                 * explicitly are in the parameter of the `bucket` operation,
                 * but that doesn't use these comparison operators.
                 */
                template <>
                struct in_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(const t_tscalar&, const t_tscalar&) {
                        return std::numeric_limits<t_tscalar>::quiet_NaN();
                    }
                    static inline t_tscalar
                    process(const std::string& t1, const std::string& t2) {
                        return std::numeric_limits<t_tscalar>::quiet_NaN();
                    }
                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_in;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_in;
                    }
                };

                template <>
                struct like_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(const t_tscalar&, const t_tscalar&) {
                        return std::numeric_limits<t_tscalar>::quiet_NaN();
                    }
                    static inline t_tscalar
                    process(const std::string& t1, const std::string& t2) {
                        return std::numeric_limits<t_tscalar>::quiet_NaN();
                    }
                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_like;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_like;
                    }
                };

                template <>
                struct ilike_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(const t_tscalar&, const t_tscalar&) {
                        return std::numeric_limits<t_tscalar>::quiet_NaN();
                    }
                    static inline t_tscalar
                    process(const std::string& t1, const std::string& t2) {
                        return std::numeric_limits<t_tscalar>::quiet_NaN();
                    }
                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_ilike;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_ilike;
                    }
                };

                template <>
                struct inrange_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    static inline t_tscalar
                    process(const t_tscalar& t0, const t_tscalar& t1,
                        const t_tscalar& t2) {
                        t_tscalar rval;
                        rval.set((t0 <= t1) && (t1 <= t2));
                        return rval;
                    }
                    static inline t_tscalar
                    process(const std::string& t0, const std::string& t1,
                        const std::string& t2) {
                        t_tscalar rval;
                        rval.set((t0 <= t1) && (t1 <= t2));
                        return rval;
                    }
                    static inline typename expression_node<t_tscalar>::node_type
                    type() {
                        return expression_node<t_tscalar>::e_inranges;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_inrange;
                    }
                };

                /**
                 * @brief mand(a, b, c, ...) returns true if all arguments
                 * evaluate to true, else false. All parameters should be of
                 * DTYPE_BOOL, or the function will return a scalar of
                 * DTYPE_NONE indicating an invalid operation.
                 */
                template <>
                struct vararg_mand_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    template <typename Type, typename Allocator,
                        template <typename, typename> class Sequence>
                    static inline t_tscalar
                    process(const Sequence<Type, Allocator>& arg_list) {
                        t_tscalar rval = mktscalar(false);

                        // Originally, there was specific implementations for up
                        // to 5 args that did not use a for loop, but since we
                        // do type-checking centralize all the logic here
                        // instead.
                        for (std::size_t i = 0; i < arg_list.size(); ++i) {
                            t_tscalar val = value(arg_list[i]);

                            // If scalar is invalid or not a bool, return bool
                            // but with STATUS_CLEAR to poison the type-checker.
                            if (!val.is_valid()
                                || val.get_dtype()
                                    != perspective::t_dtype::DTYPE_BOOL) {
                                rval.m_status
                                    = perspective::t_status::STATUS_CLEAR;
                                return rval;
                            }

                            // if value is equal to False, return False
                            if (std::equal_to<t_tscalar>()(rval, val)) {
                                return rval;
                            }
                        }

                        // True if all values are true
                        rval.set(true);
                        return rval;
                    }
                };

                // /**
                //  * @brief mor(a, b, c, ...) returns True if any parameter
                //  evalutes to
                //  * True, and False otherwise. All parameters should be
                //  scalars of
                //  * `DTYPE_BOOL`.
                //  *
                //  * @tparam T
                //  */
                template <>
                struct vararg_mor_op<t_tscalar> : public opr_base<t_tscalar> {
                    typedef typename opr_base<t_tscalar>::Type Type;

                    template <typename Type, typename Allocator,
                        template <typename, typename> class Sequence>
                    static inline t_tscalar
                    process(const Sequence<Type, Allocator>& arg_list) {
                        t_tscalar rval = mktscalar(false);

                        // Originally, there was specific implementations for up
                        // to 5 args that did not use a for loop, but since we
                        // do type-checking centralize all the logic here
                        // instead.
                        for (std::size_t i = 0; i < arg_list.size(); ++i) {
                            t_tscalar val = value(arg_list[i]);

                            // If scalar is invalid or not a bool, return bool
                            // but with STATUS_CLEAR to poison the type-checker.
                            if (!val.is_valid()
                                || val.get_dtype()
                                    != perspective::t_dtype::DTYPE_BOOL) {
                                rval.m_status
                                    = perspective::t_status::STATUS_CLEAR;
                                return rval;
                            }

                            // if any value is True, return True
                            if (std::not_equal_to<t_tscalar>()(rval, val)) {
                                rval.set(true);
                                return rval;
                            }
                        }

                        // False if all values are false
                        return rval;
                    }
                };

                // Type-check operators
                template <>
                struct lt_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(Type t1, Type t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }

                    static inline t_type_check_result
                    process(const std::string& t1, const std::string& t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }

                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_lt;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_lt;
                    }
                };

                template <>
                struct lte_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(Type t1, Type t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }
                    static inline t_type_check_result
                    process(const std::string& t1, const std::string& t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }
                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_lte;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_lte;
                    }
                };

                template <>
                struct gt_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(Type t1, Type t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }

                    static inline t_type_check_result
                    process(const std::string& t1, const std::string& t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }

                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_gt;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_gt;
                    }
                };

                template <>
                struct gte_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(Type t1, Type t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }

                    static inline t_type_check_result
                    process(const std::string& t1, const std::string& t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }

                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_gte;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_gte;
                    }
                };

                template <>
                struct eq_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;
                    static inline t_type_check_result
                    process(Type t1, Type t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }

                    static inline t_type_check_result
                    process(const std::string& t1, const std::string& t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }

                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_eq;
                    }

                    static inline details::operator_type
                    operation() {
                        return details::e_eq;
                    }
                };

                template <>
                struct equal_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(Type t1, Type t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }

                    static inline t_type_check_result
                    process(const std::string& t1, const std::string& t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }

                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_eq;
                    }

                    static inline details::operator_type
                    operation() {
                        return details::e_equal;
                    }
                };

                template <>
                struct ne_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(Type t1, Type t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }

                    static inline t_type_check_result
                    process(const std::string& t1, const std::string& t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }

                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_ne;
                    }

                    static inline details::operator_type
                    operation() {
                        return details::e_ne;
                    }
                };

                template <>
                struct and_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(Type t1, Type t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }
                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_and;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_and;
                    }
                };

                template <>
                struct nand_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(Type t1, Type t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }
                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_nand;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_nand;
                    }
                };

                template <>
                struct or_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(Type t1, Type t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }
                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_or;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_or;
                    }
                };

                template <>
                struct nor_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(Type t1, Type t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }
                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_nor;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_nor;
                    }
                };

                template <>
                struct xor_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(Type t1, Type t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }

                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_nor;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_xor;
                    }
                };

                template <>
                struct xnor_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(Type t1, Type t2) {
                        t_type_check_result rval;
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }
                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_nor;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_xnor;
                    }
                };

                /**
                 * We don't use ExprTk std::string literals (strings are passed
                 * into intern() automatically), so disable the string literal
                 * comparison operations. The only time we use string literals
                 * explicitly are in the parameter of the `bucket` operation,
                 * but that doesn't use these comparison operators.
                 */
                template <>
                struct in_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(const t_type_check_result&,
                        const t_type_check_result&) {
                        t_type_check_result rval;
                        rval.clear();
                        return rval;
                    }
                    static inline t_type_check_result
                    process(const std::string& t1, const std::string& t2) {
                        t_type_check_result rval;
                        rval.clear();
                        return rval;
                    }
                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_in;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_in;
                    }
                };

                template <>
                struct like_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(const t_type_check_result&,
                        const t_type_check_result&) {
                        t_type_check_result rval;
                        rval.clear();
                        return rval;
                    }
                    static inline t_type_check_result
                    process(const std::string& t1, const std::string& t2) {
                        t_type_check_result rval;
                        rval.clear();
                        return rval;
                    }
                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_like;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_like;
                    }
                };

                template <>
                struct ilike_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(const t_type_check_result&,
                        const t_type_check_result&) {
                        t_type_check_result rval;
                        rval.clear();
                        return rval;
                    }
                    static inline t_type_check_result
                    process(const std::string& t1, const std::string& t2) {
                        t_type_check_result rval;
                        rval.clear();
                        return rval;
                    }
                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_ilike;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_ilike;
                    }
                };

                template <>
                struct inrange_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    static inline t_type_check_result
                    process(const t_type_check_result& t0,
                        const t_type_check_result& t1,
                        const t_type_check_result& t2) {
                        t_type_check_result rval;
                        rval.clear();

                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;

                        if (t0.is_numeric() && t0.is_valid() && t1.is_numeric()
                            && t1.is_valid() && t2.is_numeric()
                            && t2.is_valid()) {
                            rval.m_status = perspective::t_status::STATUS_VALID;
                        }

                        return rval;
                    }

                    static inline t_type_check_result
                    process(const std::string& t0, const std::string& t1,
                        const std::string& t2) {
                        t_type_check_result rval;
                        rval.clear();
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;
                        return rval;
                    }
                    static inline
                        typename expression_node<t_type_check_result>::node_type
                        type() {
                        return expression_node<t_type_check_result>::e_inranges;
                    }
                    static inline details::operator_type
                    operation() {
                        return details::e_inrange;
                    }
                };

                template <>
                struct vararg_mand_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    template <typename Type, typename Allocator,
                        template <typename, typename> class Sequence>
                    static inline t_type_check_result
                    process(const Sequence<Type, Allocator>& arg_list) {
                        t_type_check_result rval;
                        rval.clear();
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;

                        for (std::size_t i = 0; i < arg_list.size(); ++i) {
                            const t_type_check_result& val = value(arg_list[i]);

                            if (!val.is_valid()
                                || val.get_dtype()
                                    != perspective::t_dtype::DTYPE_BOOL) {
                                return rval;
                            }
                        }

                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }
                };

                template <>
                struct vararg_mor_op<t_type_check_result>
                    : public opr_base<t_type_check_result> {
                    typedef typename opr_base<t_type_check_result>::Type Type;

                    template <typename Type, typename Allocator,
                        template <typename, typename> class Sequence>
                    static inline t_type_check_result
                    process(const Sequence<Type, Allocator>& arg_list) {
                        t_type_check_result rval;
                        rval.clear();
                        rval.m_type = perspective::t_dtype::DTYPE_BOOL;

                        for (std::size_t i = 0; i < arg_list.size(); ++i) {
                            const t_type_check_result& val = value(arg_list[i]);

                            if (!val.is_valid()
                                || val.get_dtype()
                                    != perspective::t_dtype::DTYPE_BOOL) {
                                return rval;
                            }
                        }

                        rval.m_status = perspective::t_status::STATUS_VALID;
                        return rval;
                    }
                };

                /**
                 * @brief Evaluates the truthiness of an expression node that
                 * returns a `t_tscalar`. The `t_tscalar` returned must be of
                 * type bool.
                 *
                 * @tparam
                 * @param node
                 * @return true
                 * @return false
                 */
                template <>
                inline bool is_true(const expression_node<t_tscalar>* node) {
                    return std::not_equal_to<t_tscalar>()(
                        mktscalar(false), node->value());
                }

                template <>
                inline bool is_true(
                    const std::pair<expression_node<t_tscalar>*, bool>& node) {
                    return std::not_equal_to<t_tscalar>()(
                        mktscalar(false), node.first->value());
                }

                template <>
                inline bool is_false(const expression_node<t_tscalar>* node) {
                    return std::equal_to<t_tscalar>()(
                        mktscalar(false), node->value());
                }

                template <>
                inline bool is_false(
                    const std::pair<expression_node<t_tscalar>*, bool>& node) {
                    return std::equal_to<t_tscalar>()(
                        mktscalar(false), node.first->value());
                }

                inline bool is_true(
                    const expression_node<t_type_check_result>* node) {
                    return true;
                }

                template <>
                inline bool is_true(
                    const std::pair<expression_node<t_type_check_result>*,
                        bool>& node) {
                    return true;
                }

                template <>
                inline bool is_false(
                    const expression_node<t_type_check_result>* node) {
                    return true;
                }

                template <>
                inline bool is_false(
                    const std::pair<expression_node<t_type_check_result>*,
                        bool>& node) {
                    return true;
                }

                /**
                 * @brief Evaluates the truthiness of a single scalar value.
                 *
                 * @param v
                 * @return true
                 * @return false
                 */
                inline bool is_true(const t_tscalar& v) { return v.as_bool(); }

                inline bool is_false(const t_tscalar& v) {
                    return !is_true(v);
                };

                inline bool is_true(const t_type_check_result& v) {
                    return true;
                }

                inline bool is_false(const t_type_check_result& v) {
                    return true;
                };

                /******************************************************************************
                 *
                 * String -> t_tscalar
                 */

                /**
                 * @brief Parse an infinity value and set `t` to infinity as a
                 * DTYPE_FLOAT64 scalar.
                 *
                 * @tparam Iterator
                 * @param itr
                 * @param end
                 * @param t
                 * @param negative
                 * @return true
                 * @return false
                 */
                template <typename Iterator>
                static inline bool parse_inf(Iterator & itr, const Iterator end,
                    t_tscalar& t, bool negative) {
                    static const char_t inf_uc[] = "INFINITY";
                    static const char_t inf_lc[] = "infinity";
                    static const std::size_t inf_length = 8;

                    const std::size_t length
                        = static_cast<std::size_t>(std::distance(itr, end));

                    if ((3 != length) && (inf_length != length))
                        return false;

                    char_cptr inf_itr = ('i' == (*itr)) ? inf_lc : inf_uc;

                    while (end != itr) {
                        if (*inf_itr == static_cast<char>(*itr)) {
                            ++itr;
                            ++inf_itr;
                            continue;
                        } else {
                            return false;
                        }
                    }

                    negative ? t.set(-std::numeric_limits<double>::infinity())
                             : t.set(std::numeric_limits<double>::infinity());
                    t.m_type = perspective::t_dtype::DTYPE_FLOAT64;

                    return true;
                }

                template <typename Iterator>
                static inline bool parse_inf(Iterator & itr, const Iterator end,
                    t_type_check_result& t, bool negative) {
                    // FIXME
                    t.m_type = perspective::t_dtype::DTYPE_FLOAT64;
                    t.m_status = perspective::t_status::STATUS_VALID;

                    return true;
                }

                template <typename T>
                inline bool valid_exponent(
                    const int exponent, numeric::details::t_tscalar_type_tag) {
                    using namespace details::numeric;
                    return (numeric_info<T>::min_exp <= exponent)
                        && (exponent <= numeric_info<T>::max_exp);
                }

                template <typename T>
                inline bool valid_exponent(const int exponent,
                    numeric::details::t_type_check_result_type_tag) {
                    using namespace details::numeric;
                    return true; // FIXME
                }

                /**
                 * @brief Parse a string to a real number, setting `t` to the
                 * parsed value and giving it DTYPE_FLOAT64. Returns true if the
                 * parse succeeded, and false otherwise.
                 *
                 * @tparam Iterator
                 * @param itr_external
                 * @param end
                 * @param t
                 * @return true
                 * @return false
                 */
                template <typename Iterator>
                inline bool string_to_real(Iterator & itr_external,
                    const Iterator end, t_tscalar& t,
                    numeric::details::t_tscalar_type_tag) {
                    bool parsed = string_to_real(itr_external, end,
                        t.m_data.m_float64, numeric::details::real_type_tag());

                    if (parsed) {
                        t.m_type = perspective::DTYPE_FLOAT64;
                        t.m_status = perspective::STATUS_VALID;
                    }

                    return parsed;
                }

                template <typename Iterator>
                inline bool string_to_real(Iterator & itr_external,
                    const Iterator end, t_type_check_result& t,
                    numeric::details::t_type_check_result_type_tag) {
                    double dummy;

                    bool parsed = string_to_real(itr_external, end, dummy,
                        numeric::details::real_type_tag());

                    if (parsed) {
                        t.m_type = perspective::DTYPE_FLOAT64;
                        t.m_status = perspective::STATUS_VALID;
                    } else {
                        t.clear();
                    }

                    return parsed;
                }

            } // end namespace details
        }     // namespace details
