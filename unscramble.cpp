//project 3
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

//Binary search of the dictionary for a specific word (query)
bool check(string* dictionary, int left, int right, string query)
{
	int middle;

	while(left <= right)
	{
		middle = (left + right) / 2;

		if (dictionary[middle] == query)
			return true;

		else if (dictionary[middle] > query)
			return check(dictionary, left, middle - 1, query);

		else
			return check(dictionary, middle + 1, right, query);
	}

	return false;
}

//Checks if the permutations vector already contains a certain word
//This handles the case in which words like "apple" and "apple" are
//considered separate cases by the permute function, but really these
//are the same word - the two p's are just switched.
bool contains(vector<string> permutations, string query)
{
	for (int i = 0; i < permutations.size(); i++)
	{
		if (permutations[i] == query)
			return true;
	}
	return false;
}

//Generates all unique permutations of a given string
//and drops them into a vector
//NOTE: For this function to work correctly, the initial
//function call should be permute(permutations, word, 0);
void permute(vector<string>& permutations, string word, int k)
{
    if(k == word.length() && !contains(permutations, word))
        permutations.push_back(word);
    else
        for(int j = k; j < word.length(); j++)
        {
            swap(word[j], word[k]);
            permute(permutations, word, k+1);
            swap(word[j], word[k]);
        }
}

int main()
{
    string* dictionary;
    int dictionarySize;
    vector<string> permutations;

	//read the dictionary
	ifstream din; din.open("dictionary.txt");
	din>>dictionarySize;
	dictionary = new string[dictionarySize];
	for (int i = 0; i < dictionarySize; i++)
		din>>dictionary[i];
	din.close();

	//testing permute function
	cout<<"Enter a word to unscramble: "; string word; cin>>word;
	permute(permutations, word, 0);
	cout<<"Analyzing...\n";
	for (int i = 0; i < permutations.size(); i++)
		cout<<permutations[i]<<" ("<< i + 1 <<")"<<endl;
	cout<<permutations.size()<<" permutations"<<endl<<endl;

	//unscramble word
	bool found = false;
	for (int i = 0; i < permutations.size(); i++)
	{
		if (check(dictionary, 0, dictionarySize - 1, permutations[i]))
		{
			cout<<permutations[i]<<" was found at index: "<< i + 1 <<"\n";
			found = true;
		}
	}

	if(!found)
		cout<<"nothing was found\n";

    return 0;
}