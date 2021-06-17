#!/bin/sh
cat /etc/passwd | grep -v '^#' | sed -n '1~2!p' | cut -d: -f1 | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | tr "\n" ", " | sed 's/,$/./g' 
echo ""