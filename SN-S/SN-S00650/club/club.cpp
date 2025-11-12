#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans;
struct st{
	int val;
	int who;
	int to;
}a[300005];
int x[100005][5];
bool vis[100005];
vector<int> v[5];
bool cmp(st x,st y){
	return x.val>y.val;
}
bool cmp2(int x,int y){
	return x>y;
}
void dfs(int now,int cnt1,int cnt2,int cnt3,int sum){
	if(now>n){
		ans=max(ans,sum);
		return;
	}
	if(cnt1<n/2){
		dfs(now+1,cnt1+1,cnt2,cnt3,sum+x[now][1]);
	}
	if(cnt2<n/2){
		dfs(now+1,cnt1,cnt2+1,cnt3,sum+x[now][2]);
	}
	if(cnt3<n/2){
		dfs(now+1,cnt1,cnt2,cnt3+1,sum+x[now][3]);
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool flag=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>x[i][j];
				if(x[i][2]!=0||x[i][3]!=0){
					flag=false;
				}
			}
		}
		if(flag){
			vector<int> vv;
			for(int i=1;i<=n;i++){
				vv.push_back(x[i][1]);
			}
			sort(vv.begin(),vv.end(),cmp2);
			int cnt=0,res=0;
			for(int i=0;i<vv.size();i++){
				cnt++;
				if(cnt<=n/2){
					res+=vv[i];
				}
			}
			cout<<res<<"\n";
		}
		if(n<=10){
			ans=0;
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		int tot=0;
		int need=n/2;
		for(int i=1;i<=n;i++){
			vis[i]=false;
			if(i<=3){
				v[i].clear();
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[++tot]={x[i][j],i,j};
			}
		}
		sort(a+1,a+tot+1,cmp);
		for(int i=1;i<=n;i++){
			if(!vis[a[i].who]&&v[a[i].to].size()<need){
				v[a[i].to].push_back(a[i].val);
				vis[a[i].who]=true;
			}
		}
		int ans=0;
		for(int i=1;i<=3;i++){
			for(int j=0;j<v[i].size();j++){
				ans+=v[i][j];
			}
		}
		cout<<ans<<"\n";
	}
}
//priority
