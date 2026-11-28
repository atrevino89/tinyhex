tiny-hexdump is a small project I made in a couple hours to learn C and how data can be shown.

### Commands:  

Compile:
```bash
$ make
```

Create a test binary:
```bash
$ printf 'ABCD\x00\x01\x0a\xffEFGH' > test.bin
```  

Run it:
```bash
$ ./tinyhex test.bin
```
