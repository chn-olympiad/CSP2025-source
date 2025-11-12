#include<bits/stdc++.h>
#define int long long
#define mp make_pair 
#define fi first
#define se second
#define fr front
#define pii pair<int,int>
#define v 5000000
using namespace std;

int n,q,b[5000005];
int mod1=998244353,mod2=1000000007,base=131;
map<pii,int> p;

struct makehash{
	int h1[5000005];
	void mhash(string s,string t){
		int n=s.length(),m=t.length();
		int p1=0,num1=0;
		for(int i=1;i<=n;i++){
			num1=(num1*base%mod1+s[i-1])%mod1;
		}
		for(int i=1;i<=m;i++){
			p1=(p1*base%mod1+t[i-1])%mod1;
		}
		p[mp(num1,p1)]++;
	}
	void lhash(string s){
		int n=s.length();
		for(int i=1;i<=n;i++){
			h1[i]=(h1[i-1]*base%mod1+s[i-1])%mod1;
		}
	}
	int get_hash(int l,int r){
		return (h1[r]-h1[l-1]*b[r-l+1]%mod1+mod1)%mod1; 
	}
}hs1,hs2;

signed main(){
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t;cin>>s>>t;
		hs1.mhash(s,t);
	}
	b[0]=1;
	for(int i=1;i<=v;i++){
		b[i]=b[i-1]*base%mod1;
	}
	for(int i=1;i<=q;i++){
		string s,t;cin>>s>>t;
		int m=s.length();
		hs1.lhash(s);hs2.lhash(t);
		int ans=0;
		int pos1=0,pos2=0;
		for(int j=m-1;j>=0;j--){
			if(s[j]!=t[j]){pos1=j+1;break;}
		}
		for(int j=0;j<=m;j++){
			if(s[j]!=t[j]){pos2=j+1;break;}
		}
		if(pos1<pos2)pos1=1,pos2=m;
		for(int j=1;j<=pos2;j++){
			for(int k=pos1;k<=m;k++){
				if(j>k)continue;
				int num1=hs1.get_hash(j,k);
				int num2=hs2.get_hash(j,k);
				//cout<<j<<" "<<k<<" "<<num1<<" "<<num2<<"\n";
				ans+=p[mp(num1,num2)];
			}
		}
		cout<<ans<<"\n";
	}
}
/*
我们需要找到l,r，使得这中间包含了所有不同字母
我们可以枚举右端点，然后减掉两个hash值
这样就得到了中间那一段相减的值



*/
