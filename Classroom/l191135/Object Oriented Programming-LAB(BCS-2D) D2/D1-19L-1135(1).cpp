#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class BinaryNum {
private:
	int* binNum;
	int noOfBits;
public:

	BinaryNum() {
		binNum = NULL;
		noOfBits = 0;
	}
	BinaryNum(const char *p) {
		int size = 0;
		for (int i = 0; p[i] != '\0'; i++) {
			size++;
		}
		noOfBits = size;
		binNum = new int[size];
		for (int i = 0; i < size; i++) {
			int temp = p[i] - 48;
			binNum[i] = temp;
		}
	}

	BinaryNum(const BinaryNum &p2) {
		this->noOfBits = p2.noOfBits;
		for (int i = 0; i < this->noOfBits; i++) {
			this->binNum[i] = p2.binNum[i];
		}
	}

	int BintoDe(BinaryNum temp) {
		int val = 0;
		int p = 0;
		for (int i = temp.noOfBits - 1; i >= 0; i--) {
			val = val + (binNum[i] * (2 ^ p));
			p++;
		}

		return val;
	}

	BinaryNum DetoBin(int val) {
		int Num[16];
		int n = val;
		int i = 0;
		while (n > 0) {
			Num[i] = n % 2;
			n = n / 2;
			i++;
		}

		for (int x = 0; x <= i; x++) {
			int y = i;
			if (y >= 0) {
				int kn = 0;
				kn = Num[y];
				Num[y] = Num[x];
				Num[x] = kn;
				y--;
			};
			if (y < 0) {
				break;
			};
		}
		BinaryNum temp;
		temp.noOfBits = i + 1;
		temp.binNum = new int[i + 1];
		for (int k = 0; k < i + 1; k++) {
			binNum[k] = Num[k];
		}

		return temp;
	}

	BinaryNum NDetoBin(int val) {
		int Num[16];
		int n = val;
		int i = 0;
		while (n > 0) {
			Num[i] = n % 2;
			n = n / 2;
			i++;
		}
		for (int x = 0; x <= i; x++) {
			int y = i;
			if (y >= 0) {
				int kn = 0;
				kn = Num[y];
				Num[y] = Num[x];
				Num[x] = kn;
				y--;
			};
			if (y < 0) {
				break;
			};
		}
		for (int x = 0; x < i; x++) {
			if (Num[x] == 0) {
				Num[x] = 1;
			}
			if (Num[x] == 1) {
				Num[x] = 0;
			}
		}
		BinaryNum temp;
		temp.noOfBits = i + 1;
		temp.binNum = new int[i + 1];
		for (int k = 0; k < i + 1; k++) {
			binNum[k] = Num[k];
		}

		return temp;
	}

	int operator [](int i) {
		if (i >= 0 && i < noOfBits) {
			return binNum[i];
		}
	}

	BinaryNum operator++() {
		int q = BintoDe(*this);
		q = q++;
		BinaryNum temp = DetoBin(q);

		return temp;
	}

	BinaryNum operator++(int) {
		int q = BintoDe(*this);
		q = ++q;
		BinaryNum temp = DetoBin(q);

		return temp;
	}

	BinaryNum operator+(const BinaryNum & p) {
		int q = BintoDe(*this);
		int w = BintoDe(p);
		int c = q + w;
		BinaryNum temp = DetoBin(c);

		return temp;
	}

	friend BinaryNum operator+(char* p, BinaryNum i) {
		BinaryNum u(p);
		int q = BintoDe(i);
		int w = BintoDe(u);
		int c = q + w;
		BinaryNum temp = DetoBin(c);

		return temp;
	}

	BinaryNum operator-(const BinaryNum & p) {
		int q = BintoDe(*this);
		int w = BintoDe(p);
		int c = abs(q - w);
		BinaryNum temp = NDetoBin(c);

		return temp;
	}

	bool operator ==(const BinaryNum & p) {
		if (noOfBits == p.noOfBits) {
			bool isEqual = false;
			for (int i = 0; i < noOfBits; i++) {
				if (binNum[i] == p.binNum[i]) {
					isEqual = true;
				}
				else {
					isEqual = false;
				}
			}
			if (isEqual) {
				return true;
			}
			else {
				return false;
			}
		}

	}

	friend istream & operator >> (istream &in, BinaryNum & q) {
		char* temp;
		int size = 18;
		temp = new char[size];
		cout << "Enter Binary number: \n";
		in.getline(temp, size);
		q = BinaryNum(temp);
		delete[] temp;

		return in;
	}

	friend ostream & operator << (ostream &out, const BinaryNum & q) {
		q.Print(out);

		return out;
	}

	void Print(ostream &out) {
		if (binNum != 0) {
			for (int i = 0; i < noOfBits; i++) {
				out << binNum[i];
			}
		}
		out << endl;
	}
	~BinaryNum() {
		if (binNum != 0) {
			delete[] binNum;
			binNum = NULL;
		}
	}
}

int main() {
	BinaryNum b1; //noOfBits = 0, binNum is NULL
	BinaryNum b2("101"); //noOfBits = 3, binNum is {1,0,1}
	BinaryNum b3("1001"); //noOfBits = 4, binNum is {1,0,0,1}
	cout << "b1 = "; cout << b1; //Prints Nothing
	cout << "b2 = "; cout << b2; //Prints 101
	cout << "b3 = "; cout << b3; //Prints 1001
	b1 = b2 + b3;
	cout << "b1 = " << b1; //Prints 1110
	cout << "b1[0] = " << b1[0] << endl; //Prints 1 (0th bit in b1)
	cout << "b1[3] = " << b1[3] << endl; //Prints 0 (3rd bit in b1)
	cout << b3++;
	bool check = (b3 == b2);
	cout << "is equal= " << check << endl; //Prints 0
	cout << ++b3;
	b1 = "111" + b2;
	cout << b1;
	cin >> b2;
	cout << b1 - b2;

	system('pause');

	return 0;
}