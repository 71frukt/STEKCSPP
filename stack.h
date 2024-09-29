#ifndef STACK_H
#define STACK_H

#define DEBUG
typedef int StackElem_t;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack_debug_macroses.h"

enum ResizeValue
{
    INCREASE,
    DECREASE
};

enum StkError
{
    STK_OK,
    STK_PTR_DATA_ERR,
    STK_DATA_ERR,
    STK_SIZE_ERR,
    STK_CAPACITY_ERR
};

enum StkAssertRes
{
    STK_ASSERT_OK,
    STK_ASSERT_ERR
};

struct Stack_t
{
    ON_DEBUG(const int line_born_in);
    ON_DEBUG(const char *file_born_in);
    ON_DEBUG(const char *func_born_in);
    ON_DEBUG(FILE *logs_file);
    
    StackElem_t *data;
    int size;
    int capacity;
};

const StackElem_t START_STACK_SIZE = 1;

StkAssertRes StackInit      (Stack_t *stk);
StkAssertRes StackDestruct  (Stack_t *stk);
StkAssertRes StackPush      (Stack_t *stk, StackElem_t value);
StkAssertRes StackPop       (Stack_t *stk, StackElem_t *stk_elem);
StkAssertRes StackResize    (Stack_t *stk, ResizeValue resize_val);
void StackDump      (Stack_t *stk, const char *func_name, const int line);

StackElem_t *StackDataRecalloc(Stack_t *stk_ptr, size_t new_data_size);

StkError StackOK (Stack_t *stk);
const char *StackStrErr(StkError err);
StkAssertRes StackAssert(Stack_t *stk);

#endif