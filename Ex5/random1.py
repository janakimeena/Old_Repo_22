#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  4 21:32:01 2022

@author: janaki
"""
from random import randint
n = 125000
fp = open("random.txt","w")
fp.write(str(n)+" ")  
for i in range(1,n):
    x = randint(-n,n)
    fp.write(str(x)+" ")  
x = randint(-n,n)
fp.write(str(x)+" ")  
fp.close()
