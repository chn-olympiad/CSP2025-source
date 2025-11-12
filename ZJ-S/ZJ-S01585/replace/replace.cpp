#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+933,base=233;
struct node{
	int x,y,len;
}s[200005];
int make_hash(string s){
	int sum=0,len=s.size();
	for(int i=0;i<len;i++) sum=(sum*base%mod+s[i])%mod;
	return sum;
}
int hs1[5000005],hs2[5000005],jc[5000005];
int ksm(int a,int b){
	int s=1;
	while(b){
		if(b&1) s=s*a%mod;
		b>>=1,a=a*a%mod;
	}
	return s;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		s[i].x=make_hash(s1),s[i].y=make_hash(s2),s[i].len=s1.size();
	}
	jc[0]=1;
	for(int i=1;i<=5000000;i++) jc[i]=jc[i-1]*base%mod;
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		hs1[0]=t1[0],hs2[0]=t2[0];
		int len1=t1.size(),len2=t2.size(),ans=0;
		for(int i=1;i<len1;i++) hs1[i]=(hs1[i-1]*base%mod+t1[i])%mod;
		for(int i=1;i<len2;i++) hs2[i]=(hs2[i-1]*base%mod+t2[i])%mod;
		int sum1=hs1[len1-1],sum2=hs2[len2-1];
		for(int i=1;i<=n;i++){
			for(int j=0;j<=len1-s[i].len;j++){
				if((hs1[j+s[i].len-1]-(j==0?0:hs1[j-1]*jc[s[i].len]%mod)+mod)%mod==s[i].x){
					int now=(s[i].y-s[i].x+mod)%mod;
					if((sum1+now*jc[len1-s[i].len-j]%mod)%mod==sum2) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
