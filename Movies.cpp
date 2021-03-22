//getters and setters for Movies

#include <iostream>
#include "Movies.h"
#include <cstring>
#define MOVIES 1

using namespace std;

//constants
const char* G_RATING = "G";
const char* PG_RATING = "PG";
const char* PG13_RATING = "PG-13";
const char* R_RATING = "R";
const char* NR_RATING = "NR";

char* Movies::getDirector(){
  return director;
}

//set saved director to the director passed in from addMedia() in main.cpp
void Movies::setDirector(char* inputDirector){
  strcpy(director, inputDirector);
  return;
}

duration_t Movies::getDuration(){
  return duration;
}

//set saved rating to the input passed in from addMedia() in main.cpp
int Movies::setRating(char* inputRating){

  bool valid = true;
  char option = 'a';
  do{
    valid = true;
    if(strcmp(inputRating, "G") == 0 || strcmp(inputRating, "g") == 0){
      option = 'a';
    }
    else if(strcmp(inputRating, "PG") == 0 || strcmp(inputRating, "pg") == 0){
      option = 'b';
    }
    else if(strcmp(inputRating, "PG-13") == 0 || strcmp(inputRating, "PG13") == 0
	    || strcmp(inputRating, "pg-13") == 0 || strcmp(inputRating, "pg13") == 0){
      option = 'c';
    }
    else if(strcmp(inputRating, "R") == 0 || strcmp(inputRating, "r") == 0){
      option = 'd';
    }
    else if(strcmp(inputRating, "NR") == 0 || strcmp(inputRating, "nr") == 0){
      option = 'e';
    }
    else{
      valid = false;
      cout << "That is not a valid movie rating." << endl;
      cout << "Possible movie ratings: G, PG, PG-13, R, NR" << endl;
      cout << "Enter a rating again: " << endl;
      cin.get(inputRating, 6);
      cin.get();
    }
    rating = option;
  } while (valid == false);
  return 0;
}

//sets duration in struct
int Movies::setDuration(int mins, int seconds){
  duration.mins = mins;
  duration.seconds = seconds;
  return 0;
}



const char* Movies::getRating(){
  if(rating == 'a'){
    return G_RATING;
  }
  else if(rating == 'b'){
    return PG_RATING;
  }
  else if(rating == 'c'){
    return PG13_RATING;
  }
  else if(rating == 'd'){
    return R_RATING;
  }
  else if(rating == 'e'){
    return NR_RATING;
  }
  else{
    return NULL;
  }
}

//constructor
Movies::Movies(){
  setType(MOVIES);
}


//destructor
Movies::~Movies(){
  cout << "Movie has been deleted." << endl;
}
