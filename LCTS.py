#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 12 21:33:19 2018

@author: Habibur Rahman
@email: habib[dot]rahman[at]uits[dot]edu[dot]bd 
"""

#import nltk
#import numpy
#from nltk import word_tokenize
import math
import csv
from trie import Trie

#def sliding_window(toFind, List):                   #Method for Pattern Matching
#    for i in range(len(List)):
#        if List[i:i+len(toFind)]==toFind:
#            return True
#        
#    return False

def tokenizer(SourceCode):                          #Customized Tokenize
#    print SourceCode
#    print len(SourceCode)
    processedCode = ""
#    print processedCode
    for i in range(0, len(SourceCode)):
        if SourceCode[i].isalpha()==True and SourceCode[i-1].isalpha()==False:
            processedCode+=" "+SourceCode[i]
        elif SourceCode[i].isalpha()==False and SourceCode[i].isdigit()==False:
            processedCode+=" "+SourceCode[i]
        elif SourceCode[i].isdigit()==True and SourceCode[i-1].isdigit()==False:
            processedCode+=" "+SourceCode[i]
        else:
            processedCode+=SourceCode[i]

    processedCode = processedCode.split(' ')
    final = []
    for x in processedCode:
        if x==' ' or x =='':
            x
        else:
            final.append(x)
#    print final
    return final


def tokenize(NumberofFiles):
    tokens = []                                         #A list where all the source codes' token will store as 2D list
    for i in range(NumberofFiles):
        with open("Datasets/"+str(i)+".cpp") as fin:    #Source Code files are named with <fileNumber>.cpp
            tokens.append(tokenizer(fin.read()))        #Customize Tokenizer
#            tokens.append(word_tokenize(fin.read()))    #NLTK is used for tokenization (Not actual Tokenizer for Source code)
    return tokens

def trieBuild(tokens):
    tree = Trie()
    for i in range(len(tokens)):
        for j in range(len(tokens[i])):
            prefixToken = tokens[i][j:len(tokens[i])]
            tree.insertWord(prefixToken, i+1)
#    Flag, Counts, TotalVisitor = tree.searchWordPrefix(['for', '(', 'int'])
#    print(str(Flag) + " "+ str(Counts) + " "+ str(TotalVisitor))
    return tree
    

def LongestCommonTokenSequence(tokens, tree):
    numberOfRow = len(tokens)                           #Same as Number of Files
    CurrentRow = tokens[0]                              #Comparision taking the first source code
    LenOfCurrentRow = len(CurrentRow)                   #Length of Tokens for a single source code
    
    maxLength = 0                                       #Previously stored maximum length of tokens
    Result = []
    
    for it in range(LenOfCurrentRow):
        for nit in range(it+1, LenOfCurrentRow+1):
            SubToken = CurrentRow[it:nit]               #Taking a sequence to from the tokens of a source code 
            #print SubToken
            
            Flag, Counts, TotalVisitor = tree.searchWordPrefix(SubToken)
#            print(str(Flag)+" "+str(Counts)+" "+str(TotalVisitor)+" "+str(SubToken))
            if Flag==True and TotalVisitor == numberOfRow:
                if len(SubToken) > maxLength:           #maximum Length Update
                    maxLength = len(SubToken)
                    Score = math.log(len(SubToken), 2)*math.log(Counts, 2) #As per instractions
                    Result = []
                    Result.append([Score, maxLength, Counts, SubToken])
                
                elif maxLength == len(SubToken):
                    Score = math.log(len(SubToken), 2)*math.log(Counts, 2) #As per instractions
                    Result.append([Score, maxLength, Counts, SubToken])#CSV Writter
#            Counts = 0                                  #Counting the occurance in several source code
#            for j in range(1, numberOfRow):
#                occurs = sliding_window(SubToken, tokens[j])    # Pattern Matching with Sliding Window Technique (Can Use Knuth Morris Pratt Algo)
#                if occurs == True:                      #Present or not 
#                    Counts = Counts + 1
#                else:
#                    break
    return Result

def WriteReport(Result, NumberofInputFiles):
    with open("Outputs/"+str(NumberofInputFiles)+".csv", "wb") as fileName:
        writer = csv.writer(fileName)
        writer.writerows(Result)
        
if __name__ == "__main__":
    NumberofInputFiles = 2                #Number of Files
    tokens = tokenize(NumberofInputFiles)
    tree = trieBuild(tokens)
    Result = LongestCommonTokenSequence(tokens, tree)
    WriteReport(Result, NumberofInputFiles)
