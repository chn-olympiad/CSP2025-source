#include<bits/stdc++.h>
using namespace std;
bool used[510];
int sum = 0 , len , a[510];
int n , m;
string s;

int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m;
	cin >> s;
	len = s.size();
	s = ' ' + s;
	for(int i = 1; i <= len; i++) if(s[i] == '1') sum++;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(sum < m){
		cout << 0;
		return 0;
	}else{
		cout << 1;
		return 0;
	}
	return 0;
}