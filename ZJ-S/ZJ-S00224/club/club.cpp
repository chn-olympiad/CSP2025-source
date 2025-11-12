#include <bits/stdc++.h>
#define fr1(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define baka cout<<p.first<<" "<<p.second<<" "<<sum[1]<<" "<<sum[2]<<" "<<sum[3]<<" "<<sum[0]<<endl
using namespace std;
const int maxn=1e5+10;
int n,sum[4];
map<int,int> a[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		sum[0]=0,sum[1]=0,sum[2]=0,sum[3]=0;
		cin>>n;
		fr1(i,1,n){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])a[i][0]=1,a[i][2]-=a[i][1],a[i][3]-=a[i][1],sum[0]+=a[i][1],sum[1]++;
		if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])a[i][0]=2,a[i][1]-=a[i][2],a[i][3]-=a[i][2],sum[0]+=a[i][2],sum[2]++;
		if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])a[i][0]=3,a[i][2]-=a[i][3],a[i][1]-=a[i][3],sum[0]+=a[i][3],sum[3]++;
		}
//		fr1(i,1,n)cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<endl;
		while(sum[1]>n/2||sum[2]>n/2||sum[3]>n/2){
			while(sum[1]>n/2){
				int maxn=-0x3f3f3f3f;
				pair<int,int>p;
				fr1(i,1,n){
					if(a[i][0]!=1)continue;
					if(a[i][2]>maxn&&a[i][2]!=3507)maxn=a[i][2],p={i,2};
					if(a[i][3]>maxn&&a[i][3]!=3507)maxn=a[i][3],p={i,3};
				}
				sum[0]+=a[p.first][p.second],a[p.first][0]=p.second,a[p.first][1]=3507,sum[1]--,sum[p.second]++;
//				baka;
			}
			while(sum[2]>n/2){
				int maxn=-0x3f3f3f3f;
				pair<int,int> p;
				fr1(i,1,n){
					if(a[i][0]!=2)continue;
					if(a[i][1]>maxn&&a[i][1]!=3507)maxn=a[i][1],p={i,1};
					if(a[i][3]>maxn&&a[i][3]!=3507)maxn=a[i][3],p={i,3};
				}
				sum[0]+=a[p.first][p.second],a[p.first][0]=p.second,a[p.first][2]=3507,sum[2]--,sum[p.second]++;
//				baka;
			}
			while(sum[3]>n/2){
				int maxn=-0x3f3f3f3f;
				pair<int,int>p;
				fr1(i,1,n){
					if(a[i][0]!=3)continue;
					if(a[i][2]>maxn&&a[i][2]!=3507)maxn=a[i][2],p={i,2};
					if(a[i][1]>maxn&&a[i][1]!=3507)maxn=a[i][1],p={i,1};
				}
				sum[0]+=a[p.first][p.second],a[p.first][0]=p.second,a[p.first][3]=3507,sum[3]--,sum[p.second]++;
//				baka;
			}
		}
		cout<<sum[0]<<endl;
	}
	return 0;
}
