#include <bits/stdc++.h>
using namespace std;

struct A {
	int z;
	int o;
} stu[10005];
int o;

bool camp(A a, A b) {
	return a > b;
}

int main() {
	cin >> stu[1].z;
	cin >> stu[2].z;
	sort(stu + 1, stu + 3, camp);
	stu[1].o = 3;
	stu[2].o = 4;
	cout << stu[1].o << " " << stu[2].o;
	return 0;
}