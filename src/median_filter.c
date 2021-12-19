/*
 * Copyright (c) 2021 cthings.co
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "median_filter.h"

/* Compare function for quick sort */
int compare_func(const void *elem1, const void *elem2)
{
	int f = *((int*)elem1);
	int s = *((int*)elem2);

	if (f > s) return  1;
	if (f < s) return -1;
	return 0;
}

/**
 * @brief Median Filter calculation
 *
 * @param in_values - an non-negative integer signal frame of size 3
 * @param out_value - median value for processed signal
 */
void median_filter(int *in_values, int *out_value)
{
	int temp_values[3];

	memcpy(temp_values, in_values, sizeof(int) * 3);
	printf("Input: [%d][%d][%d]\n\r", temp_values[0], temp_values[1], temp_values[2]);

	qsort(temp_values, 3, sizeof(int), compare_func);

	printf("Sorted: [%d][%d][%d]\n\r", temp_values[0], temp_values[1], temp_values[2]);

	*out_value = temp_values[1];

	printf("Median: [%d]\n\r", *out_value);
	printf("---------------------------------------\n\r");
}
