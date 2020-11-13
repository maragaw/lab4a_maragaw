// WordCount.cpp

#include "WordCount.h"
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

// Default constructor
WordCount::WordCount() {
	for(int i = 0; i < CAPACITY; i++){
		vector<pair<string,int>> vv;
		table[i] = vv;
	}
}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int total = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		if(table[i]){
			total++;
		}
	}
	return total;
}

int WordCount::getNumUniqueWords() const {
	int num = 0;
	for(size_t i = 0; i < CAPACITY; i++){ //
		//iterator to point to first 
		vector<pair<string,int>>::const_iterator iter1 = table[i].begin();
		size_t j = 0;
		for (j = 0; j < i; j++){
			vector<pair<string,int>>::const_iterator iter2;

			for(iter2 = table[j].begin(); iter2 < table[j].end(); iter2++){
				if(iter2->first == iter1->first) break;
			}
		}
		if(iter1 == iter2)
			num++;

		iter1++;
	}
	return num;
}

int WordCount::getWordCount(std::string word) const {
	//return number of occurences for a specific word
	//meaning the value to the key given
	int count = 0;
	size_t index = hash(word);
	vector<pair<string,int>>::const_iterator iter;
	for(iter = table[index].begin(); iter !=table[index].end();iter++){
		if(iter->first == word)
			count++;
	}
	return count;
}
	
int WordCount::incrWordCount(std::string word) {
	size_t index = hash(word);
	//first check if word is in table
	vector<pair<string, int>>::const_iterator iter;
	for(iter = table[index].begin(); iter != table[index].end(); iter++){
		if(iter->first == word) break;
	}
	//if it got to the end and didnt find it
	if(iter == table[index].end()){
		//add it in
		pair<string,int> newpair {word, 1};
		table[index].push_back(newpair);
		return iter->second;
	}
	
	iter->second++;
	return iter->second;
	
}

int WordCount::decrWordCount(std::string word) {
	size_t index = hash(word);
	vector<pair<string, int>>::const_iterator iter;
	for(iter = table[index].begin(); iter != table[index].end(); iter++){
		if(iter->first == word) break;
	}
	if(iter == table[index].end())
		return -1;
	if(iter != table[index].end() && iter->second > 1)
		iter->second--;
		return iter->second;
	else if (iter != table[index].end() && iter->second = 1){
		table[index].erase(iter);
	}
	return 0;
}

bool WordCount::isWordChar(char c) {
	
	return isalpha(c);
}

std::string WordCount::makeValidWord(std::string word) {
	stringstream ss;
	string result;
	for(int i = 0; i < word.length(); i++){
		if(isWordChar(word[i]))
			ss << word[i];
	}
	ss >> result;
	//convert to lowercase
	for(int i = 0; i<result.length(); i++){
		result[i] = tolower(result[i]);
	}

	return result;
}
