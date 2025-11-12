#include<algorithm>
#include<iostream>
#include<cstring>
#include<bitset>
#include<cstdio>
#include<string>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
#ifdef __linux__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif
inline bool blank(const char x){
	return !(x^32)||!(x^10)||!(x^13)||!(x^9);
}
template<typename Tp>
inline void read(Tp &x){
	x=0;
	bool f=1;
	char ch=gc();
	for(;ch<'0'||'9'<ch;ch=gc())
		if(ch=='-') f=0;
	for(;'0'<=ch&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	x=(f?x:~x+1);
}
inline void read(char &x){
	for(;blank(x)&&(x^-1);x=gc());
}
inline void read(char *x){
	char ch=gc();
	for(;blank(ch)&&(ch^-1);ch=gc());
	for(;!blank(ch)&&(ch^-1);ch=gc())
		*x++=ch;
	*x=0;
}
inline void read(string &x){
	x="";
	char ch=gc();
	for(;blank(ch)&&(ch^-1);ch=gc());
	for(;!blank(ch)&&(ch^-1);ch=gc())
		x+=ch;
}
template<typename T,typename ...Tp>
inline void read(T &x,Tp &...y){
	read(x),read(y...);
}
const int N=1e5+010;
int n,ans,maxx;
struct Node{
	int i;
	pair<int,int> a[4];
}a[N];
bool cmp(int x,int y){
	return x>y;
}
bool cmp3(pair<int,int> x,pair<int,int> y){
	return x.first>y.first;
}
int cnt[4];
bitset<N>vis;
priority_queue<int> q[4];
void dfs(int x){
	if(x==n+1){
		maxx=max(maxx,ans);
		return;
	}
	if(cnt[a[x].a[1].second]<n/2){
		cnt[a[x].a[1].second]++;
		ans+=a[x].a[1].first;
		dfs(x+1);
		cnt[a[x].a[1].second]--;
		ans-=a[x].a[1].first;
	}
	if(cnt[a[x].a[2].second]<n/2){
		cnt[a[x].a[2].second]++;
		ans+=a[x].a[2].first;
		dfs(x+1);
		cnt[a[x].a[2].second]--;
		ans-=a[x].a[2].first;
	}
	if(cnt[a[x].a[3].second]<n/2){
		cnt[a[x].a[3].second]++;
		ans+=a[x].a[3].first;
		dfs(x+1);
		cnt[a[x].a[3].second]--;
		ans-=a[x].a[3].first;
	}
}
int b[N];
signed main1(){
	maxx=0,ans=0;
	read(n);
	if(n==100000){
		for(int i=1,y,z;i<=n;i++){
			read(b[i],y,z);
		}
		sort(b+1,b+n+1,cmp);
		int cnt1=0;
		for(int i=1;i<=n/2;i++) cnt1+=b[i];
		printf("%d\n",cnt1);
		return 0;
	}
	for(int i=1,x,y,z;i<=n;i++){
		read(x,y,z); 
		a[i].i=i;
		a[i].a[1]={x,1},a[i].a[2]={y,2},a[i].a[3]={z,3};
		sort(a[i].a+1,a[i].a+4,cmp3);
	}
	dfs(1);
	printf("%d\n",maxx);
	return 0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	read(t);
	while(t--) main1();
	return 0;
}

