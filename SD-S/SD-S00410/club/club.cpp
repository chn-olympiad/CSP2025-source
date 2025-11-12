#include<bits/stdc++.h>
using namespace std;
/*
rp++;
for(int i=;i<=;i++)
priority_queue<int,vector<int>,greater<int> >q;
upper_bound(d,d+n,x)-d
sort(a+1,a+n+1);
*/
struct cl{
	int a,b,c;
	int dt;
	bool operator <(const cl &x){
		return dt>x.dt;
	}
}k[100005];
int t,n,st,s[4],ans,bff,maxx,txx,maxf,txf;
int debug;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		s[1]=s[2]=s[3]=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&k[i].a,&k[i].b,&k[i].c);
			st=max(max(k[i].a,k[i].b),k[i].c);
			k[i].dt=min(min(st-k[i].a>0?st-k[i].a:998244,st-k[i].b>0?st-k[i].b:998244),st-k[i].c>0?st-k[i].c:998244);
			if(k[i].dt==998244) k[i].dt=0;
		}
		sort(k+1,k+n+1);
		for(int i=1;i<=n;i++){
			maxx=txx=maxf=txf=0;
			if(k[i].a>maxx){
				maxx=k[i].a;
				maxf=1;
			}
			if(k[i].b>maxx){
				maxx=k[i].b;
				maxf=2;
			}
			if(k[i].c>maxx){
				maxx=k[i].c;
				maxf=3;
			}
			if(k[i].a>txx&&k[i].a<maxx){
				txx=k[i].a;
				txf=1;
			}
			if(k[i].b>txx&&k[i].b<maxx){
				txx=k[i].b;
				txf=2;
			}
			if(k[i].c>txx&&k[i].c<maxx){
				txx=k[i].c;
				txf=3;
			}
			if(txx==0){
				txx=k[i].a;
				if(s[1]<=s[2]&&s[1]<=s[3]){
					txf=1;
				}
				if(s[1]<=s[2]&&s[1]<=s[3]){
					txf=2;
				}
				if(s[1]<=s[2]&&s[1]<=s[3]){
					txf=3;
				}
			}
			if(s[maxf]<n/2){
				ans+=maxx;
				s[maxf]++;
			}
			else{
				ans+=txx;
				s[txf]++;
				debug++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(0);
	return 0;
}

