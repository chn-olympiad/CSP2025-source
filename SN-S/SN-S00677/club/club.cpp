#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct A{
	int a,b,c;
}x[100005];
void dfs(int num,int suma,int sumb,int sumc,int sum){
	if(num>n){
		ans=max(ans,sum);
		return;
	} 
	if(suma<n/2)dfs(num+1,suma+1,sumb,sumc,sum+x[num].a);
	if(sumb<n/2)dfs(num+1,suma,sumb+1,sumc,sum+x[num].b);
	if(sumc<n/2)dfs(num+1,suma,sumb,sumc+1,sum+x[num].c);
}
void dfs2(int num,int suma,int sumb,int sumc,int sum){
	if(num>n){
		ans=max(ans,sum);
		return;
	} 
	if(suma<n/2)dfs(num+1,suma+1,sumb,sumc,sum+x[num].a);
	if(sumb<n/2)dfs(num+1,suma,sumb+1,sumc,sum+x[num].b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	
	while(t--){
		cin>>n;
		ans=0;
		int sum=0;
		int p1=1,p2=1;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].c!=0)p1=0;
			if(x[i].b!=x[i].a)p2=0;
			sum+=x[i].a;
		}
		if(p1&&p2){
			ans=sum;
		}
		else if(p1){
			dfs2(1,0,0,0,0);
		}
		else{
			dfs(1,0,0,0,0);
		}
		for(int i=1;i<=n;i++)x[i].a=x[i].b=x[i].c=0;
		cout<<ans<<"\n";
		
	}
	return 0;
}
