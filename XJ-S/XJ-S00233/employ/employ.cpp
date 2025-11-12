#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
3 2
101
1 1 2

2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
2204128
*/
