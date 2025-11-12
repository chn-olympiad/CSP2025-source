#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,a[N][5];
int t;
bool vis[N][5];
int w1,w2,w3,cnt;
int mw;
int an[N];
void dfs(int i,int ans){
	
	cnt=max(ans,cnt);
//	cout<<i<<" "<<cnt<<" "<<ans<<endl;
	if(i>n)return;
//	cout<<w1<<" "<<w2<<" "<<w3<<endl;
	if(w1<mw&&vis[i][1]==0){
		w1++;
		vis[i][1]=1;
		dfs(i+1,ans+a[i][1]);
		vis[i][1]=0;
		w1--;
	}
	if(w2<mw&&vis[i][2]==0){
		w2++;
		vis[i][2]=1;
		dfs(i+1,ans+a[i][2]);
		vis[i][2]=0;
		w2--;
	}
	if(w3<mw&&vis[i][3]==0){
		w3++;
		vis[i][3]=1;
		dfs(i+1,ans+a[i][3]);
		vis[i][3]=0;
		w3--;
	}
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		mw=n/2;
		bool t1=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0)t1=0;
		}
		if(t1==1){
			memset(an,0,sizeof(an));
			for(int i=1;i<=n;i++)an[i]=a[i][1];
			sort(an+1,an+n+1,cmp);
			int ans1=0;
			for(int i=1;i<=mw;i++)ans1+=an[i];
			cout<<ans1<<endl;
			continue;
		}
		memset (vis,0,sizeof(vis));
		w1=0,w2=0,w3=0,cnt=0;
		dfs(0,0);
		cout<<cnt<<endl;
	}
return 0;}

