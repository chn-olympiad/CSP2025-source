#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,inf=-0x3F3F3F3F;
int a[N][4],n,cntm,an=inf;

bool sf(int x,int cntm){
	return x<cntm;
}
int dp(int i,int j,int sum,int cn1,int cn2,int cn3){
	int cnt[4];
	int ans=0,x=0;
	cnt[1]=cn1,cnt[2]=cn2,cnt[3]=cn3;
	if(i>n)return ans;
	cnt[j]++;
	ans+=a[i][j];
	for(int j=1;j<=3;j++){
		if(sf(cnt[j],cntm))x=max(x,dp(i+1,j,sum,cnt[1],cnt[2],cnt[3]));
	}
	ans+=x;
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		an=inf;
		scanf("%d",&n);
		cntm=n/2;
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
		}
		for(int j=1;j<=3;j++)an=max(an,dp(1,j,0,0,0,0));
		printf("%d\n",an);
	}
	return 0;
}