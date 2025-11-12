#include<bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
int read(){
	int ans=0,j=1;
	char c=getchar();
	while(c>'9' or c<'0'){
		if(c=='-')
			j=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		ans=(ans<<3)+(ans<<1)+(c^48);
		c=getchar();
	}
	return ans*j;
}
void write(int x){
	if(x<0)
		putchar('-'),
		x=-x;
	if(x>9)
		write(x/10);
	putchar('0'+x%10);
}
string READ(){
	char c=getchar();
	while(c>'z' or c<'a')
		c=getchar();
	string ret="";
	while(c>='a' and c<='z')
		ret+=c,
		c=getchar();
	return ret;
}
const int N=1e6+5,CCF=1337,MOD=998244353;
int n,q,val1[N],val2[N],val[N],tq[N];
string s1[N],s2[N],t1[N],t2[N];
unordered_map<int,int> mp,ttt;
int ksm(int a,int b,int p){
	int ret=1;
	while(b){
		if(b&1)
			ret*=a,
			ret%=p;
		a*=a,
		a%=p;
		b>>=1;
	}
	return ret;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	tq[0]=1;
	for(int i=1;i<=1e6;++i)
		tq[i]=tq[i-1]*CCF%MOD;
	for(int i=1;i<=n;++i){
		s1[i]=READ(),s2[i]=READ();
		for(int j=0;j<s1[i].size();++j)
			s1[i][j]-='a'-1,val1[i]*=CCF,val1[i]+=s1[i][j]*s1[i][j],val1[i]%=MOD;
		for(int j=0;j<s2[i].size();++j)
			s2[i][j]-='a'-1,val2[i]*=CCF,val2[i]+=s2[i][j]*s2[i][j],val2[i]%=MOD;
		val[i]=val2[i]-val1[i];
		val[i]=((val[i]%MOD)+MOD)%MOD;
		if(q>1){
			for(int j=0;j<=2000;++j)
				++mp[(val[i]*tq[j])%MOD];
		}
		else
			++ttt[val[i]];
	}
	int ny=ksm(CCF,MOD-2,MOD);
	for(int i=1;i<=q;++i){
		string a=READ(),b=READ();
		int vala=0,valb=0;
		for(int j=0;j<a.size();++j)
			a[j]-='a'-1,vala*=CCF,vala+=a[j]*a[j],vala%=MOD;
		for(int j=0;j<b.size();++j)
			b[j]-='a'-1,valb*=CCF,valb+=b[j]*b[j],valb%=MOD;
		int val=valb-vala;
		val=((val%MOD)+MOD)%MOD;
		if(q==1){
			int ans=0;
			for(int i=1;i<=1e6;++i){
				ans+=ttt[val];
				val=(ll)val*ny%MOD;
			}
			write(ans);
			return 0;
		}
		else write(mp[val]);
		putchar(10);
	}
	return 0;
}