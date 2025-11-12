bool M1;
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<random>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<cassert>

#define ll long long
#define inf ((ll)1e18)
#define pc putchar
#define pb push_back
#define mid ((l+r)>>1)
#define lowbit(x) ((x)&(-(x)))
#define pir pair<int,int>
#define plr pair<ll,ll>
#define fi first
#define se second

using namespace std;

ll read(){
	ll w,f=1;char c;
	while((c=getchar())>'9'||c<'0')
		if(c=='-')f=-1;
	w=c-'0';
	while((c=getchar())>='0'&&c<='9')
		w=w*10+c-'0';
	return w*f;
}

signed NEV[102],NE;

void print(ll x){
	if(x<0)
		pc('-'),x=-x;
	if(x==0)
		pc('0');
	while(x)
		NEV[++NE]=x%10,x/=10;
	while(NE)
		pc(NEV[NE--]+'0');
}

const int N=1e7+3;

struct AC{
	struct node{
		int s[26];
		int fa[24];
		int dep,sum;
	}t[N];
	int idx;
	void insert(char *s,int n){
		int u=0;
		for(int i=1;i<=n;i++){
			int nw=s[i]-'a';
			if(!t[u].s[nw]){
				t[u].s[nw]=++idx;
				t[idx].dep=i;
//				assert(idx<N);
			}
//			cout<<u<<" "<<t[u].s[nw]<<" "<<s[i]<<endl;
			u=t[u].s[nw];
		}t[u].sum++;//cout<<endl;
	}
	int q[N]; 
	void load(){
		int hd=1,tl=0;
		for(int i=0;i<26;i++)
			if(t[0].s[i])
				q[++tl]=t[0].s[i];
		while(hd<=tl){
			int u=q[hd];hd++;
//			cout<<u<<" "<<t[u].dep<<" "<<t[u].sum<<" "<<t[u].fa[0]<<endl;
			for(int j=0;j<26;j++){
				if(!t[u].s[j]){
					t[u].s[j]=t[t[u].fa[0]].s[j];
				}else{
					int v=t[u].s[j];
					t[v].fa[0]=t[t[u].fa[0]].s[j];
					t[v].sum+=t[t[v].fa[0]].sum;
					for(int k=1;k<24;k++)
						t[v].fa[k]=t[t[v].fa[k-1]].fa[k-1];
					q[++tl]=v;
				}
			}
		}
	}
	int calc(int u,int lim){
//		cout<<u<<" "<<lim<<endl;
		int ans=0;
		for(int i=23;i>=0;i--){
			if(t[t[u].fa[i]].dep>=lim){
				ans+=t[u].sum-t[t[u].fa[i]].sum;
				u=t[u].fa[i];
			}
		}
		if(t[u].dep>=lim)
			ans+=t[u].sum-t[t[u].fa[0]].sum;
//		cout<<ans<<endl;
		return ans;
	}
	ll sol(char *s,int n,int l,int r){
		int u=0;
		ll ans=0;
		for(int i=1;i<=n;i++){
			int nw=s[i]-'a';
			u=t[u].s[nw];
			if(i>=r&&((i&1)^1))
				ans+=calc(u,i-l+1);
		}return ans;
	}
}T;

char s[N],t[N/2+5];

bool M2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cerr<<(&M1-&M2)/1024.0/1024.0<<endl;
	double st=clock();
	int n=read(),q=read();
	for(int _=1;_<=n;_++){
		scanf("%s%s",s+1,t+1);
		int len=strlen(s+1);
		for(int i=len;i>=1;i--)
			s[i*2-1]=s[i];
		for(int i=len;i>=1;i--)
			s[i*2]=t[i];
		T.insert(s,len*2);
	}T.load();
	int cnt=0;ll sum=0;
	while(q--){
		scanf("%s%s",s+1,t+1);
		if(strlen(s+1)!=strlen(t+1)){
			print(0),pc('\n');
			continue;
		}
		int len=strlen(s+1);
		for(int i=len;i>=1;i--)
			s[i*2-1]=s[i];
		for(int i=len;i>=1;i--)
			s[i*2]=t[i];
		int l=-1,r=-1;
		for(int i=2;i<=len*2;i+=2){
			if(s[i]!=s[i-1]){
				if(l==-1)
					l=i-1;
				r=i;
			}
		}
		ll tmp=0;
		print(tmp=T.sol(s,len*2,l,r)),pc('\n');
		cnt+=tmp>0;sum+=tmp;
	}
	cerr<<(clock()-st)/1000.0<<endl;
	cerr<<cnt<<" "<<sum<<endl;
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
