#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N],p[N*2];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(p,0,sizeof(p));
		int n;
		scanf("%d",&n);
		int cnt1=0,cnt2=0,cnt3=0;
		int ans1=0,ans2=0,ans3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i]){
				cnt1++;
				ans1+=a[i];
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				cnt2++;
				ans2+=b[i];
			}
			else if(c[i]>=a[i]&&c[i]>=b[i]){
				cnt3++;
				ans3+=c[i];
			}
		}
//		cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			printf("%d\n",ans1+ans2+ans3);
			continue;
		}
		else{
			int tot=0;
			if(cnt1>n/2){
				for(int i=1;i<=n;i++){
					if(a[i]>=b[i]&&a[i]>=c[i]){
						p[++tot]=a[i]-b[i];
						p[++tot]=a[i]-c[i];
					}
				}
			}
			if(cnt2>n/2){
				for(int i=1;i<=n;i++){
					if(b[i]>=a[i]&&b[i]>=c[i]){
						p[++tot]=b[i]-a[i];
						p[++tot]=b[i]-c[i];
					}
				}
			}
			if(cnt3>n/2){
				for(int i=1;i<=n;i++){
					if(c[i]>=b[i]&&c[i]>=a[i]){
						p[++tot]=c[i]-b[i];
						p[++tot]=c[i]-a[i];
					}
				}
			}
//			for(int i=1;i<=tot;i++){
//				cout<<p[i]<<" ";
//			}
			sort(p+1,p+tot+1);
			int m=max(max(cnt1,cnt2),cnt3),ans=ans1+ans2+ans3;
//			cout<<ans<<endl;
			
			int tot1=0;
			for(int i=m;i>n/2;i--){
				ans-=p[++tot1];
//				res+=p[tot1];
			}
//			cout<<res<<endl;
//			cout<<endl;
			printf("%d\n",ans);
		}
	}
	return 0;
}
