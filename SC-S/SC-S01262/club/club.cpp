#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][5];
int a1[100005];
int a2[100005];
int a3[100005];
int x;
int ans=0;
void dfs(int ii,int ai,int b,int c,int zhi){
	if(ii==n){
		ans=max(ans,zhi);
		return;
	}
	if(ai<x){
		dfs(ii+1,ai+1,b,c,zhi+a[ii][1]);
	}
	if(b<x){
		dfs(ii+1,ai,b+1,c,zhi+a[ii][2]);
	}
	if(c<x){
		dfs(ii+1,ai,b,c+1,zhi+a[ii][3]);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int f1=0,f2=0,f3=0;
		for(int i=0;i<n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a1[i]=a[i][1];
			a2[i]=a[i][2];
			a3[i]=a[i][3];
			if(a[i][1]!=0){
				f1=1;
			}if(a[i][2]!=0){
				f2=1;
			}if(a[i][3]!=0){
				f3=1;
			}
		}
		if(f1==0&&f2==1&&f3==1){
			sort(a1,a1+n);
			long long ans=0;
			for(int i=n-1;i>=n/2;i--){
				ans+=a1[i];
			}
			cout<<ans<<endl;
		}else if(f1==0&&f2==1&&f3==0){
			sort(a2,a2+n);
			long long ans=0;
			for(int i=n-1;i>=n/2;i--){
				ans+=a2[i];
			}
			cout<<ans<<endl;
		}else if(f1==0&&f2==0&&f3==1){
			sort(a3+1,a3+1+n);
			long long ans=0;
			for(int i=n-1;i>=n/2;i--){
				ans+=a3[i];
			}
			cout<<ans<<endl;
		}else{
			x=n/2;
			ans=0;
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}