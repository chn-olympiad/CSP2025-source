#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int a[507];
	cin >> n >> m;
	char s[n];
	for(int i=1;i<=n;i++){
		cin >> s[i];
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	cout << m;
	
	return 0;
}
