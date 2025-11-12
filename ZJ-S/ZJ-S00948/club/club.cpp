#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n,a[N],b[N],c[N],t[N],k[N],cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cnt=0;
		int sum1=0,sum2=0,sum3=0,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i]){
				t[i]=1;
				ans+=a[i];
				sum1++;
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				t[i]=2;
				ans+=b[i];
				sum2++;
			}else {
				t[i]=3;
				ans+=c[i];
				sum3++;
			}
		}if(sum1>n/2){
			for(int i=1;i<=n;i++){
				if(t[i]==1)k[++cnt]=a[i]-max(b[i],c[i]);
			}sort(k+1,k+cnt+1);
			int x=0;
			while(sum1>n/2){
				sum1--;
				ans-=k[++x];
			}
		}if(sum2>n/2){
			for(int i=1;i<=n;i++){
				if(t[i]==2)k[++cnt]=b[i]-max(a[i],c[i]);
			}sort(k+1,k+cnt+1);
			int x=0;
			while(sum2>n/2){
				sum2--;
				ans-=k[++x];
			}
		}if(sum3>n/2){
			for(int i=1;i<=n;i++){
				if(t[i]==3)k[++cnt]=c[i]-max(a[i],b[i]);
			}sort(k+1,k+cnt+1);
			int x=0;
			while(sum3>n/2){
				sum3--;
				ans-=k[++x];
			}
		}printf("%d\n",ans);
	}
	return 0;
}
