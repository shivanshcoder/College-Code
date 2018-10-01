#include<iostream>

using namespace std;
int q = 22;
int p = 10;

int main() {
	int arr[p][q] = { 0 };
	for (int i = 0; i < q; ++i) {
		for (int j = 0; j < p; ++j) {
			cout << arr[j][i] << "\t";
		}
		cout << "\n";
	}
	return 0;
}