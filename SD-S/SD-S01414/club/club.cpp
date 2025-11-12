#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
void read(T &x){x=0;ll f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}x*=f;}
template <typename T,typename ...Args>
void read(T &x,Args &...args){read(x);read(args...);}
template <typename T>
void write(T x){if(x<0){x=-x;putchar('-');}if(x>9)write(x/10);putchar(x%10+48);}
template <typename T,typename ...Args>
void write(T x,Args ...args){write(x);if(sizeof...(args)){putchar(' ');write(args...);}}
const ll N=1e5+5,inf=0x3f3f3f3f,mod=998244353;
ll n;
ll a[N][4];
vector<ll> s[4];
inline void init(){
	for(int i=1;i<4;i++)s[i].clear();
}
bool cmp1(ll x,ll y){
	return min(a[x][1]-a[x][2],a[x][1]-a[x][3])<min(a[y][1]-a[y][2],a[y][1]-a[y][3]);
}
bool cmp2(ll x,ll y){
	return min(a[x][2]-a[x][1],a[x][2]-a[x][3])<min(a[y][2]-a[y][1],a[y][2]-a[y][3]);
}
bool cmp3(ll x,ll y){
	return min(a[x][3]-a[x][2],a[x][3]-a[x][1])<min(a[y][3]-a[y][2],a[y][3]-a[y][1]);
}
inline void solve(){
	init();
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i][1],a[i][2],a[i][3]);
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])s[1].push_back(i);
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])s[2].push_back(i);
		else s[3].push_back(i);
	}
	ll ans=0;
	if(s[1].size()>(n>>1)){
		sort(s[1].begin(),s[1].end(),cmp1);
		int i;
		for(i=0;i<s[1].size();i++){
			ll x=s[1][i];
			if(a[x][1]-a[x][2]<=a[x][1]-a[x][3])s[2].push_back(x);
			else s[3].push_back(x);
			if(s[1].size()-i-1<=(n>>1))break;
		}
		for(i=i+1;i<s[1].size();i++)ans+=a[s[1][i]][1];
		for(auto x:s[2])ans+=a[x][2];
		for(auto x:s[3])ans+=a[x][3];
	}else if(s[2].size()>(n>>1)){
		
//		cout<<"ciallo2 ";
		sort(s[2].begin(),s[2].end(),cmp2);
		int i;
		for(i=0;i<s[2].size();i++){
			ll x=s[2][i];
			if(a[x][2]-a[x][1]<=a[x][2]-a[x][3]){
				s[1].push_back(x);
//				cerr<<"2->1 "<<x<<'\n';
			}
			else s[3].push_back(x);
			if(s[2].size()-i-1<=(n>>1))break;
		}
		for(i=i+1;i<s[2].size();i++)ans+=a[s[2][i]][2];
		for(auto x:s[1])ans+=a[x][1];
		for(auto x:s[3])ans+=a[x][3];
	}else if(s[3].size()>(n>>1)){
		
//		cout<<"ciallo3 ";
		sort(s[3].begin(),s[3].end(),cmp3);
		int i;
		for(i=0;i<s[3].size();i++){
			ll x=s[3][i];
			if(a[x][3]-a[x][2]<=a[x][3]-a[x][1])s[2].push_back(x);
			else s[1].push_back(x);
			if(s[3].size()-i-1<=(n>>1))break;
		}
		for(i=i+1;i<s[3].size();i++)ans+=a[s[3][i]][3];
		for(auto x:s[2])ans+=a[x][2];
		
		for(auto x:s[1])ans+=a[x][1];
	}
	
	else{
//		cout<<"ciallo4 ";
		for(auto x:s[1])ans+=a[x][1];
		for(auto x:s[2])ans+=a[x][2];
		for(auto x:s[3])ans+=a[x][3];
	}
	write(ans);
	putchar('\n');
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	read(t);
	while(t--)solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

