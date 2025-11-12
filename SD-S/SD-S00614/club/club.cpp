#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100005;
ll a[N][5];
struct node{
	ll ans;
	ll ren[5];
}dp[N][5];
//ll ren[5];//选本项目的人数 
ll sum[5];//上一个选本项目的人的下标 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	scanf("%lld",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		ll n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		ll limit=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				ll ans1=dp[i-1][1].ans;
				ll ans2=dp[i-1][2].ans;
				ll ans3=dp[i-1][3].ans;
				ll maxx=max(ans1,max(ans2,ans3));
				if(maxx==ans1){
					
					ll ren1=dp[i-1][1].ren[j];
					
					if(ren1<limit){
						
						dp[i][j].ans=dp[i-1][1].ans+a[i][j];
						
						//dp[i][j].ren[j]++;
						dp[i][j].ren[j]=dp[i-1][1].ren[j]+1;
						sum[j]=i;
					}
					else{
						//ll maxx1=max(a[i][j],dp[sum[j]][j]-a[sum[j]][j]+a[i][j]);
						ll dpans1=dp[sum[j]][j].ans;
						ll dpans2=dp[sum[j]][j].ans-a[sum[j]][j]+a[i][j];
						ll ren2=dp[i-1][2].ren[j];
						ll ren3=dp[i-1][3].ren[j];
						
						if(ans2+a[i][j]>dpans1&&ans2+a[i][j]>dpans2&&ren2<limit&&ren2>=ren3){
							dp[i][j].ans=dp[i-1][2].ans+a[i][j];
							//dp[i][j].ren[j]++;
							dp[i][j].ren[j]=dp[i-1][2].ren[j]+1;
							sum[j]=i;
							continue;
						}
						if(ans3+a[i][j]>dpans1&&ans3+a[i][j]>dpans2&&ren3<limit&&ren3>ren2){
							dp[i][j].ans=dp[i-1][3].ans+a[i][j];
							//dp[i][j].ren[j]++;
							dp[i][j].ren[j]=dp[i-1][3].ren[j]+1;
							sum[j]=i;
							continue;
						}
						if(a[i][j]>dpans1){
							dp[i][j].ans=a[i][j];
							dp[i][j].ren[j]=1;
							sum[j]=i;
						}
						else{
							if(dpans2>dpans1){
								dp[i][j].ans=dp[sum[j]][j].ans-a[sum[j]][j]+a[i][j];
								dp[i][j].ren[j]=dp[sum[j]][j].ren[j];
								sum[j]=i;
							}
							else{
								dp[i][j].ans=dpans1;
								dp[i][j].ren[j]=dp[sum[j]][j].ren[j];
							}
						}
					}
				}
				else if(maxx==ans2){
					ll ren1=dp[i-1][2].ren[j];
					
					if(ren1<limit){
						
						dp[i][j].ans=dp[i-1][2].ans+a[i][j];
						//dp[i][j].ren[j]++;
						dp[i][j].ren[j]=dp[i-1][2].ren[j]+1;
						sum[j]=i;
					}
					else{
						//ll maxx1=max(a[i][j],dp[sum[j]][j]-a[sum[j]][j]+a[i][j]);
						
						ll dpans1=dp[sum[j]][j].ans;
						ll dpans2=dp[sum[j]][j].ans-a[sum[j]][j]+a[i][j];
						ll ren1=dp[i-1][1].ren[j];
						ll ren3=dp[i-1][3].ren[j];
						if(ans1+a[i][j]>dpans1&&ans1+a[i][j]>dpans2&&ren1<limit&&ren1>=ren3){
							dp[i][j].ans=dp[i-1][1].ans+a[i][j];
							//dp[i][j].ren[j]++;
							dp[i][j].ren[j]=dp[i-1][1].ren[j]+1;
							sum[j]=i;
							continue;
						}
						if(ans3+a[i][j]>dpans1&&ans3+a[i][j]>dpans2&&ren3<limit&&ren3>ren1){
							dp[i][j].ans=dp[i-1][3].ans+a[i][j];
							//dp[i][j].ren[j]++;
							dp[i][j].ren[j]=dp[i-1][3].ren[j]+1;
							sum[j]=i;
							continue;
						}
						if(a[i][j]>dpans1){
							dp[i][j].ans=a[i][j];
							dp[i][j].ren[j]=1;
							sum[j]=i;
						}
						else{
							//ll dpans2=dp[sum[j]][j].ans-a[sum[j]][j]+a[i][j];
							if(dpans2>dpans1){
								dp[i][j].ans=dp[sum[j]][j].ans-a[sum[j]][j]+a[i][j];
								dp[i][j].ren[j]=dp[sum[j]][j].ren[j];
								sum[j]=i;
							}
							else{
								dp[i][j].ans=dpans1;
								dp[i][j].ren[j]=dp[sum[j]][j].ren[j];
							}
						}
					}
				}
				else if(maxx==ans3){
					ll ren1=dp[i-1][3].ren[j];
					if(ren1<limit){
						dp[i][j].ans=dp[i-1][3].ans+a[i][j];
						//dp[i][j].ren[j]++;
						dp[i][j].ren[j]=dp[i-1][3].ren[j]+1;
						sum[j]=i;
					}
					else{
						//ll maxx1=max(a[i][j],dp[sum[j]][j]-a[sum[j]][j]+a[i][j]);
						ll dpans1=dp[sum[j]][j].ans;
						ll dpans2=dp[sum[j]][j].ans-a[sum[j]][j]+a[i][j];
						ll ren1=dp[i-1][1].ren[j];
						ll ren2=dp[i-1][2].ren[j];
						if(ans2+a[i][j]>dpans1&&ans2+a[i][j]>dpans2&&ren2<limit&&ren2>=ren1){
							dp[i][j].ans=dp[i-1][2].ans+a[i][j];
							//dp[i][j].ren[j]++;
							dp[i][j].ren[j]=dp[i-1][2].ren[j]+1;
							sum[j]=i;
							continue;
						}
						if(ans1+a[i][j]>dpans1&&ans1+a[i][j]>dpans2&&ren1<limit&&ren1>ren2){
							dp[i][j].ans=dp[i-1][1].ans+a[i][j];
							//dp[i][j].ren[j]++;
							dp[i][j].ren[j]=dp[i-1][1].ren[j]+1;
							sum[j]=i;
							continue;
						}
						if(a[i][j]>dpans1){
							dp[i][j].ans=a[i][j];
							dp[i][j].ren[j]=1;
							sum[j]=i;
						}
						else{
							ll dpans2=dp[sum[j]][j].ans-a[sum[j]][j]+a[i][j];
							if(dpans2>dpans1){
								dp[i][j].ans=dp[sum[j]][j].ans-a[sum[j]][j]+a[i][j];
								dp[i][j].ren[j]=dp[sum[j]][j].ren[j];
								sum[j]=i;
							}
							else{
								dp[i][j].ans=dpans1;
								dp[i][j].ren[j]=dp[sum[j]][j].ren[j];
							}
						}
					}
				}
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cout<<dp[i][j].ans<<" ";
			}
			cout<<endl;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					cout<<dp[i][j].ren[k]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}*/
		ll maxx1=dp[n][1].ans;
		ll maxx2=dp[n][2].ans;
		ll maxx3=dp[n][3].ans;
		printf("%lld\n",max(maxx1,max(maxx2,maxx3)));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
