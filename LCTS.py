#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 12 21:33:19 2018

@author: habib
"""

import nltk
import numpy
from nltk import word_tokenize


def sliding_window(toFind, List):
    for i in range(len(List)):
        if List[i:i+len(toFind)]==toFind:
            return True
    return False


#tok = ["Hello", "World", "I", "Love", "My", "Country", "Very", "Much"]
#toFind = ["I", "Love", "My"]
#
#print(sliding_window(toFind, tok))
#

#
#tokens = []
#
#for i in range(2):
#    with open(str(i)+".cpp") as fin:
#        tokens.append(word_tokenize(fin.read()))
#        
#
#numberOfRow = len(tokens)
#CurrentRow = tokens[0]
#LenOfCurrentRow = len(CurrentRow)
#
#
#for it in range(LenOfCurrentRow):
#    for nit in range(it+1, LenOfCurrentRow+1):
#        SubToken = CurrentRow[it:nit]
        
        #print SubToken
#    int n = arr.length; 
#  
#        // Take first word from array as reference 
#        String s = arr[0]; 
#        int len = s.length(); 
#  
#        String res = ""; 
#  
#        for (int i = 0; i < len; i++) { 
#            for (int j = i + 1; j <= len; j++) { 
#  
#                // generating all possible substrings 
#                // of our reference string arr[0] i.e s 
#                String stem = s.substring(i, j); 
#                int k = 1; 
#                for (k = 1; k < n; k++)  
#  
#                    // Check if the generated stem is 
#                    // common to to all words 
#                    if (!arr[k].contains(stem)) 
#                        break; 
#                  
#                // If current substring is present in 
#                // all strings and its length is greater   
#                // than current result 
#                if (k == n && res.length() < stem.length()) 
#                    res = stem; 
#            } 
#    
#    

#print len(tokens)

#with open('01.txt', 'w') as f:
#    for item in tokens:
#        f.write("%s " % item)
