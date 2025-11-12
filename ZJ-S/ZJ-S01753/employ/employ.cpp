#include<bits/stdc++.h>
using namespace std;
int s[505],c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string k;
	cin>>k;
	for(int i=0;i<n;i++)s[i+1]=k[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+1+n);
	if(m==n){
		int f=1;
		for(int i=1;i<=n;i++){
			if(s[i]==0){
				f=0;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				f=0;
				break;
			}
		}
		if(f){
			long long ans=1;
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=998244353;
			}
			cout<<ans<<endl; 
		}else cout<<0<<endl;
		return 0;
	}
} 
