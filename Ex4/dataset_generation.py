#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  4 21:32:01 2022

@author: janaki
"""
import random
n = 4096
fp = open("matrices_4096.txt","w")
fp.write(str(n)+"\n")  
for i in range(1,n*n):
    x = random.random()
    fp.write(str(int(x*1000))+" ")  
x = random.random()
fp.write(str(int(x*1000))+"\n")
for i in range(1,n*n):
    x = random.random()
    fp.write(str(int(x*1000))+" ")  
x = random.random()
fp.write(str(int(x*1000))+"\n") 
fp.close()
