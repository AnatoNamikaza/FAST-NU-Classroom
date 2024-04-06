template <typename T>
void grow(T *&arr, int newSize, int originalSize){
try{
    if(newSize < originalSize || newSize < 0){
throw newSize;
    }
    else{
     //allocate new memory for larger array
     T *tempArray = new T [newSize];
     for(int i=0; i< originalSize; i++){
        tempArray[i] = arr[i];
     }
     // elements have been copied
     // delete small array
     delete []arr;
     // point it to new array
    arr = tempArray;
    // update the size of array
    originalSize = newSize;

    }
}
catch(int size){
    //if new size is less, then no need to alter the array
cout << "new size should be non negative and bigger than " << originalSize << endl;
}

}
