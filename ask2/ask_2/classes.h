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

  string Post_get_post_creator() const;
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

  Post** Thread_get_posts() const;
  int Thread_get_pl_post() const;
};

////////////////////////////////////////////////////////////LIST
typedef struct List_node * ListPtr;

typedef struct List_node{
  Post* ID;
  ListPtr next;
}List_node;

class List{
  ListPtr l;
  void List_create(ListPtr& list);
  int List_empty(ListPtr list) const;
  void List_insert(ListPtr& list, Post& id);
  void  List_print_data(ListPtr list) const;
  void List_print_all(ListPtr list) const;
  void List_destruct(ListPtr& list);
  void List_combine(ListPtr& list, ListPtr& SList);
public:
  List();
  ~List();
  void List_delete();
  void List_insert_list(Post& t);
  void List_print() const;
  void List_combine_Lists(List& SList);
};

////////////////////////////////////////////////////////////TREE
typedef struct Tree_node* TreePtr;

typedef struct Tree_node{
  string username;
  List* Post_list;
  TreePtr left;
  TreePtr right;
}Tree_node;

class Tree{
  TreePtr t;
  void Tree_create(TreePtr& tree);
  int Tree_empty(TreePtr tree) const;
  void Tree_insert(TreePtr& tree, const string name, Post& NPost);
  void Tree_insert(TreePtr& tree, const string name, List*& NList);
  void Tree_print_all(TreePtr tree) const;
  void Tree_print_data(TreePtr tree) const;
  void Tree_destruct(TreePtr& tree);
  void Tree_add_tree(TreePtr& tree);
public:
  Tree(Thread *S_Thread);
  Tree(Tree* STree);
  ~Tree();
  void Tree_print() const;
  void Tree_enchance(Tree*& STree);
};
////////////////////////////////////////////////////////////FORUM
class Forum{
  string Title;
  int pl_Thread;
  Thread** Thread_array;
  Tree** Tree_Array;
public:
  Forum(const string title, const int pl=5);
  ~Forum();

  void Forum_print() const;
  void Forum_print_thread(const string Subjectt) const;
  void Forum_search_post(const int x) const;

  void Forum_print_sorted() const;
};
