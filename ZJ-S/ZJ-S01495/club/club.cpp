#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010;

ll t;
ll n,up;
ll a[N][5],cnt[5],tmp[N];
ll ans,num;

void dfs(ll x){
	if(x>n){
		ans=max(ans,num);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<up){
			cnt[i]++;
			num+=a[x][i];
			dfs(x+1);
			cnt[i]--;
			num-=a[x][i];
		}
	}
}

bool cmp(ll x,ll y){
	return x>y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		bool flag=1;
		ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				if(a[i][j]!=0) flag=0;
			}
		}
		up=n/2;
		if(flag==1){
			for(int i=1;i<=n;i++){
				tmp[i]=a[i][1];
			}
			sort(tmp+1,tmp+1+n,cmp);
			for(int i=1;i<=up;i++){
				ans+=tmp[i];
			}
		}
		else{
			dfs(1);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
