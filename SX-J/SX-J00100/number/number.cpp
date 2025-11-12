#include<bits/stdc++.h>
using namespace std;

const int SIZE = 1e6;

string s;
long long n;
vector<int> nm(SIZE);

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	int a = 0;
	for(int i = 0; i <= s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			nm[a] = s[i] - '0';
			a++;
		}
	}

	sort(nm.begin(), nm.end(), cmp);

	for(int i = 0; i < a; i++){
		n = n * 10 + nm[i];
	}

	cout << n;
	return 0;
}