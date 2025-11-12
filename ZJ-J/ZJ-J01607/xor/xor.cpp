#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],ans,cnt;
map<int,int> mp;
struct zdy{
	int x,y;
}b[500005];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]^a[i],mp[sum[i]]=1;
	
	int l=0;
	for(l=0;l<=n;l++){
		cnt=0;
		for(int i=l;i<=n;i++){
			int x=sum[i]^k;
//			printf("!!%d\n",i);
			if(!mp[x]) continue;
			for(int j=i+1;j<=n;j++)
				if(sum[j]==x){
//					printf("!!!!%d %d\n",i,j);
					cnt++;
					i=j-1;
					break;
				}
		}
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}
