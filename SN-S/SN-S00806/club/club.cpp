#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,a[205][5],ans=0,n2;
void dfs(int x,int sum1,int sum2,int sum3,int sum){
	if(x==n){
		ans=max(ans,sum);
		return;
	}
	if(sum1!=n2){
		dfs(x++,sum1++,sum2,sum3,sum+=a[x][1]);
	}
	if(sum2!=n2){
		dfs(x++,sum1,sum2++,sum3,sum+=a[x][2]);	
	}
	if(sum3!=n2){
		dfs(x++,sum1,sum2,sum3++,sum+=a[x][3]);	
	}
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		} 
		n2=n/2;
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
	//fc club.out club.ans
}
