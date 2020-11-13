#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>

using namespace std;

int main(){
    WordCount wc;
    int test1 = wc.incrWordCount("testword");
    int insert1 = wc.incrWordCount("something");
    int insert2 = wc.incrWordCount("testword");
    int test2 = wc.getTotalWords();
    int test3 = wc.getNumUniqueWords();
    int test4 = wc.getWordCount("testword");
    int test5 = wc.decrWordCount("testword");
    string test6 = wc.makeValidWord("43HeLLo$");

    ASSERT_EQUALS(1, test1);
    ASSERT_EQUALS(1, test2);
    ASSERT_EQUALS(3, test3);
    ASSERT_EQUALS(2, test4);
    ASSERT_EQUALS(1 ,test5);
    ASSERT_EQUALS("hello",test6);
    return 0;
}