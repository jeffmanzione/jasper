// thread.h
//
// Created on: Nov 9, 2018
//     Author: Jeff Manzione

#ifndef UTIL_SYNC_THREAD_H_
#define UTIL_SYNC_THREAD_H_

#include "util/platform.h"
#include "util/sync/constants.h"

typedef unsigned int ThreadId;

#ifdef OS_WINDOWS
#include <stdint.h>
typedef uintptr_t ThreadHandle;
typedef unsigned __stdcall (*VoidFn)(void *);
#else
#include <pthread.h>
typedef pthread_t ThreadHandle;
typedef void *(*VoidFn)(void *);
#endif

ThreadHandle thread_create(VoidFn fn, void *arg);
WaitStatus thread_join(ThreadHandle thread, unsigned long duration);
void thread_close(ThreadHandle thread);

#endif /* UTIL_SYNC_THREAD_H_ */