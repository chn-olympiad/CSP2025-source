#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int base=29,h[201010],N=200010,mod=1e9+7;
int n,m,q,len;
int qpow(int x,int q){
	int res=1;
	while(q){
		if(q&1)res=(ll)(res*x)%mod;
		q>>=1;
		x=(ll)(x*x)%mod;
	}return res;
}
int get(int H[],int l,int r){
	return (ll)(H[r]-H[l-1])*qpow(h[l],mod-2)%mod;
}
struct ill{
	string s1,s2,g1,g2;
	int l,r,len;
}qw[201010];
string s[101010][2],s1,s2;
void T2(){
	while(q--){
		cin>>s1>>s2;
		ll ans=0;
		len=s1.length();
		int l=0,r=len-1;
		while(l<len&&s1[l]==s2[l])l++;
		while(r&&s1[r]==s2[r])r--;
		string str1=s1.substr(l,r-l+1),str2=s2.substr(l,r-l+1);
		for(int i=1;i<=n;i++){
			if(str1==qw[i].g1&&str2==qw[i].g2){
				int f=1;
				for(int j=l-1,k=qw[i].l-1;k>=0;j--,k--){
					if(j<0){
						f=0;break;
					}
					if(qw[i].s1[k]!=s1[j]||qw[i].s2[k]!=s2[j]){
						f=0;break;
					}
				}
				for(int j=r+1,k=qw[i].r+1;k<qw[i].len;j++,k++){
					if(j>=len){
						f=0;
						break;
					}
					if(qw[i].s1[k]!=s1[j]||qw[i].s2[k]!=s2[j]){
						f=0;break;
					}
				}
				ans+=f;
			}
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	h[0]=1;
//	for(int i=1;i<=N;i++)h[i]=(ll)h[i-1]*base%mod;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>qw[i].s1>>qw[i].s2;
		int l=0,r=qw[i].s1.length();
		qw[i].len=qw[i].s1.length();
		while(r&&qw[i].s1[r]==qw[i].s2[r])r--;
		while(l<=r&&qw[i].s1[l]==qw[i].s2[l])l++;
		if(l<=r)qw[i].g1=qw[i].s1.substr(l,r-l+1);
		if(l<=r)qw[i].g2=qw[i].s2.substr(l,r-l+1);
		qw[i].l=l,qw[i].r=r;
	}
//	if(q==1){
//		T1();
//	}
    T2();
	
	return 0;
}

