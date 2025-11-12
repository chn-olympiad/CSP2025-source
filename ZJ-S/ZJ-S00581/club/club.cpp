#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][4],cnt[4],need,x,y[100005];long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				++cnt[1];
			}
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				++cnt[2];
			}
			if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
				++cnt[3];
			}
		}
		need=n/2;
		ans=0;
		if(cnt[1]<=need&&cnt[2]<=need&&cnt[3]<=need){
			for(int i=1;i<=n;++i){
				ans=ans+max(a[i][1],max(a[i][2],a[i][3]));
			}
		}else{
			if(cnt[1]>cnt[2]&&cnt[1]>cnt[3]){
				x=1;
			}else if(cnt[2]>cnt[1]&&cnt[2]>cnt[3]){
				x=2;
			}else{
				x=3;
			}
			int z=0;
			if(x==1){
				for(int i=1;i<=n;++i){
					if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
						ans+=a[i][1];
						y[++z]=a[i][1]-max(a[i][2],a[i][3]);
					}else{
						ans=ans+max(a[i][1],max(a[i][2],a[i][3]));
					}
				}
			}else if(x==2){
				for(int i=1;i<=n;++i){
					if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
						ans+=a[i][2];
						y[++z]=a[i][2]-max(a[i][1],a[i][3]);
					}else{
						ans=ans+max(a[i][1],max(a[i][2],a[i][3]));
					}
				}
			}else{
				for(int i=1;i<=n;++i){
					if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
						ans+=a[i][3];
						y[++z]=a[i][3]-max(a[i][1],a[i][2]);
					}else{
						ans=ans+max(a[i][1],max(a[i][2],a[i][3]));
					}
				}
			}
			sort(y+1,y+1+z);
			for(int i=1;i<=z-need;++i){
				ans-=y[i];
			}
		}
		cout<<ans<<'\n';
	}
}
