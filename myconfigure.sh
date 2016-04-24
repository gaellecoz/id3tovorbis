#!/bin/bash

export LDFLAGS="$LDFLAGS -ggdb3 -L/Users/gaellecoz/git/id3tovorbis/libs/taglib-1.11beta2/taglib"
export CPPFLAGS="$CPPFLAGS -I/Users/gaellecoz/git/id3tovorbis/libs/taglib-1.11beta2 -I/Users/gaellecoz/git/id3tovorbis/libs/taglib-1.11beta2/taglib -I/Users/gaellecoz/git/id3tovorbis/libs/taglib-1.11beta2/taglib/toolkit"
export CXXFLAGS="$CXXFLAGS -ggdb3 -O0"
./configure --enable-debug
