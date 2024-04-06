#include<iostream>
using namespace std;

class myArray {
private:
	int size; // Array size
	int *ptr; // Pointer for dynamic 1-D Array
public:
	myArray() {
		size = 0;
		ptr = nullptr;
	}

	myArray(int size) {
		this->size = size;
		ptr = new int[size];
		for (int i = 0; i < size; i++) {
			ptr[i] = 0;
		}
	}

	myArray(int *arr, int size) {
		this->size = size;
		ptr = new int[size];
		for (int i = 0; i < size; i++) {
			ptr[i] = arr[i];
		}
	}

	myArray(const myArray &p) { // copy constructor
		this->size = p.size;
		ptr = new int[p.size];
		for (int i = 0; i < p.size; i++) {
			ptr[i] = p.ptr[i];
		}
	}

	myArray &operator=(const myArray &p) {
		if(this->size==0){
			delete[]ptr;
			ptr= nullptr;
		}
		this->size = p.size;
		ptr = new int[p.size];
		for (int i = 0; i < p.size; i++) {
			ptr[i] = p.ptr[i];
		}
	}

	int &operator[](const int i) {
		if (i > -1 && i < this->size) {
			return this->ptr[i];
		} else {
			cout << "Out of Range. \n";
		}
	}

	const int &operator[](const int i) const {
		if (i > -1 && i < this->size) {
			return ptr[i];
		}
	}

	myArray &operator++() { // increment data of all elements
		for (int i = 0; i < this->size; i++) {
			this->ptr[i]++;
		}
	}

	myArray operator++(int q) { // increment data of all elements
		for (int i = 0; i < this->size; i++) {
			this->ptr[i] = this->ptr[i] + q;
		}
	}

	bool operator==(const myArray &p) { //compare size and data of all elements
		bool xin = false;
		if (this->size == p.size) {
			for (int i = 0; i < this->size; i++) {
				if (this->ptr[i] == p.ptr[i]) {
					xin = true;
				} else {
					xin = false;
					return xin;
				}
			}
		}
		return xin;
	}

	bool operator!=(const myArray &p) {
		bool xin = true;
		if (this->size == p.size) {
			for (int i = 0; i < this->size; i++) {
				if (this->ptr[i] == p.ptr[i]) {
					xin = false;
				} else {
					xin = true;
					return xin;
				}
			}
		}
		return xin;
	}

	friend istream &operator>>(istream &in, myArray &p) { //take size and data from console
		int i;
		cout << "Enter the total digits in the Array: \n";
		in >> i;
		p.size = i;
		cout << "Enter the Array: \n";
		i = 0;
		p.ptr=new int[p.size];
		for (; i < p.size; i++) {
			cout << "Element#" << i + 1 << " of Array: \n";
			in >> p.ptr[i];
		}

		return in;
	}

	friend ostream &operator<<(ostream &out, const myArray &p) {     //print data of array on console
		if (p.size != 0) {
			for (int i = 0; i < p.size; i++) {
				out << p.ptr[i];
			}
		}
		out << endl;

		return out;
	}

	myArray operator+(const myArray &p) {    // Return array containing data of both arrays merged
		myArray temp;
		int size = this->size + p.size;
		temp.size = size;

		temp.ptr = new int[size];
		for (int i = 0; i < size; i++) {
			int j = 0;
			if (i < this->size) {
				temp.ptr[i] = this->ptr[i];
			} else {
				temp.ptr[i] = p.ptr[j];
				j++;
			}
		}
	}

	friend myArray operator+(const int x, myArray &p) {
		myArray temp;
		temp.size = p.size;

		temp.ptr = new int[p.size];
		for (int i = 0; i < p.size; i++) {
			temp.ptr[i] = p.ptr[i] + x;
		}

		return temp;
	}

	~myArray() {

	}
};

int main() {
	myArray h1(3);
	myArray h2(4);
//	cin >> h1;
	cout << h1;
//	cin >> h2;
	cout << h2;
//	h1++; h2++;
	cout << h1;
	cout << h2;
	cout << h1 << h2 << '\n';
	cout << (h1 == h2) << "\n";
	cout << (h1 != h2) << "\n";
	cout << h1 + h2 << "\n";
	cout << 2 + h1 ;
	cout << h2[1];


	system("pause");

	return 0;
}