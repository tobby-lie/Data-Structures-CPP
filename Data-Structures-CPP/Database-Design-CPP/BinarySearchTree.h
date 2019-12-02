//Tobby Lie
//CSCI 2421
//Final Project
//October 20, 2017
//BST class prototypes


#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "Record.h"

struct ActorNode{
    ActorActressRecord aRecord;
    ActorNode* left;
    ActorNode* right;
};

struct PictureNode{
    PictureRecord pRecord;
    PictureNode* left;
    PictureNode* right;
};

class ActorBST{ // // used to store actor records that will be used for searches, insertion, deletion and modification
private:
    ActorNode* root;
    int size;
public:
    void insert(string filename, ActorActressRecord aRecord);
    void deleteRecord(string filename, ActorActressRecord aRecord);
    void modifyRecord(string filename, string name); // this function will search for record name to identify which record is being changed, after record has been found, searching will stop and then switch statements will be used to see if the user would like to change certain fields of that record, this will continue until user specifies that they are done modifying
    ActorActressRecord searchActorYear(string filename, int _year); // search for year in actor database with BST, will return ActorActressRecord for output
    ActorActressRecord searchActorAward(string filename, string _award); // search for award in actor database with BST, will return ActorActressRecord for output
    ActorActressRecord searchActorName(string filename, string _name); // search for name in actor database with BST, will return ActorActressRecord for output
    ActorActressRecord searchActorFilm(string filename, string _film); // search for film in actor database with BST, will return ActorActressRecord for output
};

class PictureBST{ // used to store picture records that will be used for searches, insertion, deletion and modification
private:
    PictureNode* root;
    int size;
public:
    void insert(PictureRecord pRecord);
    void deleteRecord(PictureRecord pRecord);
    void modifyRecord(string filename, string name); // this function will search for record name to identify which record is being changed, after record has been found, searching will stop and then switch statements will be used to see if the user would like to change certain fields of that record, this will continue until user specifies that they are done modifying
    PictureRecord searchPictureYear(string filename); // search for year in picture database with BST, will return PictureRecord for output
    PictureRecord searchPictureAward(string filename); // search for award in picture database with BST, will return PictureRecord for output
    PictureRecord searchPictureName(string filename); // search for name in picture database with BST, will return PictureRecord for output
    PictureRecord searchPictureFilm(string filename); // search for film in picture database with BST, will return PictureRecord for output
    PictureRecord searchNominations(string filename); // search for nomination in picture database with BST, will return PictureRecord for output
    PictureRecord searchRating(string filename); // search for rating in picture database with BST, will return PictureRecord for output
    PictureRecord searchDuration(string filename); // search for duration in picture database with BST, will return PictureRecord for output
    PictureRecord searchGenre1(string filename); // search for genre1 in picture database with BST, will return PictureRecord for output
    PictureRecord searchGenre2(string filename); // search for genre2 in picture database with BST, will return PictureRecord for output
    PictureRecord searchRelease(string filename); // search for release in picture database with BST, will return PictureRecord for output
    PictureRecord searchMetacritic(string filename); // search for metacritic in picture database with BST, will return PictureRecord for output
    PictureRecord searchSynopsis(string filename); // search for synopsis in picture database with BST, will return PictureRecord for output
};
#endif /* BinarySearchTree_h */
