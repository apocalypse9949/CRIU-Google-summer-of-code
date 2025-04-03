void restore_page(FILE *dump_file, char *output_page) {
    char compressed[MAX_COMPRESSED_SIZE];
    int compressed_size;

   
    if (fread(&compressed_size, sizeof(int), 1, dump_file) != 1) {
        perror("Error reading compressed size from dump file");
        exit(EXIT_FAILURE);
    }
    
    if (fread(compressed, compressed_size, 1, dump_file) != 1) {
        perror("Error reading compressed data from dump file");
        exit(EXIT_FAILURE);
    }

    
    int decompressed_size = LZ4_decompress_safe(compressed, output_page, compressed_size, PAGE_SIZE);
    
    if (decompressed_size < 0) {
        fprintf(stderr, "LZ4 decompression failed for page\n");
        exit(EXIT_FAILURE);
    }

    if (decompressed_size != PAGE_SIZE) {
        fprintf(stderr, "Decompressed size does not match page size\n");
        exit(EXIT_FAILURE);
    }
}
