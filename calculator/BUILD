load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "calculator",
    srcs = ["calculator.cc"],
    deps = [
        "//parser:parser",
        "//evaluator:evaluator",
    ],
)