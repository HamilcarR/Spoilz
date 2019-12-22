#!/bin/bash


var=$1
touch sources/$var.cpp
touch includes/$var.h
header="#ifndef ${var^^}_H\n#define ${var^^}_H\n\n\nclass ${var}{\n\n\n};\n\n#endif"
include="#include "'"'"../includes/$var.h"'"'
echo -e $include > sources/$var.cpp 
echo -e $header  > includes/$var.h

