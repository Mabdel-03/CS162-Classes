//header file for Child class: VideoGames. Parent = media

#include "media.h"

class VideoGames : public media{

public:
  char* getPublisher();
  void setPublisher(char* inputPublisher);
  const char* getRating();
  int setRating(char* inputRating);

  //destructor
  ~VideoGames();
  //privately store contents
private:
  char title[100];
  int year;
  char publisher[100];
  char rating;
};
