//Parent class

#include <iostream>
#include <cstring>
#include "media.h"
#define MOVIES 1
#define VIDEOGAMES 2
#define MUSIC 3

using namespace std;

int media::getYear(){
  return year;
}

//set inputted year from addMedia() in main.cpp to saved year
int media::setYear(int inputYear){
  year = inputYear;
  return 0;
}

char* media::getTitle(){
  return title;

}

//set inputted type from addMedia() in main.cpp to saved type of media
int media::setType(int inputType){
  if (inputType == MOVIES){
    type = 1;
    return 1;
  }
  else if (inputType == VIDEOGAMES){
    type = 2;
    return 2;
  }
  else if (inputType == MUSIC){
    type = 3;
    return 3;
  }
  else {
    return 0;
  }
}

int media::getType(){
  if(type == 1){
    return MOVIES;
  }
  else if(type == 2){
    return VIDEOGAMES;
  }
  else if(type == 3){
    return MUSIC;
  }
  else {
    return 0;
  }
}

//save inputted title to title
int media::setTitle(char* inputTitle) {
  strcpy(title, inputTitle);
  return 0;
}

