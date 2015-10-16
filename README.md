# OpenHMD-Java

Java bindings for OpenHMD

## Compiling

Compiling asumes you have OpenHMD installed

Linux:

* javac OpenHMD.java
* gcc -D __int64="long long" -shared -fPIC -I/usr/lib/jvm/java-7-openjdk-amd64/include/ -I/usr/local/include/openhmd/ -g -o libOpenHMD.so OpenHMD-Java.c -lopenhmd
