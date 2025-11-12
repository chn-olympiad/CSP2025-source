#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[100005][5],k[100005];
void fun(int x,int n1,int n2,int n3,int num){
	if(x>n){
		ans=max(num,ans);
		return;
	}
	//cout<<x<<' '<<n1<<' '<<n2<<' '<<n3<<' '<<num<<endl;
	if(n1<n/2) fun(x+1,n1+1,n2,n3,num+a[x][1]);
	if(n2<n/2) fun(x+1,n1,n2+1,n3,num+a[x][2]);
	if(n3<n/2) fun(x+1,n1,n2,n3+1,num+a[x][3]);
	return;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int d1=0,d2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==3&&a[i][j]!=0) d2=1;
				if((j==3||j==2)&&a[i][j]!=0) d1=1;
			}
		}
		if(d1==0){
			ans=0;
			for(int i=1;i<=n;i++) k[i]=a[i][1];
			sort(k+1,k+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=k[i];
			cout<<ans<<endl;
		}else if(d2==0){
			ans=0;
			map<int,map<int,int> >dp;
			dp[1][0]=a[1][1];
			dp[0][1]=a[1][2];
			for(int i=2;i<=n;i++){
				for(int j=1;j<=i;j++){
					if(j*2>n||(i-j)*2>n||i-j<0) continue;
					if(i-j>0) dp[j][i-j]=max(dp[j-1][i-j]+a[i][1],dp[j][i-j-1]+a[i][2]);
					else dp[j][i-j]=dp[j-1][i-j]+a[i][1];
					ans=max(ans,dp[j][i-j]);
				}
			}
			cout<<ans<<endl;
		}else{
			ans=0;
			fun(1,0,0,0,0);
			cout<<ans<<endl;
		}
	
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
