
# Longest Common Token Sequence

## Features:
* Tokenize the Source Code
* Finding the Longest Common Token Sequence
* Score of the Longest Common Token Sequence

## Platforms:
* Linux
* Windows
* Mac OS X

## Requirements:
* Python 2.7.X


## Modules

- LCTS.py
- trie.py

_**trie.py**_ is the module for **Trie** data structure [[1](#references)]. The trie (Prefix Tree) is a tree of nodes which supports Find and Insert operations. Find returns the value for a key, and Insert inserts a key and a value into the trie. Both Insert and Find run in _O(n)_ time, where n is the length of the key.

__**LCTS.py**__ is the module for Load the source codes into our system, tokenize the source codes, finding the longest common token sequence and write the result in a CSV file.

## How to Use / How it Works:

**_NumberOfFiles_**  of _LCTS.py_ is the input source code files. 

**_loadAndTokenize_** is the method for loading the source code files and prepare them for tokenizing.

**_tokenizer_** is the method which is used for tokenizing a source code.

**_trieBuild_** is the method for building a prefix tree for all the suffix of the source codes. For example:
Suffix for the list of tokens _['for', '(', 'int']_ are like below:

```python

['for', '(', 'int']

['(', 'int']

['int']
```

Finding the famous _longest common substring_ problem uses this technique. All the substrings are prefix of all the suffixes. So, inserting all the suffixes to the prefix tree is the easiest way to find the longest common substring. Finding the longest common token sequence / substring is the same problem where is node of the tree is a _token_.

**_LongestCommonTokenSequence_** is the method for solving the problem of longest common token sequence and calculating the result.

**_WriteReport_** is the method for wrting the result and score in a CSV file, where columns are **_Score_**, **_Token Sequence Length_**, **_Number of Times the token sequence occurs in the files_**, **_Token Squence_**.

_Score = log2(Counts) * log2(LenghtOfTokenSequence)_



## Complexity Analysis:

Let, complexity for a token is equal to complexity of a character in a string or constant.

**N =** Number of Source Code Files

**K =**  Number of Tokens in Source Code

So, Token Generation Complexity **= O(N * K)**

Trie Building Complexity = **O (N * K^2)**

Longest Common Token Sequence Finding Complexity = **O (N * K^2)**

Finally, Total Complexity  = Token Generation Complexity + Trie Building Complexity + Longest Common Token Sequence Finding Complexity  = **O (N * K^2 )**


## Dataset:
Contain _100_ Light Online Judge[[2](#references)] Problem Solutions that are in [[3](#references)], where customize template of my codes are deleted. Codes are in the Dataset subfolder.

## Results:
**_WriteReport_**  method writes the results in Output subfolder.

## Limitations:

* C/C++/C# Tokenizer only

## References:

- [1] https://en.wikipedia.org/wiki/Trie

- [2] https://lightoj.com

- [3] https://github.com/habibrahmanbd/Light-Online-Judge

## Acknowledgement:
I would like to thank <a href = "https://sarahnadi.org/" > Sarah Nadi</a>, Assistant Professor in the Department of Computing Science at the University of Alberta for assigning me this coding task.
