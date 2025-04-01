## Testing and Benchmarking Procedures

After implementing the changes, follow these steps for testing and benchmarking:

### Run CRIU with Compression:
```bash
criu dump -t <PID> --compression
```
Verify the Dump File Size:
```linux
ls -lh checkpoint.img
```
Restore from the Compressed Dump:
``` bash
criu restore --compression
```
