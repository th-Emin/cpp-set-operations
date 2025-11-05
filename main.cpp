// This program is written for Istanbul University MAHT2162 Discrete Mathematics Assginment.
// It perform some set operations using set membership logic.

// C++23 Standard: Use the standard library module
import std;

// Headers for previous C++ standards
//#include <iostream>
//#include <stdexcept>

using namespace std;

struct Set {
	bool* members;
	unsigned size;
	int* U;
	unsigned U_size;
	Set(int m[], unsigned size, Set& nU) : U(nU.U), U_size(nU.U_size), size(size) {
		members = new bool[U_size]();
		for (unsigned i = 0; i < size; i++) {
			for (unsigned j = 0; j < U_size; j++) {
				if (m[i] == U[j]) {
					members[j] = true;
					break;
				}
			}
		}
	}
	Set(bool members[], unsigned size, int* U, unsigned U_size) : U(U), U_size(U_size), members(members), size(size) {} 
	Set(int U[], unsigned U_size) : U(U), U_size(U_size), members(new bool[U_size]), size(U_size) {
		for (unsigned i = 0; i < U_size; i++) members[i] = true;
	}
	~Set() { delete[] members; }
};

// Intersection
Set operator&(const Set& A, const Set& B) {
	if (A.U != B.U) throw runtime_error("not same U");
	bool* m = new bool[A.U_size]();
	unsigned size = 0;
	for (unsigned i = 0; i < A.U_size; i++) {
		if (A.members[i] && B.members[i]) {
			m[i] = true;
			size++;
		}
	}
	Set result(m, size, A.U, A.U_size);
	return result;
}

// Union
Set operator|(const Set& A, const Set& B) {
	if (A.U != B.U) throw runtime_error("not same U");
	bool* m = new bool[A.U_size]();
	unsigned size = 0;
	for (unsigned i = 0; i < A.U_size; i++) {
		if (A.members[i] || B.members[i]) {
			m[i] = true;
			size++;
		}
	}
	Set result(m, size, A.U, A.U_size);
	return result;
}

// Complement
Set operator!(const Set& A) {
	bool* m = new bool[A.U_size]();
	unsigned size = 0;
	for (unsigned i = 0; i < A.U_size; i++) {
		if (!A.members[i]) {
			m[i] = true;
			size++;
		}
	}
	Set result(m, size, A.U, A.U_size);
	return result;
}

// Difference
Set operator-(const Set& A, const Set& B) {
	if (A.U != B.U) throw runtime_error("not same U");
	bool* m = new bool[A.U_size]();
	unsigned size = 0;
	for (unsigned i = 0; i < A.U_size; i++) {
		if (A.members[i] && !B.members[i]) {
			m[i] = true;
			size++;
		}
	}
	Set result(m, size, A.U, A.U_size);
	return result;
}

void display(const Set &A) {
	cout << "{ ";
	for (unsigned i = 0; i < A.U_size; i++) {
		if (A.members[i]) cout << A.U[i] << " ";
	}
	cout << "}" << endl;
}

int main() {
	cout << "This program is written for Istanbul University MAHT2162 Discrete Mathematics Assginment." << endl;
	cout << "It perform some set operations using set membership logic.\n" << endl;

	cout << "Example: " << endl;
	int U_m[] = { -9, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 55 };
	Set U(U_m, sizeof(U_m) / sizeof(U_m[0]));
	cout << "Universial Set: ";
	display(U);

	int A_m[] = { 0, 1, 4, 5 };
	Set A(A_m, 4, U);
	cout << "Set A: ";
	display(A);

	int B_m[] = { 0, 1, 2, 3, 5 };
	Set B(B_m, 5, U);
	cout << "Set B: ";
	display(B);

	cout << "Union of A and B (AuB): ";
	display(A | B);

	cout << "Intersection of A and B (AnB): ";
	display(A & B);

	cout << "Complement of A (A'): ";
	display(!A);

	cout << "Difference of A and B (A\\B): ";
	display(A - B);

	cout << "U \\ (A'nB'): ";
	display(U - (!A & !B));
	return 0;
}
