#include <lz4.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 4096
#define MAX_COMPRESSED_SIZE (PAGE_SIZE + 16) // LZ4 overhead

void dump_page(FILE *dump_file, char *page_data) {
    char compressed[MAX_COMPRESSED_SIZE]; 
    int compressed_size;

    compressed_size = LZ4_compress_default(page_data, compressed, PAGE_SIZE, MAX_COMPRESSED_SIZE);
    
    if (compressed_size <= 0) {
        fprintf(stderr, "LZ4 compression failed for page\n");
        exit(EXIT_FAILURE);
    }

  
    if (fwrite(&compressed_size, sizeof(int), 1, dump_file) != 1) {
        perror("Error writing compressed size to dump file");
        exit(EXIT_FAILURE);
    }
    if (fwrite(compressed, compressed_size, 1, dump_file) != 1) {
        perror("Error writing compressed page data to dump file");
        exit(EXIT_FAILURE);
    }
}
