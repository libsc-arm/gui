#!/bin/bash

cd libflush/build
ninja 
./init >> log.txt
./evict_time >> log.txt
./prime_probe >> log.txt
cd ..
bash run_daemon.sh &
sleep 2
bash run_attacker.sh 
