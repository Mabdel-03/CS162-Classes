//header file for child class: movies
//parent class is media
#include "media.h"

class Movies : public media {
public:

  char* getDirector();
  void setDirector(char* inputDirector);
  duration_t getDuration();
  const char* getRating();
  int setRating(char* inputRating);
  int setDuration(int mins, int seconds);  
  Movies(); //constructor used to set type
  ~Movies(); //deconstructor
  
  //store contents privately
private:
  char director[100];
  duration_t duration;
  char rating;
};
