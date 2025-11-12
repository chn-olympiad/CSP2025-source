#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,ans=0;
int f[100005];
struct Member{
	int f1,f2,f3;
}a[100005];
void getans(){
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
//		cout<<f[i]<<' ';//------------------------
		if(f[i]==0)cnt1++;
		if(f[i]==1)cnt2++;
		if(f[i]==2)cnt3++;
	}
//	cout<<endl;//--------------------------------
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2)return ;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(f[i]==0)sum+=a[i].f1;
		if(f[i]==1)sum+=a[i].f2;
		if(f[i]==2)sum+=a[i].f3;
	}
	ans=max(ans,sum);
}
void dfs(int x){
	if(x>n){
		getans();
		return ;
	}
	f[x]=0;
	dfs(x+1);
	f[x]=1;
	dfs(x+1);
	f[x]=2;
	dfs(x+1);
}
bool cmpa(Member a,Member b){
	return a.f2>b.f2;
}
bool cmpb(Member a,Member b){
	if(a.f1==b.f1)return a.f2<b.f2;
	return a.f1>b.f1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool fa=1,fb=1;
		ans=0;
		memset(f,0,sizeof f);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].f1>>a[i].f2>>a[i].f3;
			if(a[i].f2!=0)fa=0;
			if(a[i].f3!=0)fa=fb=0;
		}
		if(fa){
			sort(a+1,a+n+1,cmpa);
			for(int i=1;i<=n/2;i++)ans+=a[i].f2;
			cout<<ans<<"\n";
			continue;
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}