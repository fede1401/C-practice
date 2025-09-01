#!/bin/bash
set -e

echo "Compilo il programma..."
g++ main.cpp Imagee.cpp Color.cpp -o ruun.exe

echo "Eseguo ruun.exe..."
ls -l ruun.exe   # verifica se esiste davvero
./ruun.exe