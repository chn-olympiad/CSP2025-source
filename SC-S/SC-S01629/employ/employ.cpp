#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int mod=998244353;
int n,m,ans;
string s;
int a[N];
struct node{
	int idx,k;
}e[N];

int c[101][101];
inline void init(){
	c[0][0]=1;
	c[1][1]=1,c[1][0]=1;
	for(int i=1;i<=100;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
}

bool f;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)  if(s[i]!='1')  f=1;
	for(int i=1;i<=n;i++)  cin>>a[i];
	for(int i=1;i<=n;i++)  e[i].idx=i,e[i].k=a[i],a[i]=i;
	if(!f){
		init();int op=0;
		for(int i=1;i<=n;i++)  if(!e[i].k)  op++;
		for(int i=m;i<=n-op;i++)  ans=(ans+c[n-op][m])%mod;
		cout<<ans<<'\n';
		return 0;
	}
	do{
		int num=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')  num++;
			else{
				if(num>=e[a[i]].k)  num++;
			}
		}
		if(n-num>=m)  ans++;
	}while(next_permutation(a+1,a+1+n));
	cout<<ans%mod<<'\n';
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/