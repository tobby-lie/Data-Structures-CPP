//Tobby Lie
//CSCI 2421
//Final Project
//October 20, 2017
//Records classes prototypes

#ifndef Header_h
#define Header_h

#include <string>

using namespace std;

class ActorActressRecord{
    
private:
    int year;
    string award;
    bool winner;
    string name;
    string film;
public:
    void setYear(int _year);
    int getYear() const;
    void setAward(string _award);
    string getAward() const;
    void setWinner(int _status);
    bool isWinner() const;
    void setName(string _name);
    string getName() const;
    void setFilm(string _film);
    string getFilm() const;
};

class PictureRecord{
    
private:
    string name;
    int year;
    string nomination;
    float rating;
    float duration;
    string genre1;
    string gentre2;
    string release;
    string metacritic;
    string synopsis;
    
public:
    void setName(string _name);
    string getName() const;
    void setYear(int _year);
    int getYear() const;
    void setNomination(string _nomination);
    string getNomination() const;
    void setRating(float _rating);
    float getRating() const;
    void setDuration(float _duration);
    float getDuration() const;
    void setGenre1(string _genre1);
    string getGenre1() const;
    void setGenre2(string _genre2);
    string getGenre2() const;
    void setRelease(string _release);
    string getRelease() const;
    void setMetacritic(string _metacritic);
    string getMetacritic() const;
    void setSynopsis(string _synopsis);
    string getSynopsis() const;
};

#endif /* Header_h */






















