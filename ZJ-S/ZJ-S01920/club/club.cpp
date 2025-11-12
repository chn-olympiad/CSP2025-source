#include <bits/stdc++.h>
using namespace std;
int a[100010][6];
int cnt[6];
int clb[6][100010];
pair<int,int>pr[100010];
bool cmp(pair<int,int>p1,pair<int,int>p2){
	return p1.first>p2.first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		cnt[1]=cnt[2]=cnt[3]=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])cnt[1]++,clb[1][cnt[1]]=i;
			else if(a[i][2]>=a[i][3]&&a[i][2]>=a[i][1])cnt[2]++,clb[2][cnt[2]]=i;
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])cnt[3]++,clb[3][cnt[3]]=i;
		}
		int ans=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=cnt[i];j++){
				int pes=clb[i][j];
				ans+=a[pes][i];
			}
		}
//		for(int i=1;i<=3;i++){
//			cout<<cnt[i]<<"-";
//			for(int j=1;j<=cnt[i];j++){
//				cout<<clb[i][j]<<" ";
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//		cout<<"psd\n";
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
//				cout<<i<<":"<<cnt[i]<<endl;
				for(int j=1;j<=cnt[i];j++){
					int pes=clb[i][j];
//					cout<<i<<" "<<j<<" "<<clb[i][j]<<" "<<pes<<endl;
					int mx=0;
					for(int k=1;k<=3;k++)
					if(k!=i){
						mx=max(mx,a[pes][k]);
					}
					pr[j]=make_pair(a[pes][i]-mx,clb[i][j]);
				}
				sort(pr+1,pr+cnt[i]+1,cmp);
				for(int j=cnt[i];j>n/2;j--){
//					cout<<j<<" "<<pr[j].first<<endl;
					ans-=pr[j].first;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
