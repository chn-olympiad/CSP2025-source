#include<bits/stdc++.h>
using namespace std;
int n,m,s[100005],c[100005]; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=m;i++){
		int t;
	   cin>>t;	
	   sum=t%998244353;
	}
cout<<sum;
	return 0;
}
