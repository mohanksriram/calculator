load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "evaluator",
    srcs = ["evaluator.cc"],
    hdrs = ["evaluator.h"],
    deps = [
        "//parser:parser",
    ],
    visibility = ["//calculator:__pkg__"],
)