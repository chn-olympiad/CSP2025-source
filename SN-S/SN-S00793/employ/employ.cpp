#include<bits/stdc++.h>
using namespace std;
int n,m,b[114514];
string a;
long long ans=1;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
 	cin>>n>>m>>a;
 	for(int i=0;i<n;i++) cin>>b[i];
 	for(int i=n;i>0;i--){
 		ans*=i;
		ans=ans%998244353;	
	}
 	cout<<ans;
	return 0;
}

