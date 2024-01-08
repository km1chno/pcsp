# pcsp

## Usage 

This project uses vcpkg package manager.

```
./vcpkg/bootstrap-vcpkg.sh
vcpkg/vcpkg install 
chmod +x build.sh
./build.sh
./main
```

## Dependencies outside vcpkg 

**numcalc**

numcalc in version v1.0.0 is used for numerical differentiation. 
This is a header only lib, follow the instructions from its official github to install it on your machine.

https://github.com/xiaohongchen1991/numcalc
