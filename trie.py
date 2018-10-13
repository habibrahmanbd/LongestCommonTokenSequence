#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sat Oct 13 23:04:48 2018

@author: Habibur Rahman
@email: habib[dot]rahman[at]uits[dot]edu[dot]bd
"""

#import pickle
#import json
# Trie class
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

#    def searchWord(self, word):
#        current = self.root
#        for ch in word:
#            if not current["children"].has_key(ch):
#                return False
#            node = current["children"][ch]
#            current = node
#        return current["isEndOfWord"]

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
    # return True if children contain keys and values
        return (True, Data, TotalVisitors)

#  def deleteWord(self, word):
#    self._delete(self.root, word, 0)
#
#  def _delete(self, current, word, index):
#    if(index == len(word)):
#      if not current["isEndOfWord"]:
#        return False
#      current["isEndOfWord"] = False
#      return len(current["children"].keys()) == 0
#
#    ch = word[index]
#    if not current["children"].has_key(ch):
#      return False
#    node = current["children"][ch]
#
#    should_delete_current_node = self._delete(node, word, index + 1)
#
#    if should_delete_current_node:
#      current["children"].pop(ch)
#      return len(current["children"].keys()) == 0
#
#    return False
#
#  def save_to_pickle(self, file_name):
#    f = open(file_name + ".pkl", "wb")
#    pickle.dump(self.root, f)
#    f.close()
#
#  def load_from_pickle(self, file_name):
#    f = open(file_name + ".pkl", "rb")
#    self.root = pickle.load(f)
#    f.close()
#
#  def save_to_json(self, file_name):
#    json_data = json.dumps(self.root)
#    f = open(file_name + ".json", "w")
#    f.write(json_data)
#    f.close()
#
#  def load_from_json(self, file_name):
#    json_file = open(file_name + ".json", "r")
#    self.root = json.load(json_file)
#    json_file.close()
#

#if __name__=="main":
#    model = Trie()

#model = Trie()
#model.insertWord(['for', '(', 'int', 'i', '=', '0', ';'], 1)
#model.insertWord(['for', '(', 'int', 'v', '=', '0', ';'], 2)
#model.insertWord(['for', '(', 'int', 'j', '=', '0', ';'], 3)
#model.insertWord(['=', '0', ';'], 1)
#model.insertWord(['=', '0', ';'], 2)
#model.insertWord(['=', '0', ';'], 3)
#Flag, Counts, TotalVisitor = model.searchWordPrefix(['for'])
#print(str(Flag) + " "+ str(Counts) + " "+ str(TotalVisitor))
##print(Flag + " "+Counts + " "+ TotalVisitor)
