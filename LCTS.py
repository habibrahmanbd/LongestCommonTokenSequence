#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 12 21:33:19 2018

@author: Habibur Rahman
@email: habib[dot]rahman[at]uits[dot]edu[dot]bd 
"""

#import nltk
#import numpy
from nltk import word_tokenize
import math
import csv

def sliding_window(toFind, List):                   #Method for Pattern Matching
    for i in range(len(List)):
        if List[i:i+len(toFind)]==toFind:
            return True
        
    return False                                     

def tokenize(NumberofFiles):
    tokens = []                                         #A list where all the source codes' token will store as 2D list
    for i in range(NumberofFiles):
        with open("Datasets/"+str(i)+".cpp") as fin:    #Source Code files are named with <fileNumber>.cpp
            tokens.append(word_tokenize(fin.read()))    #NLTK is used for tokenization (Not actual Tokenizer for Source code), 
    return tokens                                       #Append the tokens for a single source code
        

def LongestCommonTokenSequence(tokens):
    numberOfRow = len(tokens)                           #Same as Number of Files
    CurrentRow = tokens[0]                              #Comparision taking the first source code
    LenOfCurrentRow = len(CurrentRow)                   #Length of Tokens for a single source code
    
    maxLength = 0                                       #Previously stored maximum length of tokens
    Result = []
    
    for it in range(LenOfCurrentRow):
        for nit in range(it+1, LenOfCurrentRow+1):
            SubToken = CurrentRow[it:nit]               #Taking a sequence to from the tokens of a source code 
            #print SubToken
            
            Counts = 0                                  #Counting the occurance in several source code
            for j in range(1, numberOfRow):
                occurs = sliding_window(SubToken, tokens[j])    # Pattern Matching with Sliding Window Technique (Can Use Knuth Morris Pratt Algo)
                if occurs == True:                      #Present or not 
                    Counts = Counts + 1
                else:
                    break
            if Counts + 1 == numberOfRow:               #Present or not in all the Source Codes' token sequence
                if len(SubToken) > maxLength:           #maximum Length Update
                    maxLength = len(SubToken)
                    Score = math.log(len(SubToken), 2)*math.log(Counts, 2) #As per instractions
                    Result = []
                    Result.append([Score, maxLength, Counts, SubToken])
                    
                elif maxLength == len(SubToken):
                    Score = math.log(len(SubToken), 2)*math.log(Counts, 2) #As per instractions
                    Result.append([Score, maxLength, Counts, SubToken])#CSV Writter
    return Result

def WriteReport(Result, NumberofInputFiles):
    with open("Outputs/"+str(NumberofInputFiles)+".csv", "wb") as fileName:
        writer = csv.writer(fileName)
        writer.writerows(Result)
        
if __name__ == "__main__":
    NumberofInputFiles = 3
    tokens = tokenize(NumberofInputFiles)
    Result = LongestCommonTokenSequence(tokens)
    WriteReport(Result, NumberofInputFiles)
    
    