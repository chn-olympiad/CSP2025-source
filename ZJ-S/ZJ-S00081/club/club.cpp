#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
struct node{
	int f,s,t,dif1;
}a[N];
int n,peo[5];
int ma(int a,int b,int c){
	if(a>b && a>c){
		if(b>c) return a-b;
		return a-c;
	}
	if(b>a && b>c){
		if(a>c) return b-a;
		return b-c;
	}
	if(a>b) return c-a;
	return c-b;
}
bool cmp(node x,node y){
	if(x.dif1==y.dif1) return x.f<y.f;
	return x.dif1>y.dif1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(peo,0,sizeof(peo));
		cin>>n;
		int maxn=n>>1;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
			a[i].dif1=ma(a[i].f,a[i].s,a[i].t);
		}
		sort(a+1,a+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			int fg=0;
			//cout<<a[i].dif1<<' ';
			int summ=max(max(a[i].f,a[i].s),a[i].t);
			//cout<<summ<<endl;
			if(summ==a[i].f){
				a[i].f=-1;
				if(peo[1]<maxn) ans+=summ,peo[1]++,fg=1;}
			else if(summ==a[i].s){
				a[i].s=-1;
				if(peo[2]<maxn) ans+=summ,peo[2]++,fg=1;}
			else if(summ==a[i].t){
				a[i].t=-1;
				if(peo[3]<maxn) ans+=summ,peo[3]++,fg=1;}
			//cout<<ans<<1<<endl;
			if(fg==1) continue;
			summ=max(max(a[i].f,a[i].s),a[i].t);
			if(summ==a[i].f){
				a[i].f=-1;
				if(peo[1]<maxn) ans+=summ,peo[1]++,fg=1;}
			else if(summ==a[i].s){
				a[i].s=-1;
				if(peo[2]<maxn) ans+=summ,peo[2]++,fg=1;}
			else if(summ==a[i].t){
				a[i].t=-1;
				if(peo[3]<maxn) ans+=summ,peo[3]++,fg=1;}
			
		}
		cout<<ans<<endl;
	}
}