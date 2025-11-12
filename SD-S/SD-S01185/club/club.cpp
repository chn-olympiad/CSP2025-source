#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,hol=-1000000000;
int n,t,hen1,hen2,hen3;
long long a[N][5],dp[N][5],sum,ans,dp2[205][205][205];
bool pf=1;
void dfs(int x){
	if(x==1+n){
		ans=max(ans,sum);return;
	}if(hen1!=n/2){
		hen1++;sum+=a[x][1];dfs(x+1);
		hen1--;sum-=a[x][1];
	}if(hen2!=n/2){
		hen2++;sum+=a[x][2];dfs(x+1);
		hen2--;sum-=a[x][2];
	}if(hen3!=n/2){
		hen3++;sum+=a[x][3];dfs(x+1);
		hen3--;sum-=a[x][3];
	}
}vector<int> vec;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=sum=hen1=hen2=hen3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			dp[i][1]=dp[i][2]=dp[i][3]=hol;
			if(a[i][2]!=0||a[i][3]!=0)pf=0;
		}if(pf){
			vec.clear();
			vec.push_back(-114514);
			for(int i=1;i<=n;i++){
				vec.push_back(a[i][1]);
			}sort(vec.begin(),vec.end());
			for(int i=n;i>n/2;i--){
				ans+=vec[i];
			}cout<<ans<<"\n";
			continue;
		}if(n<=10){
			dfs(1);cout<<ans<<"\n";continue;
		}else if(n<=200){
			for(int k=0;k<=n;k++){
				for(int i=0;i<=n;i++){
					for(int j=0;j<=n;j++){
						dp2[k][i][j]=-1e9;
					}
				}	
			}
			dp2[0][0][0]=0;
			for(int i=1;i<=n;i++){
				for(int A=n/2;A>=0;A--){
					for(int B=n/2;B>=0;B--){
						if(i-A-B<0)continue;
						if(A!=0){
							dp2[i][A][B]=max(dp2[i][A][B],dp2[i-1][A-1][B]+a[i][1]);
						}if(B!=0){
							dp2[i][A][B]=max(dp2[i][A][B],dp2[i-1][A][B-1]+a[i][2]);
						}dp2[i][A][B]=max(dp2[i][A][B],dp2[i-1][A][B]+a[i][3]);
					}
				}
			}for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					if(i+j<n/2)continue;
					ans=max(ans,dp2[n][i][j]);
				}
			}cout<<ans<<"\n";continue;
		}else{
			for(int i=1;i<=n;i++){
				dp[i][1]=max({dp[i-1][1],dp[i-1][2],dp[i-1][3]})+a[i][1];
				dp[i][2]=max({dp[i-1][1],dp[i-1][2],dp[i-1][3]})+a[i][2];
				dp[i][3]=max({dp[i-1][1],dp[i-1][2],dp[i-1][3]})+a[i][3]; 
			}cout<<max({dp[n][1],dp[n][2],dp[n][3]})<<"\n";
		}
	}
	return 0;
}


