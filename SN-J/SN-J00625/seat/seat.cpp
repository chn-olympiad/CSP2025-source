#include<bits/stdc++.h>
using namespace std;
int n,m;
int minn,cnt;
int sum,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int u;
			scanf("%d",&u);
			if(i==1&&j==1) minn=u;
			if(u>=minn) cnt++;
		}
	}
	if(cnt%n==0) ans=cnt/n;
	else ans=cnt/n+1;
	for(int i=0;i<2*n;i++){
		if(cnt%(2*n)==i){
			if(i==0) sum=1;
			else if(i<=n) sum=i;
			else sum=2*n-i+1;
		}
	}
	printf("%d %d",ans,sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
