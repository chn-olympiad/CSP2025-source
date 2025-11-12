#include<bits/stdc++.h>
#define int long long
#define MAXN 100005
using namespace std;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

int T;

struct cl{
	int a,b,c,vis;
}a[MAXN];

bool cmp1(cl x,cl y){
	if(x.a!=y.a) return x.a>y.a;
	else if(x.b!=y.b) return x.b>y.b;
	else return x.c>y.c;
}

void solve(){
	int n,ans=0;
	n=read();
	priority_queue<int,vector<int>> q1;
	priority_queue<int,vector<int>> q2;
	priority_queue<int,vector<int>> q3;
	int lim1=n/2;
	int lim2=n/2;
	int lim3=n/2;
	for(int i=1;i<=n;i++){
		a[i].a=read();
		a[i].b=read();
		a[i].c=read();
	}
	for(int i=1;i<=n;i++){
		int x=a[i].a,y=a[i].b,z=a[i].c;
		int max_p=max(x,max(y,z));
		if(x==max_p){
			q1.push(max(z-x,y-x));
			ans+=x;
			if(!lim1){
				ans+=(q1.top());
				q1.pop();
				continue;
			}
			lim1--;
			a[i].vis=1;
			
		}else if(y==max_p){
			q2.push(max(x-y,z-y));
			ans+=y;
			if(!lim2){
				ans+=(q2.top());
				q2.pop();
				continue;
			}
			lim2--;
		}else if(z==max_p){
			q3.push(max(x-z,y-z));
			ans+=z;
			if(!lim3){
				ans+=(q3.top());
				q3.pop();
				continue;
			}
			lim3--;
		}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++){
		a[i].a=a[i].b=a[i].c=0;
	}
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		solve();
	}
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
-----------
5 3 4
4 2 1
3 5 1
3 2 4
*/
