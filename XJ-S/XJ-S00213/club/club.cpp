#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int arr[N][3];
typedef long long ll;
int n; 
ll ans;
void dfs (int d,int s1,int s2, int s3,ll sum){
//	cout <<d<<' '<<s1<<' '<<s2<<' '<<s3<<' '<<sum<<'\n';
	if (d==n+1){
		ans=max(ans,sum);
		return ;
	}
	if (s1<n/2){
		dfs(d+1,s1+1,s2,s3,sum+arr[d][1]);
	}
	if (s2<n/2){
		dfs(d+1,s1,s2+1,s3,sum+arr[d][2]);
	}
	if (s3<n/2){
		dfs(d+1,s1,s2,s3+1,sum+arr[d][3]);
	}
}
int main (){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	int t;
	scanf ("%d",&t);
	while (t--){
		ans=0;
		scanf ("%d",&n);
		bool fa=1,fb=1;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				cin >>arr[i][j];
			}
//			if (arr[3][i]!=0){
//				fb=0;
//				fa=0;
//			}
//			if (arr[2][i]!=0){
//				fa=0;
//			}
		}
//		if (fa){
//			sort(arr[1]+1,arr[1]+1+n,greater<int>());
//			ll sum=0;
//			for (int i=1;i<=n/2;i++){
//				sum+=arr[1][i];
//			}
//			cout  <<sum<<'\n';
//			continue;
//		}
		dfs(1,0,0,0,0);
		cout <<ans<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
