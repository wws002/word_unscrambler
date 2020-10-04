# word_unscrambler

This program uses C++ to unscramble jumbled input text. It does so by generating every possible permutation of the jumbled text and then cross referencing each permutation with a dictionary stored in a text file. If multiple matches are found, they are all displayed in the output. These matches are found using a recursive binary search algorithm.  
to run:
g++ -o unscrambler unscramble.cpp;
./unscrambler
