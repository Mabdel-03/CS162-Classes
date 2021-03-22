//getters and setters for Music

#include <iostream>
#include <cstring>
#include "Music.h"
using namespace std;

char* Music::getArtist(){
  return artist;
}

//set saved artist to inputted artist from addMedia() in main.cpp
void Music::setArtist(char* inputArtist){
  strcpy(artist, inputArtist);
  return;
}

duration_t Music::getDuration(){
  return duration;
}

//uses struct to set duration
int Music::setDuration(int mins, int seconds){
  duration.mins = mins;
  duration.seconds = seconds;
  return 0;
}

char* Music::getPublisher(){
  return publisher;
}

//sets saved publisher to the inputted publisher from addMedia() in main.cpp
void Music::setPublisher(char* inputPublisher){
  strcpy(publisher, inputPublisher);
  return;
}

//destructor
Music::~Music(){
  cout << "Song has been deleted." << endl;
}
