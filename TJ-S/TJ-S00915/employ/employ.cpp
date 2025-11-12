#include<bits/stdc++.h>
using namespace std;
int n,m,p[1000];
string d;
long long ans=1,k=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>d;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=k; 
	}
	cout<<ans;
	return 0;
} 
