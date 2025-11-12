#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],b[100005],max1[100005],max2[100005],wz1[100005],cnt[5],ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(max1,-0x3f,sizeof max1);
		memset(max2,-0x3f,sizeof max2);
		memset(b,0,sizeof b);
		memset(cnt,0,sizeof cnt);
		ans=0;
		for(long long i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>max1[i]){
					max2[i]=max1[i];
					max1[i]=a[i][j];
					wz1[i]=j;
				}
				else if(a[i][j]>max2[i]){
					max2[i]=a[i][j];
				}
			}
			cnt[wz1[i]]++;
			ans+=a[i][wz1[i]];
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
			cout<<ans<<endl;
		}
		else{
			long long wz=0,sum=0;
			if(cnt[1]>n/2)wz=1;
			else if(cnt[2]>n/2)wz=2;
			else wz=3;
			for(long long i=1;i<=n;i++){
				if(wz1[i]==wz){
					sum++;
					b[sum]=max1[i]-max2[i];
				}
			}
			sort(b+1,b+1+sum);
			for(long long i=1;cnt[wz]-i>=n/2;i++){
				ans-=b[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
