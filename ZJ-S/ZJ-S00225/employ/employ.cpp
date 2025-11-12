#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,flgA=1,flgB,ans;
bitset<505> bt;

int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

struct Node{
	int rk,re;
	bool operator<(const Node b)const{return rk<b.rk;}
}slt[505];

int check(){
	int lst=0,cnt=0;
	for(int i=1;i<=n;i++){
		if((!bt[i])||lst>=slt[i].re) lst++;
		else cnt++;
		if(cnt>=m) return cnt;
	}
	return cnt;
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
    	char ch=getchar();
    	while(!isdigit(ch)) ch=getchar();
    	bt[i]=ch-'0';
    	flgA&=bt[i];
    	flgB+=bt[i];
	}
	for(int i=1;i<=n;i++) slt[i]={i,read()};
	if(flgA){
		ans=1;
		for(int i=1;i<=n;i++) (ans*=i)%=mod;
		cout<<ans<<endl;
		return 0;
	}
	if(m>flgB){
		cout<<0<<endl;
		return 0;
	}
	do{
		ans+=(check()>=m);
	}while(next_permutation(slt+1,slt+1+n));
	cout<<ans%mod;
    return 0;
}