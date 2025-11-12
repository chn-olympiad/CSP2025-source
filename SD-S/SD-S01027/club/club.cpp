#include<bits/stdc++.h>
using namespace std;
int T,n,max1,mid1,min1,cop[7],flag1;
int a[100005][4],people[4][4],ans[100005]; 
long long dp[100005][4];
bool flaga,flagb;
//dpi,j   i去j时的ans
//peoplei,j  i:max,mid,min   j:j部门人数 
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		flaga=0;
		flagb=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++) people[i][j]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0) flaga=1;
			if(a[i][3]!=0) flagb=1;
		}
		
		if(flaga==0&&flagb==0){
			for(int i=1;i<=n;i++){
				ans[i]=a[i][1];
			}
			sort(ans+1,ans+n+1);
			int tot=0;
			for(int i=n;i>=n/2;i--){
				tot+=ans[i];
			}
			cout<<tot<<'\n';
			continue;
		}
		
		for(int i=1;i<=n;i++){
			flag1=0;
			if(dp[i-1][1]>=dp[i-1][2]){
				if(dp[i-1][1]>=dp[i-1][3]){
					max1=1;
					if(dp[i-1][2]>=dp[i-1][3]) mid1=2,min1=3;
					else mid1=3,min1=2;
				} 
				if(dp[i-1][1]<dp[i-1][3]){
					max1=3;
					mid1=1;
					min1=2;
				} 
			} 
			if(dp[i-1][1]<dp[i-1][2]){
				if(dp[i-1][2]>=dp[i-1][3]){
					max1=2;
					if(dp[i-1][1]>=dp[i-1][3]) mid1=1,min1=3;
					else mid1=3,min1=1;
				} 
				if(dp[i-1][2]<dp[i-1][3]){
					max1=3;
					mid1=2;
					min1=1;
				} 
		    }	
/*			if(a[i][1]>=a[i][2]){
				if(a[i][1]>=a[i][3]) fir2=1;
				if(a[i][1]<a[i][3]) fir2=3;
			}
			if(a[i][1]<a[i][2]){
				if(a[i][2]>=a[i][3]) fir2=2;
				if(a[i][2]<a[i][3]) fir2=3;
			}*/
			cop[1]=people[max1][1];
			cop[2]=people[max1][2];
			cop[3]=people[max1][3];
			cop[4]=people[mid1][1];
			cop[5]=people[mid1][2];
			cop[6]=people[mid1][3];
			for(int j=1;j<=3;j++){
				if(cop[j]<n/2){
					dp[i][j]=dp[i-1][max1]+a[i][j];
					people[j][1]=cop[1];
					people[j][2]=cop[2];
					people[j][3]=cop[3];
					people[j][j]++;
				}
				else{
					if(i>2){
						dp[i][j]=max(dp[i-2][mid1]+a[i][j],dp[i-1][max1]);
						if(dp[i-2][mid1]+a[i][j]<dp[i-1][max1]){
							flag1=j;
						}
						else{
							people[j][1]=cop[4];
							people[j][2]=cop[5];
							people[j][3]=cop[6];
							people[j][j]++;
						}
					}
					if(i<=2){
						dp[i][j]=max(dp[i-1][mid1]+a[i][j],dp[i-1][max1]);
						if(dp[i-1][mid1]+a[i][j]<dp[i-1][max1]){
							flag1=j;
						}
						else{
							people[j][1]=cop[4];
							people[j][2]=cop[5];
							people[j][3]=cop[6];
							people[j][j]++;
						}
					}	
				}
			}
			if(flag1==1){
				if(dp[i][2]>=dp[i][3]) for(int j=1;j<=3;j++) people[1][j]=people[2][j];
				else for(int j=1;j<=3;j++) people[1][j]=people[3][j];
			}
			if(flag1==2){
				if(dp[i][1]>=dp[i][3]) for(int j=1;j<=3;j++) people[2][j]=people[1][j];
				else for(int j=1;j<=3;j++) people[2][j]=people[3][j];				
			}
			if(flag1==3){
				if(dp[i][1]>=dp[i][2]) for(int j=1;j<=3;j++) people[3][j]=people[1][j];
				else for(int j=1;j<=3;j++) people[3][j]=people[2][j];
			}
	
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<'\n';		
	}
	return 0;
}
