#include<bits/stdc++.h>
using namespace std;
int n,k,a[510000],b[510000],cnt,p[510000],ans,maxx,vis[510000],la[510000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	p[0]=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=0){
			a[++cnt]=b[i];
		}
	}
	for(int i=1;i<=cnt;i++){
		p[i]=(p[i-1]^a[i]);
	}
	int en=0;
	for(int i=1;i<=cnt;i++){
		if(p[i]==0||p[i]==k||(p[i]^p[en])==k){
			ans++;
			en=i;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
