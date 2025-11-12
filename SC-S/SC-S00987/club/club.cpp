#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[203330][4];
int s[203330][4];
//     i    A    B 

int n;
ll ans=0;
void sleep(int t){
	int k=1000;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=t;j++)k++,k--;
}
typedef  pair<pair<int,ll>,pair<int,int> > ppppir;

map<ppppir,bool>mp;
void dfs(int i,ll now,int A,int B){
//	cout<<i<<" "<<now<<" "<<A<<" "<<B<<" \n";
//		sleep(10000);
	if(mp.count({{i,now},{A,B}})==1){return;}
	mp[{{i,now},{A,B}}]=1;
//	ll maxx=now+s[n][0]-s[i][0];
//	if(maxx<=ans)return;
	if(i==n+1){
		ans=max(ans,now);
		return;
	}
	if(A+1<=n/2){
		dfs(i+1,now+a[i][1],A+1,B);
	}
	if(B+1<=n/2){
		dfs(i+1,now+a[i][2],A,B+1);
	}
	if(i-A-B<=n/2){
		dfs(i+1,now+a[i][3],A,B);
	}
}
int sts[203030];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		ll sum[4];
		for(int i=1 ;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				sum[j]+=a[i][j];
				s[i][j]=s[i-1][j]+a[i][j];
			}
			s[i][0]=s[i-1][0]+max({a[i][1],a[i][2],a[i][3]});
		}
		if(n<=200){
			dfs(1,0,0,0);
			mp.clear();
			cout<<ans<<endl;
			ans=0;
		}
		else{
			if(sum[2]==sum[3] and sum[2]==0){
				for(int i=1;i<=n;i++)sts[i]=a[i][1];
				sort(sts+1,sts+1+n,greater<int>());
				ans=0;
				for(int i=1;i<=n/2;i++)ans+=sts[i];
				cout<<ans;
			}
			
			
		}
		
	}
	return 0;
}

