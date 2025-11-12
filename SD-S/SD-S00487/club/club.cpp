#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][4],d[100005],cnt[4],sum;
int get2ndv(int a,int b,int c){
	if(a==b&&b==c)return b;
	if(a<=b&&b<=c||a>=b&&b>=c)return b;
	else if(b<=a&&a<=c||b>=a&&a>=c)return a;
	else return c;
}
int Min[100005],_cnt;
void solve(){
	sum=0;
	int minn=99999999;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=n;i++){
		int x=max(a[i][1],max(a[i][2],a[i][3]));
		for(int j=1;j<=3;j++)if(x==a[i][j])d[i]=x,cnt[x]++;
	}
	if(cnt[1]>n/2){
		minn=99999999;
		_cnt=0;
		for(int i=1;i<=n;i++){
			int x=max(a[i][1],max(a[i][2],a[i][3]));
			int y=get2ndv(a[i][1],a[i][2],a[i][3]);
			if(minn>x-y){
				for(int j=1;j<=3;j++){
					if(x==a[i][j])a[i][j]=-99999999;
				}
				minn=x-y,Min[++_cnt]=i;
			}
		}
	}
	if(cnt[2]>n/2){
		minn=99999999;
		_cnt=0;
		for(int i=1;i<=n;i++){
			int x=max(a[i][1],max(a[i][2],a[i][3]));
			int y=get2ndv(a[i][1],a[i][2],a[i][3]);
			if(minn>x-y){
				for(int j=1;j<=3;j++){
					if(x==a[i][j])a[i][j]=-99999999;
				}
				minn=x-y,Min[++_cnt]=i;
			}
		}
	}
	if(cnt[3]>n/2){
		minn=99999999;
		_cnt=0;
		for(int i=1;i<=n;i++){
			int x=max(a[i][1],max(a[i][2],a[i][3]));
			int y=get2ndv(a[i][1],a[i][2],a[i][3]);
			if(minn>x-y){
				for(int j=1;j<=3;j++){
					if(x==a[i][j])a[i][j]=-99999999;
				}
				minn=x-y,Min[++_cnt]=i;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int x=max(a[i][1],max(a[i][2],a[i][3]));
		for(int j=1;j<=3;j++)if(x==a[i][j])d[i]=x,cnt[x]++;
	}
	sum=0;
	for(int i=1;i<=n;i++){
		int x=max(a[i][1],max(a[i][2],a[i][3]));
		sum+=x;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<sum<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
