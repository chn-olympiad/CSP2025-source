#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
int a[N][4];
int b[N];
int cnt[4],num;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		num=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int y=-1,ma=-1;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>ma){
					ma=a[i][j];
					y=j;
				}
			}
			ans+=ma;
			cnt[y]++;
		}
		int t;
		if(cnt[1]>cnt[2]&&cnt[1]>cnt[3])t=1;
		if(cnt[2]>cnt[1]&&cnt[2]>cnt[3])t=2;
		if(cnt[3]>cnt[1]&&cnt[3]>cnt[2])t=3;
		if(cnt[t]>n/2){
			for(int i=1;i<=n;i++){
				int y=-1,ma1=-1,ma2=-1;
				for(int j=1;j<=3;j++){
					if(a[i][j]>ma1){
						ma2=ma1;
						ma1=a[i][j];
						y=j;
					}else{
						if(a[i][j]>ma2){
							ma2=a[i][j];
						}
					}
				}
				if(y==t){
					b[++num]=ma1-ma2;
				}
			}
			sort(b+1,b+num+1);
			for(int i=1;i<=num-n/2;i++)ans-=b[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}