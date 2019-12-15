#include "classes.h"
#include "data_arrays.h"


//////////////////////////////////////////////  DATE
Date::Date(){

}
Date::Date(int a, int b, int c):
d(a), m(b), y(c){ }

void Date::print_date() const{
  cout << d << "/" << m << "/" << y << endl;
}


//////////////////////////////////////////////  POST
Post::Post(const int idd, const string post_titlee, const string post_creatorr, const Date post_created_datee, const string textt):
id(idd){ //initializing and printing for constructor messeges
  post_title= post_titlee;//copy the data to save it
  post_creator= post_creatorr;
  post_created_date = post_created_datee;
  text= textt;

  cout << "ID: " << id << endl;
  cout << "Post Title: " << post_title << endl;
  cout << "Post creator: " << post_creator << endl;
  cout << "Post Created Date: ";
  post_created_date.print_date();
  cout << "Post Text: " << text << endl;

}

Post::~Post(){//cleaning heap and printing destructor messeges
  cout << "Post number:" << id << " is about to be destroyed" << endl;
}

void Post::print_post() const{//prints specific post detailed
  cout << "ID: " << id << endl;
  cout << "Post Title: " << post_title << endl;
  cout << "Post creator: " << post_creator << endl;
  cout << "Creation Date: ";
  post_created_date.print_date();
  cout << "Post Text: " << text << endl;
}

int Post::Post_return_ID() const{//returns ID of post
  return id;
}
//////////////////////////////////////////////  THREAD

Thread::Thread(const string Subjectt, const string creatorr, const Date created_datee, const int pl):
pl_post(pl){//initializing and printing constructor messeges for Thread
  Subject= Subjectt;
  Creator= creatorr;
  Created_date = created_datee;

  Post_list = new Post*[pl_post];//creates heap memory for the list of posts and initializes the posts
  for(int i=0;i<pl_post;i++){
    Post_list[i]= new Post(static_ID++, get_random_title(), get_random_name(), Created_date, get_random_phrase());//for the Post ID it uses the global variable and then ++ for the next post
  }

  cout << "Thread with subject: <" << Subject << "> has just been created!" << endl;

}

Thread::~Thread(){//prints constructor messeges and frees memory from heap
  cout << "Thread with subject: <" << Subject << "> is about to be destroyed" << endl;
  for(int i=0;i<pl_post;i++){
    delete Post_list[i];
  }
  delete[] Post_list;
}

void Thread::Thread_print() const{//print Thread's Subject
    cout << "Subject: " << Subject << endl;
}

void Thread::Thread_print_details() const{//prints Threads data(subject, creator and date)
  cout << "Subject: " << Subject << endl;
  cout << "Creator: " << Creator << endl;
  cout << "Creation date: ";
  Created_date.print_date();
}

string Thread::Thread_get_Subject() const{//returns Threads Subject;
  return Subject;
}

void Thread::Thread_print_posts() const{//prints every post in the specific Thread
  for(int i=0;i<pl_post;i++){
    Post_list[i]->print_post();
  }
}

int Thread::Thread_search_post(const int x) const{//Search if specific post with ID x exists if yes it returns the ID else it returns a "false" number
  for(int i=0;i<pl_post;i++){
    if(Post_list[i]->Post_return_ID() == x){
      return i;
    }
  }
  return -1;
}

void Thread::Thread_print_post(const int z) const{//print specific post with ID z from the Thread
  Post_list[z]->print_post();
}


//////////////////////////////////////////////  FORUM

Forum::Forum(const string titlee, const int pl):
pl_Thread(pl){//initializing and printing constructor messeges
  Title= titlee;

  Date z(24);

  Thread_array = new Thread*[pl_Thread];
  Thread_array[0]= new Thread("Rules and usefull information", "Admins", z);//from excercise the first Thread must be Rulls and usefull information created by the Forum's Admins
  for(int i=1;i<pl_Thread;i++){//initialize the next Threads created by random names with random titles
    Thread_array[i]= new Thread(get_random_title(), get_random_name(), z);
  }

  cout << "Forum with title: <" << Title << "> has just been created!" << endl;
}

Forum::~Forum(){//free heap memory and print destructor messeges
  for(int i=0;i<pl_Thread;i++){
    delete Thread_array[i];
  }
  delete[] Thread_array;

  cout << "Forum with title: <" << Title << "> is about to be destroyed" << endl;
}

void Forum::Forum_print() const{//print Forum's Thread's Subject
  cout << "Printing Forum <" << Title << ">: " << endl;
  for(int i=0;i<pl_Thread;i++){
    Thread_array[i]->Thread_print();
  }
}

void Forum::Forum_print_thread(const string Subjectt) const{//Search and Print a Thread with specific subject named Subjectt
  int x;
  for(int i=0;i<pl_Thread;i++){//for every Thread
    if(!(Subjectt.compare(Thread_array[i]->Thread_get_Subject()))){//check if Thread's Subject is the one we are interested
      x=i;//save the Threads number
      break;
    }
  }
  Thread_array[x]->Thread_print_details();//print specific thread information
  Thread_array[x]->Thread_print_posts();//print specific thread posts
}

void Forum::Forum_search_post(const int x) const{//Search specific Post with ID x
  int z;
  for(int i=0;i<pl_Thread;i++){//for every thread
    z= Thread_array[i]->Thread_search_post(x);//Search if post x exists
    if(z != -1){//if false number is not returned
      Thread_array[i]->Thread_print_post(z);//print post with ID x
      return;
    }
  }

  cout << "Post not found" << endl;
}
