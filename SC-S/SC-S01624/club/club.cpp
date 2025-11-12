#include<bits/stdc++.h>
//#define DBG

#ifdef DBG
#define dbg(...) fprintf(stderr,__VA_ARGS__)
#else
#define dbg(...) void()
#endif

#define il inline __attribute((always_inline))

using u32=unsigned int;
using i64=long long;
using u64=unsigned long long;

template<typename T=int>
T read(){
	T x=0;char c=getchar(),f=0;
	while(c<'0'||'9'<c) f=(c=='-'),c=getchar();
	while('0'<=c&&c<='9') x=x*10+(c&15),c=getchar();
	return f?-x:x;
}

template<typename T>
void print(T x){
	if(x==0) return putchar('0'),void();
	if(x<0) putchar('-'),x=-x;
	if(x>=10) print(x/10),x%=10;
	putchar(x|'0');
}

int a[100010][3],max[100010],semax[100010];
char vis[100010];

void solve(){
	int cnt[3]={0};
	int i,j,x;
	int n=read();
	i64 res=0;
	
	std::vector<int> vec[3];
	
	for(i=0;i<n;++i){
		max[i]=semax[i]=0;
		for(j=0;j<3;++j){
			a[i][j]=read();
			if(a[i][j]>max[i]) semax[i]=max[i],max[i]=a[i][j];
			else if(a[i][j]>semax[i]) semax[i]=a[i][j];
		}
		for(j=0;j<3;++j) if(a[i][j]==max[i]){
			vec[j].push_back(i);
			break;
		}
		res+=max[i];
	}
	for(i=0;i<3;++i) if(vec[i].size()>n/2){
		std::sort(vec[i].begin(),vec[i].end(),[](int a,int b){return semax[a]-max[a]<semax[b]-max[b];});
		while(vec[i].size()>n/2){
			x=vec[i].back();
			vec[i].pop_back();
			res+=semax[x]-max[x];
		}
		break;
	}
	print(res),putchar('\n');
}

int main(){
#ifndef ZIGAO
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
#endif
	
	int T=read();
	while(T--) solve();
	
	return 0;
}