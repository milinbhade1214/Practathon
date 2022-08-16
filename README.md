# Practathon

## Problem Statement:

Given 10M datapoints in form of vectors, each vector is of dimension as 100. Return 10 closest vectors to the given query vector in less than 1 sec latency – Query Time.  (Parameter: Euclidean Distance).

## Language Used : C++ 11
GCC version : g++ (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0

OS Used: Microsoft Windows 11 Home Single Language, Version	10.0.22000 Build 22000


### Execution Instructions (Brute Force): 
1. To generate data use dataGenerator.cpp script. This will create random data based on the gaussian distribution with mean as 0 and variance as 100.
2. Run bruteForce.cpp using cmd : g++ bruteForce.cpp
3. Output file will contain the information of median time required for randomly generated queries


### Execution Instructions (Implementation using Priority Queue): 
1. To generate data use dataGenerator.cpp script. This will create random data based on the gaussian distribution with mean as 0 and variance as 100.
2. Run PriorityQueueImplementation.cpp using cmd : g++ PriorityQueueImplementation.cpp
3. Output file will contain the information of median time required for randomly generated queries




