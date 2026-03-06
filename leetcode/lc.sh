#!/bin/sh

fn=`basename -s .cpp $1`
clang++ -std=c++23 -stdlib=libc++ -fmodules $1 -o $fn 2>&1

./$fn
rm $fn
