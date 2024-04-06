#include <iostream>
using namespace std;

  template <class type>
  type GetMax(type a, type b){
  if(a > b){return a;}
  return b;
  }

  template <class type>
  type GetMin(type a, type b){
  if(a < b){return a;}
  return b;
  }


template <class T>
class Pair{
  T a;
  T b;

public:
  Pair(T x, T y);
  T GetMax();
  T GetMin();
  void print();
};

template <class T>
Pair<T>::Pair(T x, T y){a=x; b=y;}

template <class T>
T Pair<T>::GetMax()
{
  if(a > b){return a;}
  return b;
}
template <class T>
T Pair<T>::GetMin(){
  if(a < b){return a;}
  return b;
}
template <class T>
void Pair<T>::print(){
  cout << "a: " << a << " b: " << b << endl;
}

template <class T>
class Container {
private:
  T counter;
public:
  Container(T n){counter = n;}
  void increase(){
    counter++;
  }
  T getCounter(){return counter;}
};

template <>
class Container <char>{
private:
  char x;
public:
  Container(char a){x = a;}
  void upperCase(){
    if(x <= 122 && x >=97){
      x=x-32; // otherwise leave it unmodified
   }
  }
  char getChar(){return x;}
};

template <class T, int N>
class Sequence{
  T memBlock[N];
public:
  void setMember(int x, T value){
    memBlock[x]=value;
  }
  T getMember(int x){
    return memBlock[x];
  }
  
};

int main(){
   Sequence <int, 5> myints;
   Sequence <double, 5> myfloats;
   myints.setMember(0,100);
   myfloats.setMember(3,3.01416);
   cout << myints.getMember(0) << '\n';
   cout << myfloats.getMember(3) << '\n';

  
  /*
  Pair <double> myobject (1.012, 1.01234);
  cout << myobject.GetMin();
  cout << myobject.GetMax();
  myobject.print();
  
  Container <char> myChar('a');
  Container <int> myInt(3);
  myChar.upperCase();
  cout << myChar.getChar();
  cout << myInt.getCounter();

    int i=5, j=6, k;
    long l=10, m=5, n;
    k=GetMax<int>(i,j);
    n=GetMin<int>(l,m);
    cout << k << endl;
    cout << n << endl;
 
    cout << GetMin(2,3);
    cout << GetMin<int>(2.5,3);
  */
  return 0;
}
