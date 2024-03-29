load("@rules_cc//cc:defs.bzl", "cc_library")

package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "constants",
    hdrs = ["constants.h"],
    deps = [],
)

cc_library(
    name = "critical_section",
    srcs = ["critical_section.c"],
    hdrs = ["critical_section.h"],
    linkopts = select({
        "@bazel_tools//src/conditions:windows": [],
        "//conditions:default": ["-lpthread"],
    }),
    deps = [
        ":constants",
        ":mutex",
        "//util:platform",
        "@memory_wrapper//alloc",
    ],
)

cc_library(
    name = "mutex",
    srcs = ["mutex.c"],
    hdrs = ["mutex.h"],
    linkopts = select({
        "@bazel_tools//src/conditions:windows": [],
        "//conditions:default": ["-lpthread"],
    }),
    deps = [
        ":constants",
        "//util:platform",
        "@memory_wrapper//alloc",
    ],
)

cc_library(
    name = "semaphore",
    srcs = ["semaphore.c"],
    hdrs = ["semaphore.h"],
    linkopts = select({
        "@bazel_tools//src/conditions:windows": [],
        "//conditions:default": ["-lpthread"],
    }),
    deps = [
        ":constants",
        "//util:platform",
        "@memory_wrapper//alloc",
    ],
)

cc_library(
    name = "thread",
    srcs = ["thread.c"],
    hdrs = ["thread.h"],
    linkopts = select({
        "@bazel_tools//src/conditions:windows": [],
        "//conditions:default": ["-lpthread"],
    }),
    deps = [
        ":constants",
        "//util:platform",
        "@memory_wrapper//alloc",
    ],
)

cc_library(
    name = "threadpool",
    srcs = ["threadpool.c"],
    hdrs = ["threadpool.h"],
    deps = [
        ":critical_section",
        ":thread",
        "@c_data_structures//struct:q",
        "@memory_wrapper//alloc",
    ],
)
