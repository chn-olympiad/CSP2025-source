#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ls[4];
struct node{
	int a[4];
	int f,s,t;
}d[100005];
int cnt[4],c[4];
bool cmp(node x,node y){
	return x.a[x.f]-x.a[x.s]<y.a[y.f]-y.a[y.s];
}
bool cmp2(node x,node y){
	return x.a[x.s]-x.a[x.t]<y.a[y.s]-y.a[y.t];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int hn=n/2;
		ll sum=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			cin>>ls[1]>>ls[2]>>ls[3];
			d[i].a[1]=ls[1];d[i].a[2]=ls[2];d[i].a[3]=ls[3];
			sort(ls+1,ls+4);
			if(ls[1]==d[i].a[1]) d[i].t=1;if(ls[1]==d[i].a[2]) d[i].t=2;if(ls[1]==d[i].a[3]) d[i].t=3;
			if(ls[2]==d[i].a[1]) d[i].s=1;if(ls[2]==d[i].a[2]) d[i].s=2;if(ls[2]==d[i].a[3]) d[i].s=3;
			if(ls[3]==d[i].a[1]) d[i].f=1;if(ls[3]==d[i].a[2]) d[i].f=2;if(ls[3]==d[i].a[3]) d[i].f=3;
			sum+=d[i].a[d[i].f];
			cnt[d[i].f]++;
		}
		int mx;c[1]=cnt[1],c[2]=cnt[2],c[3]=cnt[3];
		sort(cnt+1,cnt+4);
		if(cnt[3]==c[1]) mx=1;if(cnt[3]==c[2]) mx=2;if(cnt[3]==c[3]) mx=3;
		sort(d+1,d+1+n,cmp);
		int i=1;
		while(c[1]>hn||c[2]>hn||c[3]>hn){
			if(d[i].f==mx){
				sum-=d[i].a[d[i].f]-d[i].a[d[i].s];
				c[d[i].f]--;
				c[d[i].s]++;
			}
			i++;
			if(i>n) break;
		}
		cout<<sum<<"\n";
	} 
	return 0;
}

