#include<iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include<cstring>
using namespace std;

void displayHelp();
void createDatabase(char *filename);
void search(char *filename, int id);
void add(char *filename);
void updateRecord();

typedef struct Book{
  int id;
  int n_authors;
  int author_counter;
  char title[70];
  char authors[5][70];
  char date_of_publication[15];
  char publisher[70];
}Book_t;

Book_t * newBook(){
  Book_t *book = (Book_t *)malloc(sizeof(Book_t));
  book->n_authors=5;
  book->author_counter = 0;
  return book;
}

typedef struct dbms{
  Book_t **books;
}dbms_t;

void setID(Book_t *book,int id){
  book->id = id;
}
void setTitle(Book_t *book,char title[70]){
  strcpy(book->title, title);
}

void addAuthor(Book_t *book,char author[70]){
  if((book->author_counter) < book->n_authors){
  strcpy(book->authors[book->author_counter++], author);
  }
  else{
    cout << "cannot add more than 5 authors\n";
  }
}

void setDate(Book_t *book,char date[15]){
  strcpy(book->date_of_publication, date);
}

void setPublisher(Book_t *book,char publisher[70]){
  strcpy(book->publisher, publisher);
}

void printBook(Book_t *book){
  cout << "Book id: " << book->id << endl;
  cout << "Book Title: " << book->title << endl;
  cout << "Date of publication: " << book->date_of_publication << endl;
  cout << "publisher: " << book->publisher << endl;
  cout << "<<====Author List======>>\n";
  for(int i=0; i< book->author_counter; i++){
    cout  << i+1 << ": " << book->authors[i] << endl;    
  }
  cout << "-----------------------\n";
}

void readFromUser(Book_t *book){
  cout<<"Enter book id: ";
  cin>> book->id;
  cin.ignore();
  cout<<"Enter title of book: ";
  cin.getline(book->title,70);
  
  cout<<"Enter publication date: ";
  cin.getline(book->date_of_publication,15);
  cout<<"Enter book publisher: ";
  cin.getline(book->publisher,70);

  cout<<"Number of Authors: ";
  int number;
  cin>>number;
  cin.ignore();
  for(int i=0;i<number;i++)
    {
      cout << "Enter" << i+1<<" author of the book: ";
      cin.getline(book->authors[i],70);
    }
}

int main(){
  int id = 1;
  char title[]="Askarism";
  
  char author1[] = "Cr";
  char author2[] = "zaeem";
  char author3[] = "shehmeer";
  char author4[] = "fazeel";
  char author5[] = "Uncle Iftkhar";

  char date[] = "01-01-2001";
  char publisher[] = "FAST NUCES publisher ";

  Book_t *book = newBook();;

  setID(book,id);
  setTitle(book,title);
  setDate(book,date);

  addAuthor(book, author1);
  addAuthor(book, author2);
  addAuthor(book, author3);
  addAuthor(book, author4);
  addAuthor(book, author5);
  
  setPublisher(book,publisher);
  printBook(book);

  readFromUser(book);

  printBook(book);
  int x;
  cin >> x; // holding screen
}
void displayHelp(){
  cout<<"Following commands are valid\n";
  cout<<"[update] to update the record\n";
  cout<<"[add] add record to the system.\n";
  cout<<"[search] to search the database.\n";
  cout<<"[print] details of the book in database\n";
  cout<<"[exit] to exit from the system.\n";
}

void updateRecord(){
  int fd=open("record.dat",O_RDWR,ios::binary|ios::in);
  Book *data=(Book *)mmap(0,100*sizeof(Book_t),PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
  Book_t *b=newBook();;
  readFromUser(b);
  data[b->id]=*b;
  cout<<"Record updated successfully\n";
}

void createDatabase(char *filename){
  int fd0=open(filename,O_RDWR,ios::binary|ios::out);
  lseek(fd0,700*sizeof(Book_t),SEEK_SET); // making hols for future data
  Book_t* b=newBook();;
  write(fd0,b,sizeof(Book_t));
  close(fd0);
}

void add(char *filename){
  int fd=open(filename,O_RDWR,ios::binary|ios::in);
  Book_t *data=(Book_t *)mmap(0,100*sizeof(Book_t),PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
  Book_t *b=newBook();;
  readFromUser(b);
  data[b->id]=*b;
  cout<<"Entered success\n";
}

void search(char *filename){
  int id;
  cout<<"enter book id: ";
  cin>>id;
  int fd=open(filename,O_RDWR,ios::binary|ios::in);
  Book_t *data=(Book_t *)mmap(0,100*sizeof(Book_t),PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
  if(data[id].id!=0){
    cout<<"Book found\n";
    printBook(&data[id]);
  }
  else
    {
      cout << "Not found\n";
    }
  close(fd);       
}
