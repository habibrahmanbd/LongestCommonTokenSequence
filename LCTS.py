#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 12 21:33:19 2018

@author: Habibur Rahman
@email: habib[dot]rahman[at]uits[dot]edu[dot]bd 
"""
import math
import csv
from trie import Trie

def tokenizer(SourceCode):                          #Customized Tokenizer
    processedCode = ""
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
        cross = [' ', '', '\n', '\r', '\0', '\t']
        if x in cross:
            x
        else:
            final.append(x)
    return final


def loadAndTokenize(NumberofFiles):
    tokens = []                                         #A list where all the source codes' token will store as 2D list
    for i in range(NumberofFiles):
        with open("Datasets/"+str(i)+".cpp") as fin:    #Source Code files are named with <fileNumber>.cpp
            tokens.append(tokenizer(fin.read()))        #Customize Tokenizer
#            print tokens
    return tokens

def trieBuild(tokens):                                  #Builds the Tree and Returns
    tree = Trie()                                       #Object of Trie Class
    for i in range(len(tokens)):
        for j in range(len(tokens[i])):
            prefixToken = tokens[i][j:len(tokens[i])]
            tree.insertWord(prefixToken, i+1)
    return tree

def LongestCommonTokenSequence(tokens, tree):
    numberOfRow = len(tokens)                           #Same as Number of Files
    CurrentRow = tokens[0]                              #Comparision taking the first source code
    LenOfCurrentRow = len(CurrentRow)                   #Length of Tokens for a single source code
    
    maxLength = 0                                       #Previously stored maximum length of tokens
    Result = []                                         #Final Result to Write in CSV

    for it in range(LenOfCurrentRow):
        for nit in range(it+1, LenOfCurrentRow+1):
            SubToken = CurrentRow[it:nit]               #Taking a sequence to from the tokens of a source code
            Flag, Counts, TotalVisitor = tree.searchWordPrefix(SubToken)
            if Flag==True and TotalVisitor == numberOfRow:
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
    NumberofInputFiles = 2                             #Number of Files
    tokens = loadAndTokenize(NumberofInputFiles)               #Tokenizes the Source Code Files
    tree = trieBuild(tokens)                            #Building Tree
    Result = LongestCommonTokenSequence(tokens, tree)   #Finds the Result
    WriteReport(Result, NumberofInputFiles)             #Print Output ot CSV File
