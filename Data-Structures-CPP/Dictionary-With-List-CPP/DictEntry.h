//Tobby Lie
//CSCI 2421
//Homework 6
//October 1, 2017
//DictEntry class prototypes
//provided by Dr. Augustine

#ifndef DICTENTRY_
#define DICTENTRY_
#include <string>

typedef std::string wordType; // string
class DictEntry
{
private:
    wordType word; // string
    wordType definition; // string
public:
    wordType getWord(){return word;}
    void setWord(wordType _word){word = _word;}
    wordType getDef(){return definition;}
    void setDef(wordType _def){definition = _def;}
    bool operator < (const DictEntry &entry) const {
        return (word < entry.word);}
};

#endif
