#include <bits/stdc++.h>
using namespace std;
long long n,m,k,mx,sum,minn=LLONG_MAX;
struct geed{
	long long jia,ge[10005];
}xiang[15];
struct good{
	long long tou,wei,jia;
}lu[1000005];
good xianlu[2000005];
bool cmp1(good x,good y){
	return x.jia <= y.jia ;
}
long long ja[100005],xn;
long long fu(long long x){
	if(ja[x]==x)return x;
	return ja[x]=fu(ja[x]);
}
long long b;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>b;
	for(int i=1;i<=m;i++){
		cin>>lu[i].tou >>lu[i].wei >>lu[i].jia ;
	}
	for(int i=1;i<=b;i++){
		cin>>xiang[i].jia ;
		for(int j=1;j<=n;j++)cin>>xiang[i].ge [j];
	}
	long long k=0;
	while(1){
		mx=0;
		sum=0;
		for(int i=1;i<=m;i++){
			xianlu[++mx].jia =lu[i].jia ;
			xianlu[mx].tou =lu[i].tou ;
			xianlu[mx].wei =lu[i].wei ;
		}
		long long p=0;
		xn=n;
		long long kk=k;
		bool e=0;
		while(kk!=0){
			p++;
			if(p>b){
				e=1;
				break;
			}
			if(kk%2==1){
				xn++;
				sum+=xiang[p].jia ;
				for(int i=1;i<=n;i++){
					xianlu[++mx].tou =xn;
					xianlu[mx].wei =i;
					xianlu[mx].jia =xiang[p].ge [i];
				}
			}
			kk/=2;
		}
		if(e)break;
		sort(xianlu+1,xianlu+mx+1,cmp1);
		bool fff=1;
		if(sum>=minn)fff=0;
//		if(!fff)break;
		for(int i=1;i<=xn;i++)ja[i]=i;
		for(int i=1;i<=mx;i++){
			long long g=fu(xianlu[i].tou );
			long long f=fu(xianlu[i].wei );
			if(g!=f){
				ja[f]=ja[g];
				sum+=xianlu[i].jia ;
			}
		}
		minn=min(minn,sum);
		k++;
			
	}
	cout<<minn;
	return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/