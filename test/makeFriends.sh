#!/bin/bash

N=1000000

src=$(( $RANDOM % $N ))
trg=$(( $RANDOM % $N ))

if [ $src -eq $trg ] 
then
    trg=$(( $trg + 1 ))
    trg=$(( $trg % $N ))    
fi

echo $src $trg 

for (( i=1; i<$N; i++ ))
do
    echo $i $(( $RANDOM % $i ))
done
