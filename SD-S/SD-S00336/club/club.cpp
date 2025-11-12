#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int t,n,a[maxn][5],wrk[5][maxn],cnt[5],ans;
void addwrk(int x){
	if(a[x][1]>=a[x][2] && a[x][1]>=a[x][3]){
		cnt[1]++;
		wrk[1][cnt[1]]=min(a[x][1]-a[x][2],a[x][1]-a[x][3]);
		return ;
	}
	if(a[x][2]>=a[x][1] && a[x][2]>=a[x][3]){
		cnt[2]++;
		wrk[2][cnt[2]]=min(a[x][2]-a[x][1],a[x][2]-a[x][3]);
		return ;
	}
	if(a[x][3]>=a[x][1] && a[x][3]>=a[x][2]){
		cnt[3]++;
		wrk[3][cnt[3]]=min(a[x][3]-a[x][1],a[x][3]-a[x][2]);
		return ;
	}
	return;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		cnt[1]=0,cnt[2]=0,cnt[3]=0;
		for(int i=1;i<=n;i++){
			a[i][1]=0,a[i][2]=0,a[i][3]=0;
			wrk[1][i]=0,wrk[2][i]=0,wrk[3][i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			addwrk(i);
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				sort(wrk[i]+1,wrk[i]+cnt[i]+1,cmp);
				for(int j=cnt[i];j>n/2;j--){
					ans-=wrk[i][j];
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//wyz bless me
