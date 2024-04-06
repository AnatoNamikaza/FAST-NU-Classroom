#include <iostream>
//L19-1196 2E1
using namespace std;

class Student{
private:
  char* name;
  int age;
  int* rollNo;
  char** courses;
  int noOfCourses;
public:
  Student(int rn, const char* n, int a){
    int index=0;
    while(n[index++]);
    this->name = new char[index];
    for(int i=0; i< index; i++) this->name[i] = n[i];
    this->name[index] = '\0';

    age = a;
    rollNo = new int;
    *rollNo = rn;
    noOfCourses =0;
    courses = new char*[8];
  
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
    noOfCourses =0;
    courses = new char*[8];
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
      noOfCourses =obj.noOfCourses;
      for(int i=0; i< noOfCourses; i++){
	//todo
      }
      courses = new char*[8];
    }
  }
  
  void addCourse(const char* n){
    int index=0;
    while(n[index++]);
    courses[noOfCourses] = new char[index];
    for(int i=0; i< index; i++) courses[noOfCourses][i] = n[i];
    courses[noOfCourses][index] = '\0';
    noOfCourses++;

  }
  void print(){
    cout << "Name: " << name << endl;
    cout << "age: " << age << endl;
    cout << "rollNo: " << *rollNo << endl;
    cout << "course list...\n";
    for(int i=0; i< noOfCourses; i++){
      cout << courses[i] << endl;
      
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
  Employee(const char* n, int a, int s){
    int index=0;
    while(n[index++]);
    this->name = new char[index];
    for(int i=0; i< index; i++) this->name[i] = n[i];
    this->name[index] = '\0';
    
    age =a;
    pay_scale = new int;
    *pay_scale = s;
  }
  
  char* getName(){
    return name;
  }
  
  int getAge(){return age;}
  int getPayScale(){return *pay_scale;}
  
  virtual void print()=0;

  ~Employee(){
    if(pay_scale !=0){
      delete pay_scale;
    }
    if(name !=0){
      delete []name;
    }
  }

};



class Teacher: public Employee{
  char* highest_qualification;
public:
  Teacher(const char* tn, int a, int s, const char* hq):
    Employee(tn,a,s)
  {
    int index=0;
    while(hq[index++]);
    highest_qualification = new char[index];
    for(int i=0; i< index; i++) highest_qualification[i] = hq[i];
    highest_qualification[index] = '\0';
  }

  virtual void print(){
    cout <<"Teacher Name: " << Employee::getName() << endl;
    cout << "Teacher age: " << Employee::getAge() << endl;
    cout << "Teacher scale: " << Employee::getPayScale() << endl;
    cout << "highest qualificaiton: " << highest_qualification << endl;
  }
  ~Teacher(){
    
    if(highest_qualification!=0){
      delete []highest_qualification;
    }
    
  }
};


class Staff: public Employee{
  char* job_description;
public:
  Staff(const char* n, int a, int s, const char* jd):
    Employee(n,a,s)
  {
    int index=0;
    while(jd[index++]);
    job_description = new char[index];
    for(int i=0; i< index; i++) job_description[i] = n[i];
    job_description[index] = '\0';

  }

  virtual void print(){
    cout <<"Staff Name: " << Employee::getName() << endl;
    cout << "Staff age: " << Employee::getAge() << endl;
    cout << "Staff scale: " << Employee::getPayScale() << endl;
    cout << "Job description: " << job_description << endl;
  }


  ~Staff(){
    if(job_description!=0){
      delete []job_description;
    }
    
  }
};

int main(){
  Student s1(1,"Ali",19);
  s1.addCourse("Programming Fundamentals");
  s1.addCourse("Object Oriented Programming");
  
  Teacher t1("Danial",31,18,"MS(CS)");
  Staff st1("Mr . Kamran",37, 18,"admin");

  Teacher t2("Dr. Farooq", 35,19, "PHD(CS)");
  
  Student s2(2,"Yaseen",20);
  s2.addCourse("Programming Fundamentals");
  s2.addCourse("Object Oriented Programming");
  s2.addCourse("Data structures");

  s1.print();
  s2.print();
  t1.print();
  t2.print();
  st1.print();
}
