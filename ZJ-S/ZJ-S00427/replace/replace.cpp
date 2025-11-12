#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5,P=998244353,base=31,num=2;long long n,q,a[N],b[N],f[M][2],pw[M],fg=0,len[N],ans=0;string x,y;
long long get(int l,int r,int flag){return ((f[r][flag]-f[l-1][flag]*pw[r-l+1]%P)%P+P)%P;}
int main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>q;for(int i=1;i<=n;i++){cin>>x;len[i]=x.size();for(int j=0;j<x.size();j++) a[i]=(a[i]*base%P+x[j]-'a'+1)%P;cin>>x;for(int j=0;j<x.size();j++) b[i]=(b[i]*base%P+x[j]-'a'+1)%P;}
	if(q==1) fg=1;
	pw[0]=1;for(int i=1;i<=5e6;i++) pw[i]=pw[i-1]*base%P;
	while(q--){
		cin>>x>>y;for(int i=0;i<x.size();i++) f[i+1][0]=(f[i][0]*base%P+x[i]-'a'+1)%P,f[i+1][1]=(f[i][1]*base%P+y[i]-'a'+1)%P;ans=0;
//		if(fg==1){
			int l=1,r=x.size();while(l<=r&&x[l-1]==y[l-1]) l++;while(r>=l&&x[r-1]==y[r-1]) r--;//cout<<l<<" "<<r<<"\n";
			for(int i=1;i<=n;i++){int flag=0;for(int j=1;j<=len[i];j++) if(j<=l&&l-j+len[i]>=r&&l-j+len[i]<=x.size()) flag|=(get(l-j+1,l-j+len[i],0)==a[i]&&get(l-j+1,l-j+len[i],1)==b[i])/*,cout<<i<<" "<<j<<":"<<flag<<"\n"*/;ans+=flag;}
			cout<<ans<<"\n";
//		}
//		for(int j=1;)
	}
	return 0;
}
