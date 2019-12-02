//Tobby Lie
//CSCI 2421
//Final Project
//October 20, 2017
//database function prototypes

#ifndef functions_h
#define functions_h

#include <vector>
#include <fstream>
#include <string>
#include "Record.h"
#include "BinarySearchTree.h"

using namespace std;

void menu(); // will display menu with options that is controlled by a loop

void readActorsToVector(string filename, vector<ActorActressRecord> &actorVec); // read Actors database into vector

void readActorsToBinSearchTree(string filename, ActorBST &aBST); // read Actors database into binary search tree

void readPicturesToVector(string filename,  vector<ActorActressRecord> &actorVec); // read pictures database into vector

void readPicturesToBinSearchTree(string filename, ActorBST &aBST); // read pictures database into binary search tree

void writeUpdatedActorsFromVector(string filename, const vector<ActorActressRecord> &actorsRecord); // write updated Actors vector into database file

void writeUpdatedActorsFromBinSearchTree(string filename, const ActorBST &actorsBST); // write updated Actors BST into database file

void writeUpdatedPicturesFromVector(string filename, const vector<PictureRecord> &picturesRecord); // write updated Pictures vector into database file

void writeUpdatedPicturesFromBinSearchTree(string filename, const ActorBST &picturesBST); // write updated Pictures BST into database file

void outputReport(string actorsFile, string picturesFile); // function will ask user for fields to search for and how the output will be sorted, will be output to report file

void addInfo(string filename); // add record into BST and which immediately sorts by name, will then rewrite database file

void modifyInfo(string filename);// modify record via BST, will overwrite original database file

void deleteInfo(string filename); // delete record in desired database, will overwrite original database file

void sortYear(string filename); // sort desired database by year with a vector, will overwrite original database file

void sortAward(string filename); // sort desired database by award with a vector, will overwrite original database file

void sortName(string filename); // sort desired database by name with a vector, will overwrite original database file

void sortFilm(string filename); // sort desired database by film with a vector, will overwrite original database file

void sortNominations(string filename); // sort desired nomination by film with a vector, will overwrite original database file

void sortRating(string filename); // sort desired database by rating with a vector, will overwrite original database file

void sortDuration(string filename); // sort desired database by duration with a vector, will overwrite original database file

void sortGenre1(string filename); // sort desired database by genre1 with a vector, will overwrite original database file

void sortGenre2(string filename); // sort desired database by genre2 with a vector, will overwrite original database file

void sortRelease(string filename); // sort desired database by release with a vector, will overwrite original database file

void sortMetacritic(string filename); // sort desired database by metacritic with a vector, will overwrite original database file

void sortSynopsis(string filename); // sort desired database by synopsis with a vector, will overwrite original database file

#endif /* functions_h */




























