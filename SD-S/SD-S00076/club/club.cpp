#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[101000],b[101000],c[101000],x,y;
bool ok1=1,ok2=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(b[i]!=0||c[i]!=0)ok1=0;
			if(c[i]!=0)ok2=0;
		}
	}
	if(ok1==1){
		sort(a+1,a+1+n),reverse(a+1,a+1+n);
		for(int i=1;i<=n/2;i++)ans+=a[i];
		printf("%d",ans);
		return 0;
	}
	if(ok2==1){
		for(int i=1;i<=n;i++){
			if(a[i]>b[i])ans+=a[i],x++,c[i]=a[i]-b[i];
			else ans+=b[i],y++,c[i]=b[i]-a[i];
		}
		sort(c+1,c+1+n);
		for(int i=1;i<=max(x,y)-n/2;i++)ans-=c[i];
		printf("%d",ans);
		return 0;
	}
	if(n==2){
		int maxid[3],ans=0;
		for(int i=1;i<=2;i++){
			if(a[i]>b[i]&&a[i]>c[i])maxid[i]=1;
			if(b[i]>a[i]&&b[i]>c[i])maxid[i]=2;
			if(c[i]>b[i]&&c[i]>a[i])maxid[i]=3;
		}
		if(maxid[1]==maxid[2]){
			
		}else{
			for(int i=1;i<=2;i++){
				if(maxid[i]==1)ans+=a[i];
				if(maxid[i]==2)ans+=b[i];
				if(maxid[i]==3)ans+=c[i];
			}
			printf("%d",ans);
		}
	}
}//25pts
