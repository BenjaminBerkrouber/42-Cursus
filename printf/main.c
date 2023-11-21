#include <stdio.h>
#include <stdarg.h>
#include "includes/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void compare_results(int ft_count, int printf_count) {
    if (ft_count == printf_count)
        printf("\nOK\n");
    else
        printf("\nFAILED | s_ft : %d s_pf %d \n", ft_count, printf_count);
}


void test_char()
{
    char test_chars[] = {'A', '0', '%', '\t', 127};
    int ft_count, printf_count;
    size_t i, num_tests;

    num_tests = sizeof(test_chars) / sizeof(test_chars[0]);
    for (i = 0; i < num_tests; i++)
    {
        ft_count = ft_printf("output pf: [%c]", test_chars[i]);
        printf(" | ");
        printf_count = printf("output ft: [%c]", test_chars[i]);
        compare_results(ft_count, printf_count);
    }
}

void test_string()
{
    char    *test_string[] = {"Bonjour", NULL, "", "\t\a\b", "simple "};
    int ft_count, printf_count;
    size_t i, num_tests;

    num_tests = sizeof(test_string) / sizeof(test_string[0]);
    for (i = 0; i < num_tests; i++)
    {
        ft_count = ft_printf("output pf: [%s]", test_string[i]);
        printf(" | ");
        printf_count = printf("output ft: [%s]", test_string[i]);
        compare_results(ft_count, printf_count);
    }
}

void test_pointer() {
    void *ptr = &ptr;
    void *null_ptr = NULL;
    int ft_count, printf_count;

    printf("Testing %%p with non-null pointer: ");
    ft_count = ft_printf("output pf: [%p]", ptr);
    printf(" | ");
    printf_count = printf("output ft: [%p]", ptr);
    compare_results(ft_count, printf_count);
    ft_count = ft_printf("output pf: [%p]", null_ptr);
    printf(" | ");
    printf_count = printf("output ft: [%p]", null_ptr);
    compare_results(ft_count, printf_count);
}


void test_decimal_integer() {
    int nums[] = {0, -1, 2147483647, -2147483648};
    size_t num_tests = sizeof(nums) / sizeof(nums[0]);
    int ft_count, printf_count;

    for (size_t i = 0; i < num_tests; i++) {
        ft_count = ft_printf("output pf: [%d] [%i]", nums[i], nums[i]);
        printf(" | ");
        printf_count = printf("output ft: [%d] [%i]", nums[i], nums[i]);
        compare_results(ft_count, printf_count);
    }
}

void test_unsigned() {
    unsigned int nums[] = {0, 4294967295U, 12345, -5};
    size_t num_tests = sizeof(nums) / sizeof(nums[0]);
    int ft_count, printf_count;

    for (size_t i = 0; i < num_tests; i++) {
        ft_count = ft_printf("output pf: [%u]", nums[i]);
        printf(" | ");
        printf_count = printf("output ft: [%u]", nums[i]);
        compare_results(ft_count, printf_count);
    }
}

void test_hex() {
    unsigned int nums[] = {0, 4294967295U, 0xABCDEF, -5};
    size_t num_tests = sizeof(nums) / sizeof(nums[0]);
    int ft_count, printf_count;

    for (size_t i = 0; i < num_tests; i++) {
        ft_count = ft_printf("output pf: [%x] [%X]", nums[i], nums[i]);
        printf(" | ");
        printf_count = printf("output ft: [%x] [%X]", nums[i], nums[i]);
        compare_results(ft_count, printf_count);
    }
}

void test_percent() {
    int ft_count, printf_count;

    ft_count = ft_printf("output pf: [%%]");
    printf(" | ");
    printf_count = printf("output ft: [%%]");
    compare_results(ft_count, printf_count);
}



int main()
{
    printf("Testing For %%c\n");
    test_char();
    printf("\nTesting For %%s\n");
    test_string();
    printf("\nTesting For %%p\n");
    test_pointer();
    printf("\nTesting For %%d and %%i\n");
    test_decimal_integer();
    printf("\nTesting For %%u\n");
    test_unsigned();
    printf("\nTesting For %%x and %%X\n");
    test_hex();
    printf("\nTesting For %%%%\n");
    test_percent();
    return 0;
}
