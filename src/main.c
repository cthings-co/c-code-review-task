/*
 * Copyright (c) 2021 cthings.co
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "median_filter.h"

#define MAX_BUF_SIZE	32

/**
 * @brief Simple Median Filter
 *
 * @param argv[1] - file with the positive integer data separated with ','. E.g: 1,2,45,121,1024,0,45
 * @param argv[2] - output file with applied median filter.
 *
 * @return 0 if successful
 */
int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Wrong number of arguments provided! Please use ./median_filter <path_to_data_file> <path_to_output_file>\n\r");
		exit(-1);
	}
	
	FILE *fp_in = NULL;
	FILE *fp_out = NULL;
	int in_values[3], out_value;
	char *buffered_value = malloc(MAX_BUF_SIZE);
	char *end_ptr;
	char buffer_out[MAX_BUF_SIZE] = { 0 };
	int num_index = 0, ch_index = 0;
	char ch;

	fp_in = fopen(argv[1], "r");
	fp_out = fopen(argv[2], "w");

	for (ch = getc(fp_in); ch != EOF; ch = getc(fp_in)) {
		if (ch != ',') {
			buffered_value[ch_index++] = ch;
			continue;
		} else {
			in_values[num_index % 3] = strtol(buffered_value, &end_ptr, 10);
			ch_index = 0;
			memset(buffered_value, 0, sizeof(char) * MAX_BUF_SIZE);
		}
		if (num_index >= 2) {
			median_filter(in_values, &out_value);
		}
		fprintf(fp_out, "%d,", out_value);
		num_index++;
	}
	median_filter(in_values, &out_value);
	fprintf(fp_out, "%d", out_value);

	fclose(fp_in);

	return 0;
}
