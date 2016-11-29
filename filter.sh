#!/bin/sh

cat input.txt | awk '$1 ~ "first_name" {print $2} 
                     $1 ~ "last_name" {print $2} 
                     $1 ~ "id" {print $2}' | sed 's/["]//g' | sed 's/[,]//g' | head -n -1
