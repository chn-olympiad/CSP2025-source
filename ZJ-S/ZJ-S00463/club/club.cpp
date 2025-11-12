#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;

int cnt[4];
int a[N][4];
int n,ans;
void dfs(int pos,int num){
	if(pos>n){
		ans=max(ans,num);
		return ;
	}
	//cout<<pos<<" "<<num<<"\n";
	if(cnt[1]<n/2){
		cnt[1]++;
		dfs(pos+1,num+a[pos][1]);
		cnt[1]--;
	}
	if(cnt[2]<n/2){
		cnt[2]++;
		dfs(pos+1,num+a[pos][2]);
		cnt[2]--;
	}
	if(cnt[3]<n/2){
		cnt[3]++;
		dfs(pos+1,num+a[pos][3]);
		cnt[3]--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		cnt[1]=cnt[2]=cnt[3]=0;
		dfs(1,0);
		cout<<ans<<"\n";
	}


	return 0;
}
