//header file for child class: music. Parent = media
#include "media.h"

class Music : public media{
  
public:
 
  char* getArtist();
  void setArtist(char* inputArtist);
  int setDuration(int mins, int seconds);
  duration_t getDuration();
  char* getPublisher();
  void setPublisher(char* inputPublisher);
  int setRating(const char*);

  //destructor
  ~Music();
  
  //store contents privately
private:
  char artist[100];
  duration_t duration;
  char publisher[100];
};
