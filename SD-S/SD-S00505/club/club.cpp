#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int a[N][4];
int wl[N];
int cnt[4];
int ans=0;int n,m;
void dfs(int x,int k){
	if(x>n){
		ans=max(ans,k);
		return ;
	}
	if(cnt[1]<m){
		cnt[1]++;
		dfs(x+1,k+a[x][1]);
		cnt[1]--;
	}
	if(cnt[2]<m){
		cnt[2]++;
		dfs(x+1,k+a[x][2]);
		cnt[2]--;
	}
	if(cnt[3]<m){
		cnt[3]++;
		dfs(x+1,k+a[x][3]);
		cnt[3]--;
	}
	
}
signed main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	int tp1=0,tp2=0,tp3=0;
	while(t--){
		ans=0;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			tp1+=a[i][1];tp2+=a[i][2];tp3+=a[i][3];
		}
		if(tp1==0&&tp2==0){
			for(int i=1;i<=n;i++)wl[i]=a[i][3];
			sort(wl+1,wl+n+1,greater<int>());
			for(int i=1;i<=m;i++)ans+=wl[i];
		}
		else if(tp2==0&&tp3==0){
			for(int i=1;i<=n;i++)wl[i]=a[i][1];
			sort(wl+1,wl+n+1,greater<int>());
			for(int i=1;i<=m;i++)ans+=wl[i];
		}
		else if(tp1==0&&tp3==0){
			for(int i=1;i<=n;i++)wl[i]=a[i][2];
			sort(wl+1,wl+n+1,greater<int>());
			for(int i=1;i<=m;i++)ans+=wl[i];
		}
		else{
			dfs(1,0);
		}
		
		cout<<ans<<'\n';
	}
	return 0; 
}


