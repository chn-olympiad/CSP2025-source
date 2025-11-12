#include<bits/stdc++.h>
using namespace std;
long long n,a[4][100017],t,ans=0,sum=0,zs[300017];
bool flagtt=true;
void dfs(long long id,long long cnt1,long long cnt2,long long cnt3){
	if(id==n){
		ans=max(ans,sum);	
	}
	if(cnt1+1<=n/2){
		sum+=a[1][id+1];
		dfs(id+1,cnt1+1,cnt2,cnt3);
		sum-=a[1][id+1];
	}
	if(cnt2+1<=n/2){
		sum+=a[2][id+1];
		dfs(id+1,cnt1,cnt2+1,cnt3);
		sum-=a[2][id+1];
	}
	if(cnt3+1<=n/2){
		sum+=a[3][id+1];
		dfs(id+1,cnt1,cnt2,cnt3+1);
		sum-=a[3][id+1];
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		ans=0;
		flagtt=true;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]!=0||a[3][i]!=0){
				flagtt=false;
			}
		}
		if(flagtt){
			sort(a[1]+1,a[1]+n+1);
			for(int i=n/2+1;i<=n;i++){
				ans+=a[1][i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(n>=1000){
			for(int i=1;i<=n;i++){
				zs[i]=a[1][i];
			}
			for(int i=1;i<=n;i++){
				zs[i+n]=a[2][i];
			}
			for(int i=1;i<=n;i++){
				zs[i+2*n]=a[3][i];
			}
			sort(zs+1,zs+3*n+1);
			for(int i=2*n+1;i<=3*n;i++){
				ans+=zs[i];
			}
			cout<<ans<<endl;
			continue;
		}
		sum+=a[1][1];
		dfs(1,1,0,0);
		sum-=a[1][1];
		sum+=a[2][1];
		dfs(1,0,1,0);
		sum-=a[2][1];
		sum+=a[3][1];
		dfs(1,0,0,1);
		sum-=a[3][1];
		cout<<ans<<endl;
	}
	return 0;
}