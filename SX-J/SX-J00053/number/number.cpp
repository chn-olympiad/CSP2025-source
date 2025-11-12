#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define dbug(x) (void)(cerr << #x << " = " << x << endl)

inline bool cmp(char a, char b){
	return a > b;
}

int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out", "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	string s , t = "";
	cin >> s;
	for(ll i = 0;i < s.size();i++){
		if(isdigit(s[i])){
			t.push_back(s[i]);
		}
	}
	stable_sort(t.begin() , t.end() , cmp);
	cout << t;


	return 0;
}
