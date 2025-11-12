#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	int a,b,c;
}A[N];
int T,n,a[N],b[N],c[N];
int ans,dp[205][205][205],flag1,flag2;
vector<int>Va,Vb,Vc;
void solve1(){
	ans=0;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		for(int x=0;x<=min(i,n/2);x++)
			for(int y=0;y<=min(i-x,n/2);y++){
				if(i-x-y>n/2)continue;
				if(x>0)dp[i][x][y]=max(dp[i][x][y],dp[i-1][x-1][y]+a[i]);
				if(y>0)dp[i][x][y]=max(dp[i][x][y],dp[i-1][x][y-1]+b[i]);
				if(i-x-y>0)dp[i][x][y]=max(dp[i][x][y],dp[i-1][x][y]+c[i]);
				if(i==n)ans=max(ans,dp[i][x][y]);
			}
	cout<<ans<<'\n';	
}
void solve2(){
	ans=0;
	sort(a+1,a+n+1);
	for(int i=n/2+1;i<=n;i++)ans+=a[i];
	cout<<ans<<'\n';
}
bool cmp1(node &x,node &y){
	return x.a-x.b>y.a-y.b;
}
void solve3(){
	sort(A+1,A+n+1,cmp1);
	ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=A[i].a;
	}
	for(int i=n/2+1;i<=n;i++){
		ans+=A[i].b;
	}
	cout<<ans<<'\n';
}
bool cmda(int x,int y){
	return a[x]-max(b[x],c[x])>a[y]-max(b[y],c[y]);
}
bool cmdb(int x,int y){
	return b[x]-max(a[x],c[x])>b[y]-max(a[y],c[y]);
}
bool cmdc(int x,int y){
	return c[x]-max(a[x],b[x])>c[y]-max(a[y],b[y]);
}
void solve4(){
	ans=0;
	Va.clear();Vb.clear();Vc.clear();
	for(int i=1;i<=n;i++){
		if(a[i]>=b[i]&&a[i]>=c[i])Va.push_back(i);
		else if(b[i]>=c[i])Vb.push_back(i);
		else Vc.push_back(i);
	}
	if(int(Va.size())>n/2){
		sort(Va.begin(),Va.end(),cmda);
		for(int i=0;i<n/2;i++)ans+=a[Va[i]];
		for(int i=n/2;i<int(Va.size());i++)ans+=max(b[Va[i]],c[Va[i]]);
		for(int i=0;i<int(Vb.size());i++)ans+=b[Vb[i]];
		for(int i=0;i<int(Vc.size());i++)ans+=c[Vc[i]];
	}
	else if(int(Vb.size())>n/2){
		sort(Vb.begin(),Vb.end(),cmdb);
		for(int i=0;i<n/2;i++)ans+=b[Vb[i]];
		for(int i=n/2;i<int(Vb.size());i++)ans+=max(a[Vb[i]],c[Vb[i]]);
		for(int i=0;i<int(Va.size());i++)ans+=a[Va[i]];
		for(int i=0;i<int(Vc.size());i++)ans+=c[Vc[i]];
	}
	else if(int(Vc.size())>n/2){
		sort(Vc.begin(),Vc.end(),cmdc);
		for(int i=0;i<n/2;i++)ans+=c[Vc[i]];
		for(int i=n/2;i<int(Vc.size());i++)ans+=max(a[Vc[i]],b[Vc[i]]);
		for(int i=0;i<int(Va.size());i++)ans+=a[Va[i]];
		for(int i=0;i<int(Vb.size());i++)ans+=b[Vb[i]];
	}
	else{
		for(int i=0;i<int(Va.size());i++)ans+=a[Va[i]];
		for(int i=0;i<int(Vb.size());i++)ans+=b[Vb[i]];
		for(int i=0;i<int(Vc.size());i++)ans+=c[Vc[i]];
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>T;
	for(;T--;){
		cin>>n;
		flag1=flag2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			A[i].a=a[i],A[i].b=b[i],A[i].c=c[i];
			if(b[i]!=0||c[i]!=0)flag1=0;
			if(c[i]!=0)flag2=0;
		}
		solve4();
	}
	return 0;
}