#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans,mm=998244353;
char a[510],b[510];
int c[510];
int main(){
	
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	cin>>b;
		ans=1;
	for(int i=1;i<=m;i++)ans=ans*(n-i+1)%mm;
	cout<<ans<<endl;
 
} 

