#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
int T,a[maxn],b[maxn],c[maxn];
long long f[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int n;
		long long ans=0;
		cin>>n;
		bool fa=0,fb=0,fc=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i])fb=1;
			if(a[i])fa=1;
			if(c[i])fc=1;
			ans+=a[i]+b[i];
		}
		if(!fa&&!fb&&!fc)cout<<"0"<<'\n';
		else if(!fc&&fa&&fb){
			cout<<ans<<'\n';
		}
		else {
			for(int i=1;i<=n;i++){
				for(int j=n/2;j>=1;j--){
					f[j]=max(f[j],f[j-1]+max({a[i],b[i],c[i]}));
				} 
			}
			cout<<f[n/2]<<'\n';
		}
		
	}
	return 0;
}
