#include<bits/stdc++.h>
using namespace std;
int n,k,x,s[500005],ans;
bool vis[1050005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		s[i]=s[i-1]^x;
	}
	vis[0]=1;
	for(int i=1,l=0;i<=n;i++){
		if(vis[s[i]^k]){
			ans++;
			for(int j=l;j<i;j++)vis[s[j]]=0;
			l=i;
		}
		vis[s[i]]=1;
	}
	printf("%d\n",ans);
	return 0;
}