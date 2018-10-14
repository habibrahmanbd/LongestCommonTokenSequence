#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 14 22:29:24 2018

@author: Habibur Rahman
@email: habib[dot]rahman[at]uits[dot]edu[dot]bd
"""
class tokenizer:
#    def __init__(self):
#        self = None
    
    def tokenizer(SourceCode):
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
    
#with open("Datasets/0.cpp") as fin:
#    tokens = fin.read()
##    print tokens
#    tokenizer(tokens)