#include <iostream>
using namespace std;

template <typename T>
T average(T const* t, int n) {
	T s = t[n - 1];
	for (int i = 0; i < (n-1); i++) {
		s += t[i];
	}

	int k=s / n;
	return k;
}

template <typename T>
T Sort(T const* t, int n) {
	T *s;
	int i,j;
	for (i = 0; i < n; i++) {
		for(j=i+1;j<n;j++){
			if(*t[j]<*t[i]){
				s=t[i];
				t[i]=t[j];
				t[j]=s;
			}
		}
	}
	for (int k = 0; k < n; k++) {
		cout << t[k];
	}
	cout<<endl;
}

template <typename T>
T Max(T const* t, int n) {
	T Max = t[n - 1];
	for (int i = 0; i < (n-1); i++) {
		if(Max < t[i]) {
			Max=t[i];
		}
	}

	return Max;
}

template <typename T>
T CommonElements(T const* t, T const* t2) {
	int siz1=0;
	int siz2=0;

	for(int i=0;t[i]!='\0';i++){
		siz1++;
	}

	for(int i=0;t2[i]!='\0';i++){
		siz2++;
	}

	for (int i = 0; i < siz1; i++) {
		for (int j = 0; j < siz2; j++) {
			if (t[i] == t2[j])	{
				cout<<t[i]<<endl;
			}
		}
	}
}

template <typename T>
T Print(T const* t= nullptr, T const** t2= nullptr) {
	if (t != nullptr) {
		int siz1 = 0;

		for (int i = 0; t[i] != '\0'; i++) {
			siz1++;
		}

		for (int i = 0; i < siz1; i++) {
			cout << t[i];
		}
		cout<<endl;
	}
//	if (t2 != nullptr) {
//		int siz1 = 0;
//		for (int i = 0; t[i] != '\0'; i++) {
//			siz1++;
//		}
//
//		int i = 0;
//		for (; i < siz1; i++) {
//			int siz2 = 0;
//			for (int j = 0; t[i][j] != nullptr; j++) {
//				siz1++;
//			}
//
//			for (int j = 0; j < siz2; j++) {
//				cout << t[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
}


int main() {

	const int a[]={1,2,3,6,5};
	const int a2[]={1,9,3,11,5};
	const char a3[]="gsadk";

	int v=average(a,5);
	cout<<v<<endl;

	v=Max(a2,5);
	cout<<v<<endl;

	CommonElements(a,a2);

	Print(a3);

	return 0;
}
