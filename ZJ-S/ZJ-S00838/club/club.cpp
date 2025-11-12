#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e5+10;
int a[maxn][10],n,mx[maxn],ans;
vector<int> v1,v2,v3;
void dfs(int now,int sum,int c1,int c2,int c3){
	if(now==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(c1==n/2){
		dfs(now+1,sum+a[now][2],c1,c2+1,c3);
		dfs(now+1,sum+a[now][3],c1,c2,c3+1);
	}else if(c2==n/2){
		dfs(now+1,sum+a[now][1],c1+1,c2,c3);
		dfs(now+1,sum+a[now][3],c1,c2,c3+1);
	}else if(c3==n/2){
		dfs(now+1,sum+a[now][2],c1,c2+1,c3);
		dfs(now+1,sum+a[now][1],c1+1,c2,c3);
	}else{
		dfs(now+1,sum+a[now][1],c1+1,c2,c3);
		dfs(now+1,sum+a[now][2],c1,c2+1,c3);
		dfs(now+1,sum+a[now][3],c1,c2,c3+1);
	}
}
void solve(){
	cin>>n;
	int sum=0;
	ans=0;
	v1.clear();
    v2.clear();
    v3.clear();
	bool flag1=true,flag2=true,flag3=true;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		v1.push_back(a[i][1]);
        v2.push_back(a[i][2]);
        v3.push_back(a[i][3]);
		if(a[i][2]>0 || a[i][3]>0) flag1=false;
        if(a[i][1]>0 || a[i][3]>0) flag2=false;
        if(a[i][1]>0 || a[i][2]>0) flag3=false;
	}
	if(flag1){
        sort(v1.begin(),v1.end()+1);
		for(int i=n/2;i<n;i++) sum+=v1[i];
		cout<<sum<<endl;
		return ;
	}
    if(flag2){
        sort(v2.begin(),v2.end()+1);
		for(int i=n/2;i<n;i++) sum+=v2[i];
		cout<<sum<<endl;
		return ;
	}
    if(flag3){
        sort(v3.begin(),v3.end()+1);
		for(int i=n/2;i<n;i++) sum+=v3[i];
		cout<<sum<<endl;
		return ;
	}
	dfs(1,0,0,0,0);
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
