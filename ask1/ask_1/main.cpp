#include "classes.h"

int static_ID=0;

int main(void){
  srand(time(NULL));

  cout << "<CONSTRUCTOR MESSEGES>" << endl;
  cout << "<------------------------------------------>" << endl;
  Forum MForum("Object Oriented Programming", 4); //initialize Forum
  cout << "<------------------------------------------>" << endl;
  cout << "</CONSTRUCTOR MESSEGES>\n" << endl;

  cout << "<PRINT FORUM>" << endl;
  cout << "<------------------------------------------>" << endl;
  MForum.Forum_print(); //print Forum
  cout << "<------------------------------------------>" << endl;
  cout << "</PRINT FORUM>\n" << endl;

  cout << "<PRINT Rules and usefull information THREAD>" << endl;
  cout << "<------------------------------------------>" << endl;
  MForum.Forum_print_thread("Rules and usefull information"); //Print Rules and usefull information Thread
  cout << "<------------------------------------------>" << endl;
  cout << "</PRINT Rules and usefull information THREAD>\n" << endl;

  cout << "<SEARCH FIRST RANDOM POST>" << endl;
  cout << "<------------------------------------------>" << endl;
  MForum.Forum_search_post(rand() % static_ID); //Search random post 1
  cout << "<------------------------------------------>" << endl;
  cout << "</SEARCH FIRST RANDOM POST>\n" <<endl;

  cout << "<SEARCH SECOND RANDOM POST>" << endl;
  cout << "<------------------------------------------>" << endl;
  MForum.Forum_search_post(rand() % static_ID); //Search random post 2
  cout << "<------------------------------------------>" << endl;
  cout << "</SEARCH SECOND RANDOM POST>\n" << endl;

  cout << "<PROGRAM ENDED STARTING DESTROYING>" << endl;
  return 0;
}
