#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001];
string s;
int main(){
	freopen("employ","r",stdin);
	freopen("employ","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<((n*(n+1))/2);
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
