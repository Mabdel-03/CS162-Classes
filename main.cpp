/*Code Written By Mahmoud Abdelmoneum
 * Code Written on 3/21/2021
 * Classes is a project that serves as a media database holding video games,
 * movies, and songs. It allows for additions, as well as searches, and 
 * provides practice using classes in C++
 */

#include <iostream>
#include "VideoGames.h"
#include "Music.h"
#include "Movies.h"
#include <vector>
#include <cstring>
#define MOVIES 1
#define VIDEOGAMES 2
#define MUSIC 3
using namespace std;

//set up function prototypes
bool checkLegal(char *command);
void quit();
char* searchMedia(vector<media*> *mediaVtr);
void deleteMedia(vector<media*> *mediaVtr);
void addMedia(vector<media*> *vtrptr, int typeOfMedia);
bool mediaValidCheck(char *type);

//Media search - Title, or year? 
char* searchMedia(vector<media*> *mediaVtr){
  duration_t duration;
  char searchTitle[100]; //title searched
  int searchYear = 0; //year searched
  char searchCommands[100]; 

  //Prompt user for input
  cout << "Search by TITLE or by YEAR? (Enter TITLE or YEAR)" << endl;
  cin.get(searchCommands, 6);
  cin.get();

  //search by title
  if(strcmp(searchCommands, "TITLE") == 0 || strcmp(searchCommands, "title") == 0){
    cout << "Enter a Title: " << endl;
    cin.get(searchTitle, 100);
    cin.get();
  }

  //search by year
  else if(strcmp(searchCommands, "YEAR") == 0 || strcmp(searchCommands, "year") == 0){
    cout << "Enter a year: " << endl;
    cin >> searchYear;
    cin.get();
  }
  else {
    cout << "invalid input." << endl;
  }

  //iterate through vector of media pointers
  for(vector<media*>::iterator index = mediaVtr->begin(); index!=mediaVtr->end(); ++index){

    //if title matches title of what index points to or year matches year...
    if(strcmp((*index)->getTitle(), searchTitle) == 0 || (*index)->getYear() == searchYear){

      //print out commonalities from all 3 child classes (title and year)
      cout << "Title: " << (*index)->getTitle() << endl;
      cout << "Year: " << (*index)->getYear() << endl;

      //now check if movie, and if so print out movie contents
      if((*index)->getType() == MOVIES){
	cout << "Type: Movie" << endl;
	cout << "Director: " << (dynamic_cast<Movies*>(*index))->getDirector() << endl;
	cout << "Rating: " << (dynamic_cast<Movies*>(*index))->getRating() << endl;
	duration = (dynamic_cast<Movies*>(*index))->getDuration();
	cout << "Duration: " << duration.mins << ":" << duration.seconds << endl;
	cout << " " << endl;
       }

      //if video game, print out video game contents
      else if((*index)->getType() == VIDEOGAMES){
	cout << "Type: video game" << endl;
	cout << "Publisher: " << (dynamic_cast<VideoGames*>(*index))->getPublisher() << endl;
	cout << "Rating: " << (dynamic_cast<VideoGames*>(*index))->getRating() << endl;
	cout << " " << endl;
       }

      //if music, print out music contents
      else if((*index)->getType() == MUSIC){
	cout << "Type: music" << endl;
       	cout << "Artist: " << (dynamic_cast<Music*>(*index))->getArtist() << endl;
	duration = (dynamic_cast<Music*>(*index))->getDuration();
	cout << "Duration: " << duration.mins << ":" << duration.seconds << endl; 
	cout << "Publisher: " << (dynamic_cast<Music*>(*index))->getPublisher() << endl;
      }
      
       else { //something isn't right if it's else..
	 cout << "ERROR: could not find class name. " << endl;
	 cout << (*index)->getType() << endl;
       }
     }
  }
  return NULL; 
}

//delete media by searching title or year
void deleteMedia(vector<media*> *mediaVtr){
  char verify[2]; //either y or n
  //basically the same algorithm as searchMedia
  duration_t duration;
  char searchTitle[100];
  int searchYear = 0;
  char searchCommands[100];
  //ask user input
  cout << "To delete: search by TITLE or by YEAR? (TITLE/YEAR)" << endl;
  cin.get(searchCommands, 6);
  cin.get();

  //search by title
  if(strcmp(searchCommands, "TITLE") == 0 || strcmp(searchCommands, "title") == 0){
    cout << "Enter a Title: " << endl;
    cin.get(searchTitle, 100);
    cin.get();
  }

  //search by year
  else if(strcmp(searchCommands, "YEAR") == 0 || strcmp(searchCommands, "year") == 0){
    cout << "Enter a year: " << endl;
    cin >> searchYear;
    cin.get();
  }
  else {
    cout << "invalid input." << endl;
  }

  //iterate through vector of media pointers to find user's search
  for(vector<media*>::iterator index = mediaVtr->begin(); index!=mediaVtr->end(); ++index){

    //if fields match..
    if(strcmp((*index)->getTitle(), searchTitle) == 0 || (*index)->getYear() == searchYear){
      cout << "Title: " << (*index)->getTitle() << endl;
      cout << "Year: " << (*index)->getYear() << endl;

      //for movies..
      if((*index)->getType() == MOVIES){
	cout << "Type: Movie" << endl;
	cout << "Director: " << (dynamic_cast<Movies*>(*index))->getDirector() << endl;
	cout << "Rating: " << (dynamic_cast<Movies*>(*index))->getRating() << endl;
	duration = (dynamic_cast<Movies*>(*index))->getDuration();
	cout << "Duration: " << duration.mins << ":" << duration.seconds << endl;

	//verify decision with user
	cout << "Are you sure you would like to delete this movie? (y/n) " << endl;
	cin.get(verify, 2);
	cin.get();
	if (strcmp(verify, "y") == 0 || strcmp(verify, "Y") == 0){
	  mediaVtr->erase(index);
	  delete (dynamic_cast<Movies*>(*index));
	  return;
	}
	else{
	  cout << "Movie not deleted. " << endl;
	}
       }

      //for video games..
      else if((*index)->getType() == VIDEOGAMES){
	cout << "Type: video game" << endl;
	cout << "Publisher: " << (dynamic_cast<VideoGames*>(*index))->getPublisher() << endl;
	cout << "Rating: " << (dynamic_cast<VideoGames*>(*index))->getRating() << endl;
	cout << " " << endl;

	//verify decision with user
	cout << "Are you sure you would like to delete this video game? (y/n) " << endl;
	cin.get(verify, 2);
	cin.get();
	if (strcmp(verify, "y") == 0 || strcmp(verify, "Y") == 0){
	  mediaVtr->erase(index);
	  delete (dynamic_cast<VideoGames*>(*index));
	  return;
	}
	else{
	  cout << "Video game not deleted. " << endl;
	}
       }

      //for music..
      else if((*index)->getType() == MUSIC){
	cout << "Type: music" << endl;
       	cout << "Artist: " << (dynamic_cast<Music*>(*index))->getArtist() << endl;
	duration = (dynamic_cast<Music*>(*index))->getDuration();
	cout << "Duration: " << duration.mins << ":" << duration.seconds << endl; 
	cout << "Publisher: " << (dynamic_cast<Music*>(*index))->getPublisher() << endl;

	//verify decision with user
	cout << "Are you sure you would like to delete this song? (y/n) " << endl;
	cin.get(verify, 2);
	cin.get();
	if (strcmp(verify, "y") == 0 || strcmp(verify, "Y") == 0){
	  mediaVtr->erase(index);
	  delete (dynamic_cast<Music*>(*index));
	  return;
	}
	else{
	  cout << "Song not deleted. " << endl;
	}
      }
         else { //something isn't right if it's else..
	 cout << "ERROR: could not find class name. " << endl;
	 cout << (*index)->getType() << endl;
       }
     }
  }
    return;
}

//add media to vector
void addMedia(vector<media*> *vtrptr, int typeOfMedia){

  //local variables to pass into class methods
  int minutesLocal = 0;
  int secondsLocal = 0;
  int yearLocal = 0;
  char ratingLocal[6]; 
  char titleLocal[100];
  char directorLocal[100];
  
  //adding movie
  if(typeOfMedia == 1){
    Movies* movie = new Movies(); //create new movie
    cout << "Enter the title of the movie: " << endl;
    cin.get(titleLocal, 100);
    cin.clear();
    cin.ignore(10000, '\n');
    movie->setTitle(titleLocal);
    cout << "Enter the year it was made: " << endl;
    cin >> yearLocal;
    cin.clear();
    movie->setYear(yearLocal);
    cin.ignore(10000, '\n');
    cout << "Enter the director: " << endl;
    cin.get(directorLocal, 100);
    cin.clear();
    cin.ignore(10000, '\n');
    movie->setDirector(directorLocal);
    cout << "Enter the duration in minutes and seconds." << endl;
    cout << "FIRST enter the duration in minutes (seconds later): " << endl;
    cin >> minutesLocal;
    cout << "Now enter seconds: " << endl;
    cin >> secondsLocal;
    movie->setDuration(minutesLocal, secondsLocal);
    cin.ignore(10000, '\n');
    cout << "Enter the rating: " << endl;
    cout << "Possible ratings include G, PG, PG-13, R, NR. " << endl;
    cin.get(ratingLocal, 6);
    cin.clear();
    cin.ignore(10000, '\n');
    movie->setRating(ratingLocal);
    movie->setType(MOVIES);

    //push back vector to "upload" contents
    vtrptr->push_back(movie);
    cout << "Movie added." << endl;
  }
  
//adding video game
  if(typeOfMedia == 2){
    VideoGames *vg = new VideoGames(); //create new Video Game
    cout << "Enter the title of the video game: " << endl;
    cin.get(vg->getTitle(), 100);
    cin.get();
    cout << "Enter the year it was released: " << endl;
    cin >> yearLocal;
    cin.get();

    //ask for user input on video game fields
    vg->setYear(yearLocal);
    cout << "Enter the publisher of the video game: " << endl;
    cin.get(vg->getPublisher(), 100);
    cin.get();
    cout << "Enter the rating of the video game: " << endl;
    cout << "Possible video game ratings: E10+, E, EC, T, M, RP, AO" << endl;
    cin.get(ratingLocal, 6);
    cin.get();
    vg->setRating(ratingLocal);
    vg->setType(VIDEOGAMES);
    vtrptr->push_back(vg);
    cout << "Video game added." << endl;
  }

  //adding music
  if(typeOfMedia == 3){
    Music *m = new Music(); //new music 
    cout << "Enter the title of the song: " << endl;
    cin.get(m->getTitle(), 100);
    cin.get();
    cout << "Enter the year it was released: " << endl;
    cin >> yearLocal;
    cin.get();
    m->setYear(yearLocal);
    cout<< "Enter the artist: " << endl;
    cin.get(m->getArtist(), 100);
    cout << "Enter the duration in minutes and seconds." << endl;
    cout << "FIRST enter the duration in MINUTES (seconds later): " << endl;
    cin >> minutesLocal;
    cout << "Now enter the seconds: " << endl;
    cin >> secondsLocal;
    cin.get();
    m->setDuration(minutesLocal, secondsLocal);
    cout << "Enter the publisher of the song: " << endl;
    cin.get(m->getPublisher(), 100);
    cin.get();
    cout << "Music added." << endl;    
    m->setType(MUSIC);
    vtrptr->push_back(m); //push back vector to "upload" contents
  }
    return;
}

//quit program
void quit(){
  //all this function does is say a goodbye statement
  cout << "Quitting program. See you next time!" << endl;
  return;
}


//check to make sure the given command is allowed
bool checkLegal(char *command){
  if(strcmp(command, "ADD") == 0){
    return true;
  }
  if(strcmp(command, "DELETE") == 0){
    return true;
  }
  if(strcmp(command, "QUIT") == 0){
    return true;
  }
  if(strcmp(command, "SEARCH") == 0){
    return true;
  }
  //if it's not legal..
  return false;
}

//check to see if added media type is allowed
bool mediaValidCheck(char *type){
  //if legal:
  if(strcmp(type, "MOVIE") == 0){
    return true;
  }
  //if legal:
  if(strcmp(type, "VIDEO GAME") == 0){
    return true;
  }
  //if legal:
  if(strcmp(type, "MUSIC") == 0){
    return true;
  }
  //if not legal:
    return false;
}

int main(){
  
  //vector containing Parent class: media
  vector<media*> mediaVtr;
  char type[20]; //contains what type of media user wants to add
  int typeOfMedia = 0; //either 1) movie 2) video game or 3) music
  cout << "Welcome to the media database." << endl;
  char command[7];

  while (strcmp(command, "QUIT") != 0){
    //ask user input for command
    cout << "Enter a command: ADD, SEARCH, DELETE, QUIT" << endl;
    cin.get(command, 7);
    cin.get();
    char searchCommands[6]; //either title or year
    char search[100]; //title of media or year of media
    bool mediaValid = false;
    
    //format to all uppercase
    for(int i = 0; i < strlen(command); i++){
      command[i] = toupper(command[i]);
    }
    bool isLegal = checkLegal(command);
    //check if legal
    if(isLegal == true){
      
      if(strcmp(command, "ADD") == 0){
	//continuous loop until a valid input is given
	do {
	  cout << "What type of media? (movie/video game/music)" << endl;
	  cin.get(type, 20);
	  cin.get();
	
	  //format to upper
	  for(int i = 0; i < strlen(type); i++){
	    type[i] = toupper(type[i]);
	  }
	  //make sure input is a valid type
	  mediaValid = mediaValidCheck(type);
	  if (mediaValid == true) {
	    //
	    //while (mediaValid != true){
	    if(strcmp(type, "MOVIE") == 0){
	      typeOfMedia = 1;
	    }
	    else if(strcmp(type, "VIDEO GAME") == 0){
	      typeOfMedia = 2;
	    }
	    else if(strcmp(type, "MUSIC") == 0){
	      typeOfMedia = 3;
	    }
	  }
	} while (mediaValid == false); // end while 
	//valid input (out of while loop)
	addMedia(&mediaVtr, typeOfMedia);
      }
      
      //pass in vector of media to search
      if(strcmp(command, "SEARCH") == 0){
	searchMedia(&mediaVtr);
      }

      //pass in vector of media to delete
      if(strcmp(command, "DELETE") == 0){
	deleteMedia(&mediaVtr);
      }

    }
  }
  //quit
  quit();
  return 0;
}
