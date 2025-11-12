#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],a[505];
int p[505];
long long ans=1;
bool P=1;
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
//	s[0]='1';
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+(s[i-1]=='1');
	}
	for(int i=1;i<=n;i++){
		a[i]=i-a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]!=1) P=0;
		p[c[i]]++;
	}
	if(P){
		if(a[n]!=n){
			cout<<0<<endl;
			return 0;
		}else{
			for(int i=1;i<=n;i++) ans=(ans*i)%mod;
			cout<<ans;
		}
		return 0;
	}
	if(m==n){
		for(int i=1;i<n;i++) ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	for(int i=500;i>=0;i--){
		p[i]+=p[i+1];
	}
	for(int i=n,t=0;i>0;i--,t++){
	//	cout<<a[i]<<" "<<p[a[i]]<<" "<<t<<endl;
		//if(p[a[i]]==t) continue;
		ans=(ans*max(1,(p[a[i]]-t)%mod))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
