#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[i]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		ans*=(n-i);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
