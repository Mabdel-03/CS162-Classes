#include <iostream>
#include "VideoGames.h"
#include <cstring>
using namespace std;

//constants
const char* E10_RATING = "E10+";
const char* E_RATING = "E";
const char* EC_RATING = "EC";
const char* T_RATING = "T";
const char* M_RATING = "M";
const char* RP_RATING = "RP";
const char* AO_RATING = "AO";

//sets saved publisher to inputted publisher from addMedia() in main.cpp
void VideoGames::setPublisher(char* inputPublisher){
  strcpy(publisher, inputPublisher);
  return;
}

char* VideoGames::getPublisher(){
  return publisher;
}

//save passed in rating to rating
int VideoGames::setRating(char* inputRating){
  char option = 'a';
  bool valid = true;
  do{
    valid = true;
    if(strcmp(inputRating, "E10+") == 0 || strcmp(inputRating, "e10+") == 0){
      option = 'a'; //everyone 10+
    }
    else if(strcmp(inputRating, "E") == 0 || strcmp(inputRating, "e") == 0){
      option = 'b'; //everyone
    }
    else if(strcmp(inputRating, "EC") == 0 || strcmp(inputRating, "ec") == 0){
      option = 'c'; //early childhood
    }
    else if(strcmp(inputRating, "T") == 0 || strcmp(inputRating, "t") == 0){
      option = 'd'; //teen
    }
    else if(strcmp(inputRating, "M") == 0 || strcmp(inputRating, "m") == 0){
      option = 'e'; //mature
    }
    else if(strcmp(inputRating, "RP") == 0 || strcmp(inputRating, "rp") == 0){
      option = 'f'; //rating pending
    }
    else if(strcmp(inputRating, "AO") == 0 || strcmp(inputRating, "ao") == 0){
      option = 'g'; //adult only
    }
    else{
      valid = false;
      cout << "Not a valid video game rating." << endl;
      cout << "Possible video game ratings: E10+, E, EC, T, M, RP, AO" << endl;
      cout << "Enter a rating again: " << endl;
      cin.get(inputRating, 6);
      cin.get();
    }
    rating = option;
  } while (valid == false); 
  return 0;
}

const char* VideoGames::getRating(){
  if(rating == 'a'){
    return E10_RATING;
  }
  else if(rating == 'b'){
    return E_RATING;
  }
  else if(rating == 'c'){
    return EC_RATING;
  }
  else if(rating == 'd'){
    return T_RATING;
  }
  else if(rating == 'e'){
    return M_RATING;
  }
  else if(rating == 'f'){
    return RP_RATING;
  }
  else if(rating == 'g'){
    return AO_RATING;
  }
  else{
    return NULL;
  }
}


//destructor
VideoGames::~VideoGames(){
  cout << "Video game deleted." << endl;
}
