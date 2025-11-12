#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353,N=5e6+10;
int n,Q,q,cn,l1,l2,t,w,x,y,s,ans,ma,i,p[N],j,a[N],b[N],c[N],d[N];
char s1[N],s2[N];
map<int,int> f;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(i=1;i<=n;i++){
		cin>>s1+1>>s2+1;
		l1=strlen(s1+1);l2=strlen(s2+1);
		s=0;
		for(j=1;j<=l1;j++)
			s=(s*100+s1[j]-96)%mod;
		q=s;
		s=0;
		for(j=1;j<=l1;j++)
			s=(s*100+s2[j]-96)%mod;
		cn=s;
		f[q]=cn;
		ma=max(ma,l1);
//		cout<<q<<"  "<<cn<<"\n";
	}
	while(Q--){
		cin>>s1+1>>s2+1;ans=0;
		l1=strlen(s1+1);l2=strlen(s2+1);
		p[0]=1;
		for(j=1;j<=l1;j++)
			a[j]=(a[j-1]*100+s1[j]-96)%mod,
			p[j]=p[j-1]*100%mod;
		for(j=l1;j>=1;j--)
			b[j]=(b[j+1]*100+s1[j]-96)%mod;
		for(j=1;j<=l2;j++)
			c[j]=(c[j-1]*100+s2[j]-96)%mod;
		for(j=l2;j>=1;j--)
			d[j]=(d[j+1]*100+s2[j]-96)%mod;
		for(i=1;i<=min(l1,l2);i++)
			if(a[i]!=c[i])break;
		t=i;
		for(i=1;i<=min(l1,l2);i++)
			if(b[l1-i+1]!=d[l2-i+1])break;
		w=l1-i+1;
//		cout<<t<<" "<<w<<"\n";
		for(i=t;i>=max(1ll,w-ma+1);i--)
			for(j=w;j<=min(l1,l2);j++)
				if(j-i+1>ma)break;
				else{
					x=(a[j]-a[i-1]*p[j-i+1]%mod+mod)%mod;
					if(f[x]!=0){
						y=(c[l2-l1+j]-c[i-1]*p[l2-l1+j-i+1]%mod
						+mod)%mod;
//						cout<<i<<" "<<j<<" "<<x<<" "<<y<<"\n";
						if(f[x]==y)ans++;
					}
				}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/
