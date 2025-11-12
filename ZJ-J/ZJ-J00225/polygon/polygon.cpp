#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))r=(r<<3)+(r<<1)+(ch&15),ch=getchar();
	return f*r;
}
const int maxn=5005,INF=998244353;
int n,a[maxn],ans,sum,cnt[maxn*maxn];
int fd(int x){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]<x)l=mid+1;
		else r=mid-1;
	}
	return r;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
	sort(a+1,a+1+n);
	sum-=a[n];
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=a[i];j--){
			if(cnt[j-a[i]]||j==a[i]&&i<=2){
				cnt[j]=(cnt[j]+1)%INF;
				if(i>1)ans=(ans+(fd(j)-i))%INF;
			}
		}
	}
	
	printf("%d",ans);
//	printf("\n");
//	for(int i=1;i<=sum;i++)printf("cnt[%d]=%d ",i,cnt[i]);
	return 0;
}
