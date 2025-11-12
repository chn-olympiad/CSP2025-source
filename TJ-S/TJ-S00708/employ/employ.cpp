#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	int n,m;cin >> n >> m;
	string s;cin >> s;
	int h[n];
	int zong=1,p=1;
	for (int i=0;i<n;i++){
		cin >> h[i];
		zong=(zong*p)%998244353;
		p+=1;
	}
	cout << zong;
	return 0;
}
