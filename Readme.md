## Testing and Benchmarking Procedures

After implementing the changes, follow these steps for testing and benchmarking:

### Run CRIU with Compression:
```bash
criu dump --compression
```
Verify the Dump File Size:
```linux
ls -lh checkpoint.img
```
Restore from the Compressed Dump:
``` bash
criu restore --compression
```
ehnacements 
🔹 Support multiple compression algorithms (e.g., ZSTD, Gzip).
🔹 Optimize for incremental dumps.
🔹 Improve parallelization for faster compression.
