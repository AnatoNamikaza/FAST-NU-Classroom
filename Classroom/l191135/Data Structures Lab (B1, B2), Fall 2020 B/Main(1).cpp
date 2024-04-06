#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

struct  Employee {

	int ID;
	std::string Name;
	float Salary;

	Employee() { this->ID = 0, this->Salary = 0; this->Name = "\0"; }

	Employee(int id, std::string& pname, float pay) { this->ID = id; this->Salary = pay; this->Name = pname; }

	friend std::ostream& operator << (std::ostream& ou, const Employee& worker) {
		ou  << "Employee ID: " << worker.ID << "__Name: " << worker.Name << "__Salary: " << worker.Salary << "\n";
		return ou;
	}

	void print() {	std::cout << "Employee ID: " << ID << "__Name: " << Name << "__Salary: " << Salary << "\n";}

	void copy(const Employee& worker) { this->ID = worker.ID; this->Salary = worker.Salary; this->Name = worker.Name; }

	~Employee() { this->ID = 0, this->Salary = 0; this->Name = "\0"; }
};

void Hswap(std::vector<Employee>& data, int index1, int index2) {
	Employee temp(data[index1]);
	data[index1].copy(data[index2]);
	data[index2].copy(temp);
}

void BHeapify(std::vector<Employee>& data, int size, int index) {
	int Largest = index, LNode = ((index * 2) + 1), RNode = ((index * 2) + 2);
	int LGid = data[Largest].ID, Rid = -1, Lid = -1;
	if (RNode < size) { Rid = data[RNode].ID; }
	if (LNode < size) { Lid = data[LNode].ID; }
	if (LNode < size && Lid != -1 && Lid >= LGid) {
		Largest = LNode;
		LGid = data[Largest].ID;
	}
	if (RNode < size &&Rid != -1 && Rid >= LGid) {
		Largest = RNode;
		LGid = data[Largest].ID;
	}

	if (Largest != index) {
		Hswap(data, index, Largest);
		BHeapify(data, size, Largest);
	}
}

void BuildHeap(std::vector<Employee>& data, int size) {
	for (int i = ((size / 2) - 1); i >= 0; i--) 
		BHeapify(data, size, i);
}

void readEmployees(std::string const filename, std::vector<Employee> & empVector, int &size) {
	std::ifstream fin(filename);
	if (fin) {
		int n = 0, id = 0; float salary = 0; std::string name;
		fin >> n;
		size = n;
		for (int i = 0; i < n; i++) {
			fin.ignore(1, '\n');
			fin >> id;
			fin.ignore(1, '\n');
			std::getline(fin, name, '\n');
			fin >> salary;
			Employee e1(id, name, salary);
			empVector.push_back(e1);
		}
	}
	else { std::cout << "File is not accessable.\n"; }
}

void HeapSort(std::vector<Employee>& data, int size) {
	for (int i = size / 2 - 1; i >= 0; i--)
		BHeapify(data, size, i);

	for (int i = size - 1; i >= 0; i--)
		Hswap(data, 0, i), BHeapify(data, i, 0);
}

void heapify(int arr[], int n, int i) {
	int largest = i, l = 2 * i + 1, r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest]) { largest = l; }
	if (r < n && arr[r] > arr[largest]) { largest = r; }
	if (largest != i) { std::swap(arr[i], arr[largest]), heapify(arr, n, largest); }
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) { heapify(arr, n, i); }
	for (int i = n - 1; i >= 0; i--) { std::swap(arr[0], arr[i]), heapify(arr, i, 0); }
}

bool IsMaxHeap(int arr[], int n) {
	for (int i = ((n / 2) - 1); i >= 0; i--) {
		int Largest = i, LNode = ((i * 2) + 1), RNode = ((i * 2) + 2);
		if (LNode < n &&  arr[LNode] >= arr[Largest]) { return false; }
		if (RNode < n && arr[RNode] >= arr[Largest]) { return false; }
	}
	return true;
}

void mheapify(int arr[], int n, int i) {
	int largest = i, l = 2 * i + 1, r = 2 * i + 2;
	if (l < n && arr[l] < arr[largest]) { largest = l; }
	if (r < n && arr[r] < arr[largest]) { largest = r; }
	if (largest != i) { std::swap(arr[i], arr[largest]), mheapify(arr, n, largest); }
}

void mheapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) { mheapify(arr, n, i); }
	for (int i = n - 1; i >= 0; i--) { std::swap(arr[0], arr[i]), mheapify(arr, i, 0); }
}

void sheapify(int arr[], int n, int i) {
	int l = 2 * i + 1, r = 2 * i + 2, m = i;
	if (l < n && arr[i] < arr[l]) { m = l; }
	if (r < n && arr[m] < arr[r]) { m = r; }
	if (m != i) { std::swap(arr[m], arr[i]), sheapify(arr, n, m); }
}

int extractMax(int arr[], int n) {
	if (n == 0) { return -1; }
	int m = arr[0]; arr[0] = arr[n - 1];	sheapify(arr, n, 0);
	return m;
}

int kThGreatest(int arr[], int n, int k) {
	for (int i = 1; i < k; ++i) { extractMax(arr, n); }
	return extractMax(arr, n);
}

int main() {
	int Arr1[] = { 100, 19, 36, 17, 3, 25, 1, 2, 7 };
	int Arr2[] = { 100, 19, 36, 17, 3, 25, 1, 2, 25 };
	int Arr3[] = { 20, 18, 10, 12, 9, 9, 3, 5 ,6 ,8 };
	std::vector<Employee> v1; int size;
	readEmployees("EmployeeList.txt", v1, size);
	std::cout << "\n================ Data in file now ================\n";
	for (int i = 0; i < v1.size(); i++)	std::cout << v1[i];
	std::cout << "\n================ Data in Max heap ================\n";
	BuildHeap(v1, size);
	for (int i = 0; i < v1.size(); i++)	 v1[i].print();
	std::cout << "\n================ Data in Min heap ================\n";
	HeapSort(v1, size);
	std::vector<Employee>::iterator SN;
	for (SN = v1.begin(); SN != v1.end(); ++SN)	 SN->print();
	std::cout << "-----------------------------------------------------------------------\n";
	heapSort(Arr3, 10);
	for (int i = 0; i < 10; i++)std::cout << " " << Arr3[i];
	std::cout << "\n-----------------------------------------------------------------------\n";
	if (!IsMaxHeap(Arr1, 9)) { std::cout << "Arr1 is not a Max heap.\n"; }
	else { std::cout << "Arr1 is a Max heap.\n"; }
	std::cout << "-----------------------------------------------------------------------\n";
	if (!IsMaxHeap(Arr2, 9)) { std::cout << "Arr2 is not a Max heap.\n"; }
	else { std::cout << "Arr2 is a Max heap.\n"; }
	std::cout << "-----------------------------------------------------------------------\n";
	mheapSort(Arr3, 10);
	for (int i = 0; i < 10; i++)std::cout << " " << Arr3[i];
	std::cout << "\n-----------------------------------------------------------------------\n";
	int Arr4[] = { 100, 19, 36, 17, 3, 25, 1, 2, 7 };
	std::cout << "Requested Index's value is: " << kThGreatest(Arr4, 9, 5);
	std::cout << "\n-----------------------------------------------------------------------\n";

	return 0;
}