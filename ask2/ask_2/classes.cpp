#include "classes.h"
#include "data_arrays.h"

//////////////////////////////////////////////  LIST
List::List(){
  List_create(l);
}

List::~List(){
 List_destruct(l);
}

//<private>
void List::List_create(ListPtr& list){
  list=NULL;
}

int List::List_empty(ListPtr list) const{
  return(list==NULL);
}

void List::List_destruct(ListPtr& list){//delete all the memory from heap(for lists)
  if(List_empty(list)){
    return;
  }
  List_destruct(list->next);
  delete list;
  list=NULL;
}

void List::List_insert(ListPtr& list, Post& id){//insert new post in end of list
  if(List_empty(list)){//go to last List node of the List and create new node
    list= new List_node;
    list->ID= &id;
    list->next= NULL;
  }else{
    List_insert(list->next, id);
  }
}

void List::List_combine(ListPtr& list, ListPtr& SList){ //combine 2 lists (end of first)
  if(List_empty(SList)){
    return;
  }else{
    List_insert(list, *(SList)->ID);
    List_combine(list, SList->next);
  }
}

void List::List_print_data(ListPtr list) const{
  list->ID->print_post();
}

void List::List_print_all(ListPtr list) const{
  if(!List_empty(list)){
    List_print_data(list);
    List_print_all(list->next);
  }
}
//</private>

void List::List_insert_list(Post& t){ // insert to list(usable from outside List scope)
  List_insert(l, t);
}

void List::List_combine_Lists(List& SList){// combine 2 lists(usable from outside List scope)
  List_combine(l, SList.l);
}

void List::List_print() const{ // print the list
  List_print_all(l);
}

void List::List_delete(){ // free memory
  List_destruct(l);
}

//////////////////////////////////////////////  TREE
Tree::Tree(Tree* STree){//copy constructor
  Tree_create(t);
  Tree_add_tree(STree->t);
}

Tree::Tree(Thread *S_Thread){//constructor for Tree, with argument a Thread and insert data to the tree
  Tree_create(t);

  Post** temp;//create a temp Post array
  temp= S_Thread->Thread_get_posts();//and copy the Threads Post array to the temp array
  for(int i=0;i<S_Thread->Thread_get_pl_post();i++){//go through the array and insert data to tree
    Tree_insert(t, temp[i]->Post_get_post_creator(), *temp[i]);
  }
}

Tree::~Tree(){//destructor
  Tree_destruct(t);
}
//<private>

void Tree::Tree_create(TreePtr& tree){
  tree=NULL;
}

int Tree::Tree_empty(TreePtr tree) const{
  return(tree==NULL);
}

void Tree::Tree_insert(TreePtr& tree, const string name, Post& NPost){//insert post to Tree
  if(Tree_empty(tree)){//check if Tree is empty(if there is no Tree node with the specific username)
    tree= new Tree_node;//if yes create new node for the Tree
    tree->username= name;
    tree->Post_list= new List;
    tree->Post_list->List_insert_list(NPost);//and insert the Post to the Lists node
    tree->left = NULL;
    tree->right = NULL;
  }else if(tree->username.compare(name) > 0){//if first not maching character is greater then insert to the left side of the tree
    Tree_insert(tree->left, name, NPost);
  }else if(tree->username.compare(name) < 0){//if first not maching character is smaller then insert to the right side of the tree
    Tree_insert(tree->right, name, NPost);
  }else if(tree->username.compare(name) == 0){//if the username exists then add the Post to the already existing List
    tree->Post_list->List_insert_list(NPost);
  }
}

void Tree::Tree_insert(TreePtr& tree, const string name, List*& NList){//same as above but to combine Lists (if the username already exists in 2 or more trees
  if(Tree_empty(tree)){                                                //or it doesent and we have to add a List of Posts instead of a single Post
    tree= new Tree_node;
    tree->username= name;
    tree->Post_list= new List;
    tree->Post_list->List_combine_Lists(*NList);
    tree->left = NULL;
    tree->right = NULL;
  }else if(tree->username.compare(name) > 0){
    Tree_insert(tree->left, name, NList);
  }else if(tree->username.compare(name) < 0){
    Tree_insert(tree->right, name, NList);
  }else if(tree->username.compare(name) == 0){
    tree->Post_list->List_combine_Lists(*NList);
  }
}

void Tree::Tree_add_tree(TreePtr& tree){
  if(!Tree_empty(tree)){//go throught the second Tree and combine it with the first Tree by inserting each username and username's List to the first tree
    Tree_add_tree(tree->left);
    Tree_insert(t, tree->username, tree->Post_list);
    Tree_add_tree(tree->right);
  }
}

void Tree::Tree_print_data(TreePtr tree) const{//print Data of the Tree node
  cout << tree->username << "======" << endl;
  tree->Post_list->List_print();
}

void Tree::Tree_print_all(TreePtr tree) const{//print all the Tree
  if(!Tree_empty(tree)){
      Tree_print_all(tree->left);
      Tree_print_data(tree);
      Tree_print_all(tree->right);
  }
}

void Tree::Tree_destruct(TreePtr& tree){//Destroy the Tree
  if(Tree_empty(tree)){
    return;
  }
  Tree_destruct(tree->left);
  Tree_destruct(tree->right);
  tree->Post_list->List_delete();//and each Tree nodes list
  delete tree->Post_list;
  delete tree;
  tree= NULL;
}
//</private>

void Tree::Tree_enchance(Tree*& STree){//enchance "parent" tree with a second tree
  Tree_add_tree(STree->t);
}

void Tree::Tree_print() const{//print tree but usable from outside of Tree scope
  Tree_print_all(t);
}
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

string Post::Post_get_post_creator() const{ //returns creator of post
  return post_creator;
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


Post** Thread::Thread_get_posts() const{ // returns the array with the posts of the Thread
  return Post_list;
}

int Thread::Thread_get_pl_post() const{// retruns how many posts there are in the Thread
  return pl_post;
}

//////////////////////////////////////////////  FORUM

Forum::Forum(const string titlee, const int pl):
pl_Thread(pl){//initializing and printing constructor messeges
  Title= titlee;

  Date z(24);

  Thread_array = new Thread*[pl_Thread];
  Tree_Array= new Tree*[pl_Thread];
  Thread_array[0]= new Thread("Rules and usefull information", "Admins", z);//from excercise the first Thread must be Rulls and usefull information created by the Forum's Admins
  Tree_Array[0]= new Tree(Thread_array[0]);
  for(int i=1;i<pl_Thread;i++){//initialize the next Threads created by random names with random titles
    Thread_array[i]= new Thread(get_random_title(), get_random_name(), z);
    Tree_Array[i]= new Tree(Thread_array[i]);//initialize each tree with the specific Thead
  }

  cout << "Forum with title: <" << Title << "> has just been created!" << endl;
}

Forum::~Forum(){//free heap memory and print destructor messeges
  for(int i=0;i<pl_Thread;i++){
    delete Thread_array[i];
  }
  delete[] Thread_array;

  for(int i=0;i<pl_Thread;i++){
    delete Tree_Array[i];
  }
  delete[] Tree_Array;

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

void Forum::Forum_print_sorted() const{
  Tree temp(Tree_Array[0]);//create a new temp tree with the copy constructor and start it with the first Tree
  for(int i=1;i<pl_Thread;i++){
    temp.Tree_enchance(Tree_Array[i]);//and enchance it with the rest
  }
  temp.Tree_print(); // then print it
}//and free it with the tree destructor automaticaly
