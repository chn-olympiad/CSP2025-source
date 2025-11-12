#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int T;
int n;
int dp[105][105][105];
void subtask1(){
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){	
				dp[i][j][k]=0;	
			}
		}
	}
	int ans=0;
	for(int x=1;x<=n;x++){
		for(int i=0;i<=min(x,n/2);i++){
			for(int j=0;j<=min(x-i,n/2);j++){
				int k=x-i-j;
				if(k>n/2) continue;
				if(i!=0) dp[i][j][k]=max(dp[i-1][j][k]+a[x],dp[i][j][k]);
				if(j!=0) dp[i][j][k]=max(dp[i][j-1][k]+b[x],dp[i][j][k]);
				if(k!=0) dp[i][j][k]=max(dp[i][j][k-1]+c[x],dp[i][j][k]);
				ans=max(ans,dp[i][j][k]);
			}
		}
	}
	cout<<ans<<'\n';
}
void subtask2(){
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=a[i];
	}
	cout<<ans<<'\n';
}
int tp[N];
struct Node{
	int sum;
	int type;
	int tp;
}s[N*3];
bool cmp(Node a,Node b){
	return a.sum>b.sum;
}
void subtask3(){
	int cnta,cntb,cntc,cnt;
	cnta=cntb=cntc=cnt=0;
	for(int i=1;i<=n;i++){
		tp[i]=0;
		s[++cnt]={a[i],1,i};
		s[++cnt]={b[i],2,i};
		s[++cnt]={c[i],3,i};
	}
	sort(s+1,s+1+cnt,cmp);
	int ans=0;
	int res=0;
	for(int i=1;i<=cnt;i++){
		if(res==n) break;
		if(tp[s[i].tp]==1) continue;
		if(s[i].type==1){
			if(cnta==n/2) continue;
			cnta++;
			res++;
			ans+=s[i].sum;
			tp[s[i].tp]=1;
		}
		if(s[i].type==2){
			if(cntb==n/2) continue;
			cntb++;
			res++;
			ans+=s[i].sum;
			tp[s[i].tp]=1;
		}
		if(s[i].type==3){
			if(cntc==n/2) continue;
			cntc++;
			res++;
			ans+=s[i].sum;
			tp[s[i].tp]=1;
		} 
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		int A=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]||c[i]) A=1;
		}
		if(n<=200){//dp暴力 
			subtask1();
		}
		else if(A==0){
			subtask2();
		}
		else{
			subtask3();
		}
	}
	return 0;
}

