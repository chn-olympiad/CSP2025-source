#include<bits/stdc++.h>
#define rd read()
#define ll long long
#define ULL unsigned long long
#define lbt(x) ((x)&(-(x)))
#define Cmax(a,b) (a=max(a,(b)))
#define Cmin(a,b) (a=min(a,(b)))
#define for_(a,b,c) for(int a=(b);a<=(c);++a)
#define For_(a,b,c) for(int a=(b);a>=(c);--a)
#define md ((l+r)/2)
#define pi pair<int,int>
#define fs first
#define sc second
using namespace std;
	int n,m;
	const int N=510;
	int a[N],c[N],p[N];
	int ans=0;
	void check(){
		int cnt=0;
		int chenggong=0;
		for_(i,1,n){
			int x=p[i];
			bool flag=1;
			if(a[i]==0)flag=0;
			if(cnt>=c[x])flag=0;
			if(!flag)++cnt;
			else ++chenggong;
		}
		ans+=(chenggong>=m);
	}
//	inline ll read(){ll d=0,f=0;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}while(ch>='0'&&ch<='9'){d=(d<<1)+(d<<3)+ch-'0';ch=getchar();}return f?-d:d;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	string s;cin>>s;
	for_(i,1,n)a[i]=(s[i-1]=='1');
	for_(i,1,n)cin>>c[i];
	for_(i,1,n)p[i]=i;
	check();
	while(next_permutation(p+1,p+1+n)){
		check();
	}
	cout<<ans;
	
	
	
	
	
	
	
	return 0;
}
