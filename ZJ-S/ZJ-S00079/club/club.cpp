#include<bits/stdc++.h>
using namespace std;
int a[100001][4],dp[100001],id[10001];
int bi(int a,int b,int c){
	return max(max(a,b),c);
}
int bi2(int a,int b,int c){
	if(a>=b){
		return a>=c?1:3;
	}else
	return c>=b?3:2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dp[1]=bi(a[1][1],a[1][2],a[1][3]);
		int sum[4]={};
		sum[bi2(a[1][1],a[1][2],a[1][3])]++;
		id[++cnt]=bi2(a[1][1],a[1][2],a[1][3]);
		int num[4]={};
		int j;
		int mn;
		for(int i=2;i<=n;i++){
			mn=1e9;
			int fl=0;
			if(sum[1]==n/2){
				fl=1;
				for(j=1;j<=cnt;j++){
					if(mn<min(a[j][1]-a[j][2],a[j][1]-a[j][3])&&id[j]==1){
						num[1]=bi2(1e9,a[j][2],a[j][3]);
						k=j;
						mn=min(a[j][2]-a[j][1],a[j][3]-a[j][1]);
					}
				}
			}
			else if(sum[2]==n/2){
				fl=2;
				for(j=1;j<=cnt;j++){
					if(mn<min(a[j][2]-a[j][1],a[j][2]-a[j][3])&&id[j]==2){
						k=j;
						num[2]=bi2(1e9,a[j][1],a[j][3]);
						mn=min(a[j][2]-a[j][1],a[j][2]-a[j][3]);
					}
				}
			}
			else if(sum[3]==n/2){
				fl=3;
				for(j=1;j<=cnt;j++){
					if(mn<min(a[j][3]-a[j][1],a[j][3]-a[j][2])&&id[j]==3){
						k=j;
						num[3]=bi2(0,a[j][1],a[j][2]);
						mn=min(a[j][3]-a[j][1],a[j][3]-a[j][2]);
					}
				}
			}else{
				dp[i]=dp[i-1]+bi(a[i][1],a[i][2],a[i][3]);
				sum[bi2(a[i][1],a[i][2],a[i][3])]++;
				id[cnt++]=bi2(a[i][1],a[i][2],a[i][3]);
				continue;
			}
			if(fl==1){
				dp[i]=dp[i-1]+bi(a[i][1]-mn,a[i][2],a[i][3]);
				id[++cnt]=bi2(a[i][1]-mn,a[i][2],a[i][3]);
				sum[id[cnt]]++;
				id[k]=num[1];
			}
			if(fl==2){
				dp[i]=dp[i-1]+bi(a[i][2]-mn,a[i][1],a[i][3]);
				id[++cnt]=bi2(a[i][2]-mn,a[i][1],a[i][3]);
				sum[num[2]]++;
				id[k]=num[2];
			}
			if(fl==3){
				dp[i]=dp[i-1]+bi(a[i][3]-mn,a[i][2],a[i][1]);
				id[++cnt]=bi2(a[i][3]-mn,a[i][2],a[i][1]);
				sum[num[3]]++;
				id[k]=num[3];
			}
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
