#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+5;
int rd(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return f*x;
}int _s[20],_t;
void wt(int x){
	if(x<0)putchar('-'),x=-x;
	do _s[++_t]=x%10,x/=10;
	while(x);while(_t)putchar(_s[_t--]+48);
	return;
}
int T,n,sum=0;
pii p;
int a[N][4];
priority_queue<int>pq[4];
int ct[4];
void sol(){
	n=rd();sum=0;ct[1]=ct[2]=ct[3]=0;
	while(pq[1].size())pq[1].pop();
	while(pq[2].size())pq[2].pop();
	while(pq[3].size())pq[3].pop();
	for(int i=1;i<=n;i++){
		pii mx={0,0};
		for(int j=1;j<=3;j++){
			a[i][j]=rd();
			mx=max(mx,{a[i][j],j});
		}sum+=mx.fi;
		pq[mx.se].push(a[i][1]+a[i][2]+a[i][3]-2*mx.fi-min(a[i][1],min(a[i][2],a[i][3])));
		ct[mx.se]++;
	}
	for(int i=1;i<=3;i++){
		while(pq[i].size()>n/2){
			sum+=pq[i].top(),pq[i].pop();
		}
	}
	wt(sum),putchar('\n');
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=rd();
	while(T--)sol();
	return 0;
}
