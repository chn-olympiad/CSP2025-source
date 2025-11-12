#include<bits/stdc++.h>
using namespace std;
struct F{
	int num;
	int f;
	int YG;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,ans=0,sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int temp;
				cin>>temp;
				a[sum].f=temp;
				a[sum].YG=i;
				a[sum].num=j;
				sum++;
			}	
		}
		if(n==2){
			for(int i=0;i<sum-1;i++){
				for(int j=1;j<sum;j++){
					if(a[i].YG==a[j].YG)continue;
					int cnt[]={0,0,0,0};
					cnt[a[i].num]++;
					cnt[a[j].num]++;
					bool falg=0;
					for(int k=1;k<=3;k++)if(cnt[k]>1)falg=1;
					if(falg)continue;
					ans=max(ans,a[i].f+a[j].f);
				}
			}
			cout<<ans<<endl;
		}
		if(n==4){
			for(int i=0;i<sum-3;i++){
				for(int j=1;j<sum-2;j++){
					for(int x=2;x<sum-1;x++){
						for(int z=3;z<sum;z++){
							if(a[i].YG==a[j].YG||a[i].YG==a[x].YG||a[i].YG==a[z].YG||a[j].YG==a[x].YG||a[j].YG==a[z].YG||a[x].YG==a[z].YG)continue;
							int cnt[]={0,0,0,0};
							cnt[a[i].num]++;
							cnt[a[j].num]++;
							cnt[a[x].num]++;
							cnt[a[z].num]++;
							bool falg=0;
							for(int k=1;k<=3;k++)if(cnt[k]>2)falg=1;
							if(falg)continue;
							ans=max(ans,a[i].f+a[j].f+a[x].f+a[z].f);
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

