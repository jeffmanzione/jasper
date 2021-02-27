// module_manager.h
//
// Created on: Jul 10, 2020
//     Author: Jeff Manzione

#ifndef VM_MODULE_MANAGER_H_
#define VM_MODULE_MANAGER_H_

#include "entity/module/module.h"
#include "heap/heap.h"
#include "program/tape.h"
#include "struct/keyed_list.h"
#include "struct/set.h"
#include "util/file/file_info.h"

typedef struct {
  Set _files_processed;
  Heap *_heap;
  KeyedList _modules;  // ModuleInfo
} ModuleManager;

void modulemanager_init(ModuleManager *mm, Heap *heap);
void modulemanager_finalize(ModuleManager *mm);
Module *modulemanager_read(ModuleManager *mm, const char fn[]);
Module *modulemanager_lookup(ModuleManager *mm, const char fn[]);

const FileInfo *modulemanager_get_fileinfo(const ModuleManager *mm,
                                           const Module *m);

Module *mm_read_helper(ModuleManager *mm, const char fn[]);

void add_reflection_to_module(ModuleManager *mm, Module *module);
void add_reflection_to_function(Heap *heap, Object *parent, Function *func);
void modulemanager_update_module(ModuleManager *mm, Module *m,
                                 Map *new_classes);

#endif /* VM_MODULE_MANAGER_H_ */