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

priority_queue<int>q[3];

bool M2;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cerr<<(&M1-&M2)/1024.0/1024.0<<endl;
	double st=clock();
	int _T=read();
	while(_T--){
		int n=read();
		while(!q[0].empty())q[0].pop();
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		ll sum=0;
		for(int i=1;i<=n;i++){
			int a=read(),b=read(),c=read();
			if(a>=b&&a>=c){
				sum+=a;
				q[0].push(max(b,c)-a);
			}
			else if(b>=a&&b>=c){
				sum+=b;
				q[1].push(max(a,c)-b);
			}
			else if(c>=a&&c>=b){
				sum+=c;
				q[2].push(max(b,a)-c);
			}
		}
		for(int i=0;i<3;i++){
			while(q[i].size()>n/2){
				sum+=q[i].top();
				q[i].pop(); 
			}
		}print(sum),pc('\n');
	}
	cerr<<(clock()-st)/1000.0<<endl;
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
