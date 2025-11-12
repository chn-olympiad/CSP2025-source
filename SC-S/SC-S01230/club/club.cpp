#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int T,n,a[N],b[N],c[N],ans,a1,a2,a3;
int b1[N],b2[N],b3[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		a1=a2=a3=ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ans+=a[i],b1[++a1]=a[i]-max(b[i],c[i]);
			} else{
				if(b[i]>=a[i]&&b[i]>=c[i]){
					ans+=b[i],b2[++a2]=b[i]-max(a[i],c[i]);
				} else{
					ans+=c[i],b3[++a3]=c[i]-max(a[i],b[i]);
				}
			}
		}
		if(a1>n/2){
			sort(b1+1,b1+a1+1);
			for(int i=1;i<=a1-n/2;i++)
				ans-=b1[i];
		} else{
			if(a2>n/2){
				sort(b2+1,b2+a2+1);
				for(int i=1;i<=a2-n/2;i++)
					ans-=b2[i];
			} else{
				if(a3>n/2){
					sort(b3+1,b3+a3+1);
					for(int i=1;i<=a3-n/2;i++)
						ans-=b3[i];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}