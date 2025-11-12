#include<bits/stdc++.h>
using namespace std;
int n,a[5010],c[5010],ans;
void dfs(int x){
	if(x>=n+1){
		int s=0,ma=0;
		for(int i=1;i<=n;i++){
			if(c[i]){
				s+=a[i],ma=max(ma,a[i]);
			}
		}
		if(s>ma*2){
			ans++;
		}
		return ;
	}
	c[x]=0;
	dfs(x+1);
	c[x]=1;
	dfs(x+1);
	c[x]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
//4/10AC!!!
