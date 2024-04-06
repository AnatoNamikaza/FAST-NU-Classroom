#include <iostream>
// sir i will send the improved version soon
// i am having fever, therefore i need more time
// thanks
// 
using namespace std;

class Student{
private:
  char* name;
  int age;
  int* rollNo;
  char** courses;
  int noOfCourses;
public:
  Student(int rn, char* n, int a){
    int index=0;
    while(n[index++]);
    this->name = new char[index];
    for(int i=0; i< index; i++) this->name[i] = n[i];
    this->name[index] = '\0';

    age = a;
    rollNo = new int;
    *rollNo = rn;
  
  }
  Student(const Student &obj){
    int index=0;
    while(obj.name[index++]);
    this->name = new char[index];
    for(int i=0; i< index; i++) this->name[i] = obj.name[i];
    this->name[index] = '\0';

    age = obj.age;
    rollNo = new int;
    *rollNo = *obj.rollNo;
  }

  Student &operator = (const Student &obj){
    if(this != &obj){
      if(this->name !=0){
	delete []name;
	delete rollNo;
	
      }

      int index=0;
      while(obj.name[index++]);
      this->name = new char[index];
      for(int i=0; i< index; i++) this->name[i] = obj.name[i];
      this->name[index] = '\0';

      age = obj.age;
      rollNo = new int;
      *rollNo = *obj.rollNo;
    }
    
  }
 
  ~Student(){
    if(name!=0){
      delete []name;
    }
    
    if(rollNo!=0){
      delete rollNo;
 
    }

    if(courses!=0){
      for(int i=0; i< noOfCourses; i++){
	delete []courses[i];
      }
      delete []courses;
    }
 
  }
};

class Employee{
  char* name;
  int age;
  int* pay_scale;
public:
  
  ~Employee(){
    if(name!=0){
      delete []name;
    }
    
    if(pay_scale!=0){
      delete pay_scale;
    }
    
  }
};

class Teacher: public Employee{
  char* highest_qualification;
public:

  ~Teacher(){
    if(highest_qualification!=0){
      delete []highest_qualification;
    }
    
  }
};
class Staff: public Employee{
  char* job_description;

  ~Staff(){
    if(job_description!=0){
      delete []job_description;
    }
    
  }
};

int main(){
 

}
