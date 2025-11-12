#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;
const ll mod1=1e9+7,mod2=998244353;
int n,q;
map<ll,ll>mp1,mp2;
struct hash{
	ll pw1[N],h1[N],sed;
	string s;
	void make1(){
		pw1[0]=h1[0]=1,sed=150ll;
		for(int i=1;i<=s.size();i++) pw1[i]=pw1[i-1]*sed%mod1;
		for(int i=1;i<=s.size();i++) h1[i]=(h1[i-1]*sed+s[i-1])%mod1;
	}
	ll query1(int l,int r){
		if(l>r) return -1;
		return ((h1[r]-h1[l-1]*pw1[r-l+1])%mod1+mod1)%mod1;
	}
	ll pw2[N],h2[N];
	void make2(){
		pw2[0]=h2[0]=1,sed=150ll;
		for(int i=1;i<=s.size();i++) pw2[i]=pw2[i-1]*sed%mod2;
		for(int i=1;i<=s.size();i++) h2[i]=(h2[i-1]*sed+s[i-1])%mod2;
	}
	ll query2(int l,int r){
		if(l>r) return -1;
		return ((h2[r]-h2[l-1]*pw2[r-l+1])%mod2+mod2)%mod2;
	}
}a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a.s>>b.s;
		a.make1(),b.make1();
		a.make2(),b.make2();
		mp1[a.query1(1,a.s.size())]=b.query1(1,b.s.size());
		mp2[a.query2(1,a.s.size())]=b.query2(1,b.s.size());
	}
	while(q--){
		hash d,k;
		cin>>d.s>>k.s;
		if(d.s.size()!=k.s.size()){
			printf("0\n");
			continue;
		}
		d.make1(),k.make1();
		d.make2(),k.make2();
		int sum=0,nn=k.s.size();
		for(int i=0;i<=nn;i++){
			if(d.query1(1,i)!=k.query1(1,i)||d.query2(1,i)!=k.query2(1,i)) break;
			for(int j=nn+1;j>=1;j--){
				if(d.query1(j,nn)!=k.query1(j,nn)||d.query2(j,nn)!=k.query2(j,nn)) break;
				if(mp1[d.query1(i+1,j-1)]==k.query1(i+1,j-1)&&mp2[d.query2(i+1,j-1)]==k.query2(i+1,j-1)) sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
