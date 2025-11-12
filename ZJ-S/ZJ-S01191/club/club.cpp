#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	long long b1,b2,b3;
}a[1000005];
int l[500005];
int n;
long long ans=-1;
bool cmp23(node a,node b){
	return a.b1>b.b1;
}
bool cmp33(node a,node b){
	return a.b2>b.b2;
}
void dfs(int x,long long maxx,int aa,int bb,int cc){
	if(x==n+1){
		ans=max(ans,maxx);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(aa+1>n/2 && i==1) continue;
		if(bb+1>n/2 && i==2) continue;
		if(cc+1>n/2 && i==3) continue;
		if(i==1) dfs(x+1,maxx+a[x].b1,aa+1,bb,cc);
		if(i==2) dfs(x+1,maxx+a[x].b2,aa,bb+1,cc);
		if(i==3) dfs(x+1,maxx+a[x].b3,aa,bb,cc+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=-1;
		cin>>n;
		int f2=1,f3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].b1>>a[i].b2>>a[i].b3;
			if(a[i].b2!=0) f2=2;
			if(a[i].b3!=0) f3=3;
		} 
		if(f2==2 && f3==2)dfs(1,0,0,0,0);
		else if(f2==1 && f3==1){
			sort(a+1,a+n+1,cmp23);
			ans=0;
			for(int i=1;i<=n/2;i++) ans+=a[i].b1;
		}
		else if(f2==2 && f3==1){
			sort(a+1,a+n+1,cmp23);
			ans=0;
			for(int i=1;i<=n;i++){
				if(i<=n/2) ans+=a[i].b1;
				else ans+=a[i].b2;
			}
			long long sum=0;
			sort(a+1,a+n+1,cmp33);
			for(int i=1;i<=n;i++){
				if(i<=n/2) sum+=a[i].b2;
				else sum+=a[i].b1;
			}
			ans=max(ans,sum);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
