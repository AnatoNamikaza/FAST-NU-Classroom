#include<bits/stdc++.h> 
using namespace std; 
template<typename K, typename V> 
class HashNode 
{ 
public: 
  V value; 
  K key; 
	
  HashNode(K key, V value) 
  { 
    this->value = value; 
    this->key = key; 
  } 
}; 
template<typename K, typename V> 
class HashMap 
{ 
  HashNode<K,V> **arr; 
  int capacity; 
  int size; 
  HashNode<K,V> *dummy; 
public: 
  HashMap() 
  { 
    capacity = 20; 
    size=0; 
    arr = new HashNode<K,V>*[capacity]; 
    for(int i=0 ; i < capacity ; i++) 
      arr[i] = NULL; 
    dummy = new HashNode<K,V>(-1, -1); 
  } 
  int hashCode(K key) 
  { 
    return key % capacity; 
  } 	
  void insertNode(K key, V value) 
  { 
    HashNode<K,V> *temp = new HashNode<K,V>(key, value); 
		
    int hashIndex = hashCode(key); 
		
    cout << "HashIndex=" << hashIndex << endl;
	
    int probe_counter=1;
    while(arr[hashIndex] != NULL && (arr[hashIndex]->key != key 
				     || arr[hashIndex]->key != -1)) 
      {   
	hashIndex += probe_counter*probe_counter;
	probe_counter++;            
	hashIndex %= capacity;          
      } 
		
    if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1) {
      size++;
        
    }
      
    arr[hashIndex] = temp; 
  } 
	
  V deleteNode(int key) 
  { 
    int hashIndex = hashCode(key); 
    int probe_counter = 1;
    while(arr[hashIndex] != NULL) 
      { 
	if(arr[hashIndex]->key == key) 
	  { 
	    HashNode<K,V> *temp = arr[hashIndex]; 
				
	    arr[hashIndex] = dummy; 
				
	    size--; 
	    return temp->value; 
	  } 
	//hashIndex++;
	hashIndex += probe_counter*probe_counter;
	probe_counter++;
	hashIndex %= capacity; 
      } 
		
    cout << "Key not found";	
    return 0; 
  } 
	
  V get(int key) 
  { 
    int hashIndex = hashCode(key); 
    int counter=0;
    int probe_counter = 1;
    while(arr[hashIndex] != NULL) 
      { 
	// int counter =0; 
	//   return -20 ;	
	  
	if(arr[hashIndex]->key == key) 
	  return arr[hashIndex]->value; 
	//hashIndex++;
	hashIndex += probe_counter*probe_counter;
	probe_counter++;
	hashIndex %= capacity; 
      } 
		
    return -10; 
  } 
	
  int sizeofMap() 
  { 
    return size; 
  } 
	
  bool isEmpty() 
  { 
    return size == 0; 
  } 
	
  void display() 
  { 
    for(int i=0 ; i<capacity ; i++) 
      { 
	if(arr[i] != NULL && arr[i]->key != -1) 
	  cout << "key = " << arr[i]->key 
	       <<" value = "<< arr[i]->value << endl; 
      } 
  } 
}; 
int main() 
{ 
  HashMap<int, int> *h = new HashMap<int, int>; 
  h->insertNode(1,1); 
  //  //h->display(); 
  h->insertNode(3,13); 
  h->insertNode(2,2); 
  //h->display(); 
  h->insertNode(2,3); 
  h->display(); 
    
  //h->display(); 
  h->insertNode(3,33); 
  
  cout<< "h->sizeofMap()" <<endl; 
  cout << h->sizeofMap() <<endl; 
  cout <<"h->display()"; 
  h->display(); 
	
  cout << h->deleteNode(2) << endl; 
  cout << "h->sizeofMap()" <<endl; 
  cout << h->sizeofMap() <<endl; 
  h->display();
  cout << h->isEmpty() << endl; 
	
  cout << h->get(2); 
  return 0; 
} 
