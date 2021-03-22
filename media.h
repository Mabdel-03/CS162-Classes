//header file for Parent class: media. Children = Music, Movies, VideoGames
#pragma once //only include once per compilation

//struct to hold duration of music and movies
struct duration_t {
  int mins;
  int seconds;
};

class media{
public:
  int getYear();
  char* getTitle();
  int setTitle(char* inputTitle);
  int setYear(int inputYear);
  int setType(int inputType);
  int getType();
  int type;

  //virtual destructor 
  virtual ~media() {};

private:
  //store fields
  char title[100];
  int year;
};
