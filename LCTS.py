#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 12 21:33:19 2018

@author: habib
"""

import nltk
import numpy
from nltk import word_tokenize
import math

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


tokens = []

for i in range(1, 3):
    with open(str(i)+".cpp") as fin:
        tokens.append(word_tokenize(fin.read()))
        

numberOfRow = len(tokens)
CurrentRow = tokens[0]
LenOfCurrentRow = len(CurrentRow)

maxLength = 0
Result = []
for it in range(LenOfCurrentRow):
    for nit in range(it+1, LenOfCurrentRow+1):
        SubToken = CurrentRow[it:nit]
        
        Counts = 0
        for j in range(1, numberOfRow):
            if sliding_window(SubToken, tokens[j])==True:
                Counts = Counts + 1
            else:
                break
        if Counts + 1 == numberOfRow:
            if len(SubToken) > maxLength:
                maxLength = len(SubToken)
                Score = math.log10(len(SubToken))*math.log10(Counts) #Need to Update as per instractions
                Result = []
                Result.append(['Seq: '+str(SubToken), 'Count:'+str(Counts), 'Score: '+str(Score)])
            elif maxLength == len(SubToken):
                Score = math.log10(len(SubToken))*math.log10(Counts) #Need to Update as per instractions
                Result.append(['Seq: '+str(SubToken), 'Count:'+str(Counts), 'Score: '+str(Score)])

print Result
                
           
            
        
        
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
