#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],maxn=-1;
void dfs(int u,int sum,int p_1,int p_2,int p_3){
	if(u==n+1){
		maxn=max(maxn,sum);
		return ;
	}
	if(p_1<n/2){
		dfs(u+1,sum+a[u],p_1+1,p_2,p_3);
	}
	if(p_2<n/2){
		dfs(u+1,sum+b[u],p_1,p_2+1,p_3);
	}	
	if(p_3<n/2){
		dfs(u+1,sum+c[u],p_1,p_2,p_3+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		maxn=-1;
		cin>>n;
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=c[i]&&b[i]!=0){
				flag=false;
			}
		}
		if(flag==true){
			sort(a+1,a+n+1,greater<int>());
			long long sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i];
			}
			cout<<sum<<"\n";
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<maxn<<'\n';
	}
	return 0;
}