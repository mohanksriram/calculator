load("@rules_cc//cc:defs.bzl", "cc_library")
load("@rules_cc//cc:defs.bzl", "cc_test")


cc_library(
    name = "evaluator",
    srcs = ["evaluator.cc"],
    hdrs = ["evaluator.h"],
    deps = [
        "//parser:parser",
    ],
    visibility = ["//calculator:__pkg__"],
)

cc_test(
    name = "evaluator-test",
    srcs = ["evaluator_test.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
        "//parser:parser",
        "//evaluator:evaluator",
    ],
)