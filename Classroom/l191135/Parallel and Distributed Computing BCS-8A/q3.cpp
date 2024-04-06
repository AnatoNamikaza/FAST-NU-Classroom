#include<iostream>
#include<time.h>
using namespace std;

void printArray(int A[], int size)
{
  for (auto i = 0; i < size; i++)
    cout << A[i] << " ";
}

class Matrix{
public:
  int rows;
  int cols;
  int **matrix;
  Matrix(int r, int c){
    rows = r;
    cols = c;
    matrix = new int*[rows];
    for(int i=0; i < rows; i++){
      matrix[i] = new int[cols];
    }
  }
  ~Matrix(){
    for(int i=0; i < rows; i++){
      delete(matrix[i]);
    }
  }

  void print(){
    for(int i=0; i< rows; i++){
      for(int j=0; j < cols; j++){
	cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
  }

  void populate(){
    for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
	matrix[i][j]=rand() % 50;
      }
    }
  }
};

struct ArrayData{
  int *array;
  int begin;
  int end;
  int sum;
  ArrayData(int *arr, int b, int e, int s){
    array = arr;
    begin = b;
    end = e;
    sum = s;
  }
  void print(){
    cout << "Array\n";
    printArray(array,end-begin+1);
    cout << endl;
    cout << "begin: " << begin << " end " << end << " sum: " << sum <<endl;
  }
};

void merge(int array[], int left, int mid, int right)
{
  auto const subArrayOne = mid - left + 1;
  auto const subArrayTwo = right - mid;

  // Create temp arrays
  auto *leftArray = new int[subArrayOne],
    *rightArray = new int[subArrayTwo];

  // Copy data to temp arrays leftArray[] and rightArray[]
  for (auto i = 0; i < subArrayOne; i++)
    leftArray[i] = array[left + i];
  for (auto j = 0; j < subArrayTwo; j++)
    rightArray[j] = array[mid + 1 + j];

  auto indexOfSubArrayOne = 0, // Initial index of first sub-array
    indexOfSubArrayTwo = 0; // Initial index of second sub-array
  int indexOfMergedArray = left; // Initial index of merged array

  // Merge the temp arrays back into array[left..right]
  while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
    if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
      array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
      indexOfSubArrayOne++;
    }
    else {
      array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
      indexOfSubArrayTwo++;
    }
    indexOfMergedArray++;
  }
  // Copy the remaining elements of
  while (indexOfSubArrayOne < subArrayOne) {
    array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
    indexOfSubArrayOne++;
    indexOfMergedArray++;
  }
  // Copy the remaining elements of
  while (indexOfSubArrayTwo < subArrayTwo) {
    array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
    indexOfSubArrayTwo++;
    indexOfMergedArray++;
  }
}

void *mergeSort(void * args)
{  
  ArrayData *mat = (ArrayData *) args;  
  if (mat->begin >= mat->end){
    int *element = new int(mat->array[mat->begin]);
    return (void *) element;
  }
  
  auto mid = mat->begin + (mat->end - mat->begin) / 2;
  ArrayData *left = new ArrayData(mat->array, mat->begin, mid,0);
  ArrayData *right = new ArrayData(mat->array, mid+1, mat->end,0);    

  pthread_t *twoThreads = new pthread_t[2];
  pthread_create(&twoThreads[0],NULL,mergeSort,left);
  pthread_create(&twoThreads[1],NULL,mergeSort,right);

  int  *left_sum = new int;
  *left_sum = 0;
  int *right_sum = new int;
  *right_sum= 0;
  pthread_join(twoThreads[0],(void **) &left_sum);
  pthread_join(twoThreads[1],(void **) &right_sum);
    
  int *total = new int;
  *total = (*left_sum) + (*right_sum);

  merge(mat->array, mat->begin, mid, mat->end);
  return (void *) total;
}


int main()
{
  srand(time(0));
  
  cout << "enter rows: ";
  int rows;
  cin >> rows;

  cout << "enter cols: ";
  int cols;
  cin >> cols;

  Matrix *mat = new Matrix(rows,cols);
  mat->populate();

  mat->print();
  
  int total = 0;
  int *row_sum = 0;
  pthread_t *threads = new pthread_t[rows];
  for(int i=0; i< mat->rows; i++){      
  ArrayData *data = new ArrayData(mat->matrix[i],0,mat->cols-1,0);
  pthread_create(&threads[i], NULL, mergeSort, data);
  }
  
  for(int i=0; i< mat->rows; i++){      
    pthread_join(threads[i],(void **)&row_sum);
    total = total + *row_sum;
  }
  
  
  cout << "\nSorted array is \n";
  mat->print();
  cout << "\ntotal sum: " << total << endl;

  return 0;
  }
