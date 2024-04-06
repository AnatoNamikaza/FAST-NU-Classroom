#include <iostream>
using namespace std;
// l19 1196 2E1 

class MobilePhone{
 protected:
  int* battery;
  float* camera;
  char* osVersion;
 public:
 MobilePhone(){
  battery =0;
  camera = 0;
  osVersion = 0;
}

  MobilePhone(int b, float c, const char* v){
  battery = new int;
  camera = new float;
  *battery = b;
  *camera = c;
    
  int index =0;
  while(v[index++]);
  osVersion = new char[index];
  for(int i=0; i< index; i++){
    osVersion[i] = v[i];
  }
  osVersion[index]='\0';
}

void printinfo(){
  cout << "Battery: " << *battery << " mAph\n";
  cout << "camera : " << *camera << " pixel\n";
  cout << "operating system: " << osVersion << endl;
}

void inputinfo(){
  battery = new int;
  cout << "enter battary mAph: ";
  cin >> *battery;
  cout << "enter camera in pixels: ";
  camera = new float;
  cin >>  *camera;
  cout << "enter os name: ";
  char v[20];
  cin >> v;

  int index =0;
  while(v[index++]);
  osVersion = new char[index];
  for(int i=0; i< index; i++){
    osVersion[i] = v[i];
  }
  osVersion[index]='\0';
}

~MobilePhone(){
  delete []osVersion;
  delete camera;
  delete battery;
}

};

class Android : public MobilePhone {
 private:
  int ram;
 public:

 Android(int b,float c, const char* v, int r) :MobilePhone(b,c,v), ram(r)
    { }
  int getRam(){return ram;}
  void setRam(int r){ram = r;}

~Android(){
  delete []osVersion;
}

};

class iPhone : public MobilePhone{
private:
  bool audioJack;
  int ram;
public:
  iPhone(int b, float c, const char* v, int r, bool aj):MobilePhone(b,c,v), ram(r), audioJack(aj){}
  
  void printinfo(){
    cout << "camera: " << camera << endl;
    cout << "os version: " << osVersion << endl;
    cout << "audio jack: " << audioJack << endl;
    
  }

  void inputinfo(){
    inputinfo();
    cin >> audioJack;
  }

  ~iPhone(){
    delete []osVersion;
    delete battery;
    delete camera;
  }
};

int main(){
  MobilePhone m1(2300, 18, "marshmallow");
  m1.printinfo();
  Android a1(2500, 17, "jellibean", 3);
  a1.printinfo();
  bool audioJack = true;
  iPhone ip(2500, 20.5, "x-10", 3, audioJack);
}
