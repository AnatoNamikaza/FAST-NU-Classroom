#include <iostream>
using namespace std;

class BinaryNum
{
private:
  int* binNum;	//integer array to save binary number
  int noOfBits;	//total no. of bits
public:
  //*modified
  BinaryNum(){binNum=0; noOfBits=0;}
  
  BinaryNum(const char *str){
    int lenth=0;
    noOfBits=0;
    while(*(str+lenth++)) noOfBits++;
    
    binNum = new int [noOfBits];
    cout << noOfBits << "---------------\n";
    for(int i=0; i < noOfBits; i++) binNum[i] = str[i]-'0';
  }
  //------------------- get number of bits
  int getNumberOfBits() reutrn noOfBits;
  int * getBinaryNo() return binNum;
  
  BinaryNum operator +(const BinaryNum & obj){
    int pnb = noOfBits;
    noOfBits = noOfBits+obj.getNumberOfBits()+1; // may be carried forward
    int *temp = new int [noOfBits];
    int *other_number = obj.getBinaryNo();
    if(pnb > obj.getNumberOfBits()){
      int carry=0;
      for(int i=0; i< pnb; i++){
	int result=carry+other_number[i]+binNum[i];
	if(result ==2){carry=1; result=0;}
	else if(result==3){carry=1; result=1;}
	else if (result ==1) {carry = 0; result=1;}
	else{carry=0; result=0;}
	temp[i] = result;
      }
      temp[noOfBits] = carry;
    }
    
  }
  //------------------------------------
    BinaryNum operator -(const BinaryNum & obj){
    int pnb = noOfBits;
    noOfBits = noOfBits+obj.getNumberOfBits(); // may be carried forward
    int *temp = new int [noOfBits];
    int *other_number = obj.getBinaryNo();
    if(pnb > obj.getNumberOfBits()){
      int carry=0;
      for(int i=0; i< pnb; i++){
	int result=binNum[i]-other_number[i];
	if(result ==0){carry=0; result=0;}
	else if(result==-1){carry=2; result=1;}
	else{carry=0; result=0;}
	temp[i] = result;
      }

    }
    delete binNum;
    for(int i=0; i< noOfBits; i++) binNum[i]=temp[i];
    delete temp;
    return this;
  }
  //-------------------------------------
  	BinaryNum operator++() {
		for(int i=0; i< noOfBits; i++){
			if(binNum[noOfbits+i] == 1) bin[noOfbits+i]=0;
			else{bin[noOfbits+i]=0;break;}
		}
		return this;
	}
  
  
  bool operator == (const BinaryNum& obj) {
		if (noOfBits == obj.noOfBits) {
			int count = 0;
			for (int i = 0;i < noOfBits;i++) {
	if (binNum[i] == obj.binNum[i])count++;
			}
			if (count == noOfBits)return true;
		}
		return false;
	}
  //--------end of modified
  void Print(){
	  if(binNum != 0){
	    for(int i = 0 ; i< noOfBits ; i++)
	      cout<<binNum[i];
	  }
	  //out<<endl;
	}
  //--------------- << operator
  friend ostream & operator <<(ostream &out, const BinaryNum & obj){
    for(int i = 0 ; i< obj.noOfBits; i++)
      cout << obj.binNum[i];
	  }
	  cout<<endl;
    return out;
  }
//------------------
  friend istream & operator >>(istream &in, const BinaryNum & obj){
    for(int i = 0 ; i< obj.noOfBits; i++)
      cin >> obj.binNum[i];
	  }
    return in;
  }
  
  ~BinaryNum(){
    if(noOfBits !=0) delete []binNum;
    binNum = 0; // or nullptrx
  }

};

int main()
{
  BinaryNum b1;			//noOfBits = 0, binNum is NULL
  BinaryNum b2("101");	//noOfBits = 3, binNum is {1,0,1}
  BinaryNum b3("1001");	//noOfBits = 4, binNum is {1,0,0,1}
  
  cout<<"b1 = ";cout<<b1;	//Prints Nothing
  cout<<"b2 = ";cout<<b2;	//Prints 101
  cout<<"b3 = ";cout<<b3;	//Prints 1001
  
  // 	b1 = b2+b3;
  // 	cout<<"b1 = "<<b1;	//Prints 1110
  	cout<<"b1[0] = "<<b1[0]<<endl;	//Prints 1 (0th bit in b1)
   	cout<<"b1[3] = "<<b1[3]<<endl;	//Prints 0 (3rd bit in b1)
  
  // 	cout<<b3++;				
   bool check = (b3==b2);
  // cout<<"is equal= "<<check;			//Prints 0
  // cout<<++b3;							
  // cin>>b2; 				
  // cout<<b1-b2; 			
  b2.Print();
  return 0;
}
