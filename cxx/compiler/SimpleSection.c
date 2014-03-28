/*
 * =====================================================================================
 *
 *       Filename:  SimpleSection.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/02/2013 04:14:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Yonghao Zhou (leo), zhouyonghao@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <pthread.h>
#include <stdio.h>

int printf(const char* format, ...);
int global_init_val = 84;
int globale_uninit_val;

extern void func1(int i);
extern char __executable_start[];
__attribute__((section("TEST1"))) static int test1 = 10;
__attribute__((weak)) int weak2 = 1;
__attribute__((weak)) void func1(int i)
{
    printf("weak %d\n", i);
}

int pthread_create(pthread_t*, const pthread_attr_t*, void* (*)(void *), void*) __attribute__((weak));
int main(void)
{
    static int static_var = 8;
    static int static_var2;

    if (!pthread_create)
        printf("no thread\n");
    else
        printf("thread\n");

    int a = 1;
    int b;

    func1(static_var + static_var2 + a + b);
    printf("%p\n", __executable_start);
    printf("%d\n", weak2);
    return a;
}
