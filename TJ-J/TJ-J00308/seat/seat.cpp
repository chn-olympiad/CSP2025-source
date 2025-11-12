#include <bits/stdc++.h>

using namespace std;

int n, m, r;
const int N = 109;

struct people{
	int n, m;
	int grade;
	bool operator <(const people &A) const{
		return grade > A.grade;
	}
}v[N];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0;i < n*m;i++){
		cin >> v[i].grade;
		if (i == 0) r = v[i].grade;
	}
	sort(v, v+n*m);
	
	for (int i = 0;i < n*m;i++){
		v[i].m = i/n+1;
		if (v[i].m % 2 == 1) v[i].n = (i%n)+1;
		else v[i].n = n+1-((i%n)+1);
		
		if (v[i].grade == r) cout << v[i].m << " " << v[i].n;
	}
	
	return 0;
}
