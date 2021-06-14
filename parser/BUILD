load("@rules_cc//cc:defs.bzl", "cc_library")
load("@rules_cc//cc:defs.bzl", "cc_test")


cc_library(
    name = "parser",
    srcs = ["parser.cc"],
    hdrs = ["parser.h"],
    visibility = ["//calculator:__pkg__",
                "//evaluator:__pkg__"],
)

cc_test(
    name = "parser-test",
    srcs = ["parser_test.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
        "//parser:parser",
    ],
)