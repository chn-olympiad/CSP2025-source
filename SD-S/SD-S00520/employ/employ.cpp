#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<cstring>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define ll long long
#define ull usdigned long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int N=505;
const ll mod=998244353;
ll read(){
	ll x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){w=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*w;
}
void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
ll n,m,c[N];
string s;
ll a[N],b[N],sum[N],vis[N],ans;
bool cheak(int x){
	ll res=0;
	for (int i=1;i<=x;i++){
		int now=0;
		for (int j=1;j<i;j++){
			if(s[j]=='0'||c[a[j]]>now){
				now++;
			}
		}
		if(c[a[i]]<=now) res++;
	}
	if(res<m) return 1;
	else return 0;
}
void dfs(int pos){
	for (int i=1;i<=n;i++){
		if(vis[i]==1) continue; 
		a[pos]=i;
		vis[i]=1;
		if(pos==n){
			if(cheak(pos)==1){
				ans=(ans+1)%mod;
			}	 
		}
		dfs(pos+1);
		vis[i]=0;
	}
}
int main(){
	file("employ");
	n=read();m=read();
	cin>>s;
	s=" "+s;
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(s[i]=='0');
	}
	for (int i=1;i<=n;i++){
		c[i]=read();
	}
	if(n<=18){
		dfs(1);
		cout<<ans<<"\n"; 
	}
	return 0;
}
/*
3 2
101
1 1 2
*/
