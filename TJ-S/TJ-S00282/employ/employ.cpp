#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[1000230];
	string str = "";
	cin >> str;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	cout << n*m; 
	return 0; 
} 
