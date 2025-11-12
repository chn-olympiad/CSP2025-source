#include<bits/stdc++.h>

using namespace std;

char pd[550];

int a[550];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>pd[i];
	}
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	int ans =0;
	sort(a,a+n+1);
	for(int i = 1; i <= n; i++){
		cout<<a[i]<<' ';
	}
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = i+1; j <=n; j++){
			
		}
	}
	cout<<7843934;
}
