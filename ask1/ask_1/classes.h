#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

extern int static_ID;

////////////////////////////////////////////////////////////DATE
class Date{
  int d;
  int m;
  int y;
public:
  Date();
  Date(int a, int b=12, int c=2019);

  void print_date() const;
};

////////////////////////////////////////////////////////////POST
class Post{
  int id;
  string post_title;
  string post_creator;
  Date post_created_date;
  string text;
public:
  Post(const int, const string, const string, const Date, const string);
  ~Post();

  void print_post() const;
  int Post_return_ID() const;
};

////////////////////////////////////////////////////////////THREAD
class Thread{
  string Subject;
  string Creator;
  Date Created_date;
  int pl_post;
  Post** Post_list;
public:
  Thread(const string, const string, const Date, const int pl=5);
  ~Thread();

  void Thread_print() const;
  void Thread_print_details() const;
  void Thread_print_posts() const;
  string Thread_get_Subject() const;
  int Thread_search_post(const int) const;
  void Thread_print_post(const int) const;
};

////////////////////////////////////////////////////////////FORUM
class Forum{
  string Title;
  int pl_Thread;
  Thread** Thread_array;
public:
  Forum(const string title, const int pl=5);
  ~Forum();

  void Forum_print() const;
  void Forum_print_thread(const string Subjectt) const;
  void Forum_search_post(const int x) const;
};
