#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,a[N][10],k,f[N];
int ans;
priority_queue<int>q;
void dfs(int h,int sum){
	if(h>n){
		ans=max(ans,sum);
		return ;
	}
	if(f[1]<k){
		f[1]++;
		dfs(h+1,sum+a[h][1]);
		f[1]--;
	}
	if(f[2]<k){
		f[2]++;
		dfs(h+1,sum+a[h][2]);
		f[2]--;
	}
	if(f[3]<k){
		f[3]++;
		dfs(h+1,sum+a[h][3]);
		f[3]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		k=n/2;
		int maxx2=0,maxx3=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				f[j]=0;
				cin>>a[i][j];
				if(j==2)maxx2=max(maxx2,a[i][j]);
				if(j==3)maxx3=max(maxx3,a[i][j]);
			}
		}
		ans=0;
		if(maxx2==0&&maxx3==0){
			while(!q.empty())q.pop();
			for(int i=1;i<=n;++i)q.push(a[i][1]);
			int sum=0;
			while(!q.empty()){
				sum++;
				if(sum>k)break;
				int u=q.top();q.pop();
				ans+=u;
			} 
			cout<<ans<<endl; 
		}
		else{
			dfs(0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
