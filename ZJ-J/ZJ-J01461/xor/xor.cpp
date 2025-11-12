#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500005];
int ans;
int xyh[25];
int yyh[25];
int ayh[25];

int yh(int x,int y){
	int res=0;
	memset(xyh,0,sizeof(xyh));
	memset(yyh,0,sizeof(yyh));
	memset(ayh,0,sizeof(ayh));
	int px=0,py=0;
	while(x){
		xyh[++px]=x%2;
		x/=2;
	}
	while(y){
		yyh[++py]=y%2;
		y/=2;
	}
	for(int i=1;i<=20;i++){
		ayh[i]=(xyh[i]+yyh[i])%2;
	}
	for(int i=1;i<=20;i++){
		int t=pow(2,i-1);
		res+=ayh[i]*t;
	}
	return res;
}

void dfs(int head,int tmp,int tot){
	if(head==n+1){
		ans=max(ans,tot);
		return;
	}
	if(head==1&&tmp!=k){
		for(int i=2;i<=n;i++){
			dfs(i,a[i],tot);
		}
	}
	if(tmp==k){
		for(int i=head+1;i<=n;i++){
			dfs(i,a[i],tot+1);
		}
		ans=max(ans,tot+1);
		return;	
	}
	dfs(head+1,yh(tmp,a[head+1]),tot);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n+1]=0;
	dfs(1,a[1],0);
	cout<<ans;
	return 0;
}