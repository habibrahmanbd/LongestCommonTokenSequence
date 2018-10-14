#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sat Oct 13 23:04:48 2018

@author: Habibur Rahman
@email: habib[dot]rahman[at]uits[dot]edu[dot]bd
"""

class Trie:
    
    def __init__(self):
      self.root = self.getNode()

    def getNode(self):
        return {"isEndOfWord": False, "children": {}, "VisitorCounter" : 0, "Visitors": set()}

    def insertWord(self, word, visitorNumber):
        current = self.root
        for ch in word:
            if current["children"].has_key(ch):
                node = current["children"][ch]
            else:
                node = self.getNode()
                current["children"][ch] = node

            current["VisitorCounter"] = current["VisitorCounter"] + 1
            current["Visitors"].add(visitorNumber)
            current = node
        current["isEndOfWord"] = True
        current["VisitorCounter"] = current["VisitorCounter"] + 1
        current["Visitors"].add(visitorNumber)

    def searchWordPrefix(self, word):
        current = self.root
        Data = 0
        TotalVisitors = 0
        for ch in word:
            if not current["children"].has_key(ch):
                return (False,0, 0)
            node = current["children"][ch]
            current = node
        Data = current["VisitorCounter"]
        TotalVisitors = len(current["Visitors"])
        return (True, Data, TotalVisitors)
