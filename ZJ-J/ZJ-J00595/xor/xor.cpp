#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int res[1010][1010];
int mx=0;
void dfs(int level,int cnt){
	if(level>n){
		mx=max(mx,cnt);
		return;
	}
	for(int i=level;i<=n;i++){
		if(res[level][i]==k) dfs(i+1,cnt+1);
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool all_true=true;
	bool all_0_1=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) all_true=false;
		if(a[i]>1) all_0_1=false;
	}
	if(all_true){
		printf("%d",n/2);
		return 0;
	}
	else if(all_0_1){
		int sum=a[1],cnt=0;		
		for(int i=2;i<=n+1;i++){
			if(sum==k){
				cnt++;
				sum=a[i];
			}
			else if(i!=n+1) sum=sum^a[i];
		}
		printf("%d",cnt);
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				res[i][j]=a[i];
				for(int k=i+1;k<=j;k++){
					res[i][j]=res[i][j]^a[k];
				}
			}
		}
		dfs(1,0);
		printf("%d",mx);
	}
	return 0;
}