#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int a[100005],b[100005],c[100005];
int fa[50005],fb[50005],fc[50005];
int t[20];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int Q;
	scanf("%d",&Q);
	while(Q--){
		memset(fa,0,sizeof(fa));
		memset(fb,0,sizeof(fb));
		memset(fc,0,sizeof(fc));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		}
		fa[1]=a[1],fb[1]=b[1],fc[1]=c[1];
		for(int i=2;i<=n;i++){
			for(int j=n/2;j>=1;j--){
				
				int v1=max(fa[j],max(fa[j-1],max(fc[j],fb[j]))+a[i]),v2=max(fb[j],max(fa[j],max(fc[j],fb[j-1]))+b[i]),v3=max(fc[j],max(fa[j],max(fc[j-1],fb[j]))+c[i]);
				if(a[i]!=0)fa[j]=v1;
				if(b[i]!=0)fb[j]=v2;
				if(c[i]!=0)fc[j]=v3;
		 	}
			//printf("%d %d %d %d %d %d\n",fa[2],fb[2],fc[2],fa[1],fb[1],fc[1]);
		}
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans=max(ans,max(fa[i],max(fb[i],fc[i])));
		}
		printf("%d\n",ans);
	}
	return 0;
}
