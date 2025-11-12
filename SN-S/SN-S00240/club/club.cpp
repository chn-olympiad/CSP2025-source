#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,id;
}a[100001];
long long ans=-1;
int suma=0,sumb=0,sumc=0;
void dfs(int n,int ta,int tb,int tc,int c,long long sum){
	if(c>n){
		ans=max(ans,sum);
		return ;
	}
	if(ta<n/2)dfs(n,ta+1,tb,tc,c+1,sum+a[c].a);
	if(tb<n/2)dfs(n,ta,tb+1,tc,c+1,sum+a[c].b);
	if(tc<n/2)dfs(n,ta,tb,tc+1,c+1,sum+a[c].c);
	return;
}
bool cmp(node x,node y){
	return x.a>y.a;
}
bool cmq(node x,node y){
	return x.b>y.b;
}
bool cmt(node x,node y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long sum=0;
		suma=sumb=sumc=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			suma+=a[i].a,sumb+=a[i].b,sumc+=a[i].c;
		} 
		if(n<11){
			ans=-1;
			dfs(n,0,0,0,0,0);
			cout<<ans<<"\n";
		}
		else if(suma==0&&sumb==0&&sumc==0){
			cout<<0<<"\n";
		}
		else if(sumb==0&&sumc==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) sum+=a[i].a;
			cout<<sum<<"\n";
		}
		else if(suma==0&&sumc==0){
			sort(a+1,a+n+1,cmq);
			for(int i=1;i<=n/2;i++) sum+=a[i].b;
			cout<<sum<<"\n";
		}
		else if(sumb==0&&suma==0){
			sort(a+1,a+n+1,cmt);
			for(int i=1;i<=n/2;i++) sum+=a[i].c;
			cout<<sum<<"\n";
		}
		else{
			for(int i=1;i<=n;i++) sum+=max(max(a[i].a,a[i].b),a[i].c);
			cout<<sum<<"\n";
		}
	}
	
	return 0;
}
