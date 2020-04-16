// temporary C API for the lazy dir view
#pragma once
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

bool LDV_ChangeDir(void *LDV, bool sortByName, const char *path);
uint32_t LDV_TotalFilesCount(void *LDV);
uint32_t LDV_VisibleFilesCount(void *LDV);
bool LDV_MoveUp(void *LDV);
bool LDV_MoveDown(void *LDV);
const char *LDV_FileAt(void *LDV, int index, bool *isFile);
void *LDV_Create(void);

#ifdef __cplusplus
}
#endif