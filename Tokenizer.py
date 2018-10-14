#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 14 22:29:24 2018

@author: Habibur Rahman
@email: habib[dot]rahman[at]uits[dot]edu[dot]bd
"""
class tokenizer:
    def tokenizer(SourceCode):
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
            if x==' ' or x =='' or x == '\n' or x== '\0' or x == '\r':
                x
            else:
                final.append(x)
        return final