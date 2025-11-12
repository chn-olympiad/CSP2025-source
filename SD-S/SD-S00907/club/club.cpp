#include<bits/stdc++.h>
#define intt long long
using namespace std;
intt t,n,a[1145141][5],ans;
intt cnt[10];
struct myst {
	intt dist;
	bool operator<(const myst &k)const {
		return k.dist<dist;
	}
};
priority_queue<myst>q1,q2,q3;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		ans=0;
		cnt[1]=0,cnt[2]=0,cnt[3]=0;
		while(!q1.empty()){
			q1.pop();
		}
		while(!q2.empty()){
			q2.pop();
		}
		while(!q3.empty()){
			q3.pop();
		}
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			intt maxx=0,maxind;
			for(int j=1; j<=3; j++) {
				if(a[i][j]>maxx) {
					maxx=a[i][j];
					maxind=j;
				}
			}
			intt max2=0,max2ind;
			for(int j=1; j<=3; j++) {
				if(a[i][j]>max2&&j!=maxind) {
					max2=a[i][j];
					max2ind=j;
				}
			}
			if(cnt[maxind]<n/2) {
				ans+=a[i][maxind];
				cnt[maxind]++;
				if(maxind==1)
					q1.push({maxx-max2});	
				else if(maxind==2)
					q2.push({maxx-max2});
				else
					q3.push({maxx-max2});
			} else {
				if(maxind==1) {
					if(a[i][maxind]-q1.top().dist>max2) {
						ans=ans+a[i][maxind]-q1.top().dist;
						q1.pop();
						q1.push({maxx-max2});
					}else ans+=max2;
				}
				if(maxind==2) {
					if(a[i][maxind]-q2.top().dist>max2) {
						ans=ans+a[i][maxind]-q2.top().dist;
						q2.pop();
						q2.push({maxx-max2});
					}else ans+=max2;
				}
				if(maxind==3) {
					if(a[i][maxind]-q3.top().dist>max2) {
						ans=ans+a[i][maxind]-q3.top().dist;
						q3.pop();
						q3.push({maxx-max2});
					}else ans+=max2;
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
