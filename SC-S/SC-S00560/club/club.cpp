#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],num[5],ans,flag[100005];
pair <int,int> b[5][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(b,0,sizeof(b));
		memset(num,0,sizeof(num));
		memset(flag,0,sizeof(flag));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			int l;
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				ans+=a[i][1],num[1]++,l=1;
				b[1][num[1]]={a[i][1],i};
			}else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				ans+=a[i][2],num[2]++,l=2;
				b[2][num[2]]={a[i][2],i};
			}else{
				ans+=a[i][3],num[3]++,l=3;
				b[3][num[3]]={a[i][3],i};
			}
			if(num[l]>n/2){
				int max_=-1e9,min_i;
				for(int j=1;j<=num[l];j++){
					for(int z=1;z<=3;z++){
						if(z!=l && flag[b[l][j].second]==0 && a[b[l][j].second][z]-b[l][j].first>max_){
							max_=a[b[l][j].second][z]-b[l][j].first,min_i=b[l][j].second;
							//b[l][j]={1e9,0};
						}
					}
				}
				flag[min_i]=1;
				ans+=max_;
				//cout<<ans<<' '<<min_i<<' '<<i<<' '<<max_<<endl;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}