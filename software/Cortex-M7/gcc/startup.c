/*
** Copyright (C) ARM Limited, 2006-2017. All rights reserved.
*/

#include <stdint.h>
#include <stdlib.h>

extern void _start();

/* This file contains the default exception handlers and vector table.
All exceptions are handled in Handler mode.  Processor state is automatically
pushed onto the stack when an exception occurs, and popped from the stack at
the end of the handler */

volatile unsigned int __systick_count = 0;
uint32_t SystemCoreClock = 25000000;

/* Exception Handlers */
/* Marking as __attribute__((interrupt)) avoids them being accidentally called from elsewhere */

__attribute__((interrupt)) void NMIException(void)
{   while(1); }

__attribute__((interrupt)) void HardFaultException(void)
{   while(1); }

__attribute__((interrupt)) void SVCHandler(void)
{   while(1); }

__attribute__((interrupt)) void PendSVC(void)
{   while(1); }

/* For SysTick, use handler in timer.c */
__attribute__((interrupt)) void SysTickHandler(void)
{  while(1); }

__attribute__((interrupt)) void InterruptHandler(void)
{   while(1); }

__attribute__((interrupt)) void ResetHandler(void)
{    _start(); exit(0); }


/* typedef for the function pointers in the vector table */
typedef void(* __attribute__ ((interrupt)) const ExecFuncPtr)(void);

extern unsigned int stack_top;

/* Vector table
*/

ExecFuncPtr vector_table[] __attribute__((section("vectors"))) = {
     /* Configure Initial Stack Pointer using linker-generated symbol */
    (ExecFuncPtr)&stack_top,
    ResetHandler,
    NMIException,
    HardFaultException,
    0, 0, 0,                /* Reserved */
    0, 0, 0, 0,             /* Reserved */
    SVCHandler,
    0,                      /* Reserved */
    0,                      /* Reserved */
    PendSVC,
    SysTickHandler,

    /* Add up to 32 interrupt handlers, starting here... */
    InterruptHandler,
    InterruptHandler,      /* Some dummy interrupt handlers */
    InterruptHandler
    /*
    :
    */
};

