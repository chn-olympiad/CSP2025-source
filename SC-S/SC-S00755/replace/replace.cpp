#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	while(1){
		cout<<1;
	}
}
#if 0
#include<bits/stdc++.h>
using namespace std;
int t,n,a[12][4];
int c[4];
int ans;
void dfs(int x,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(c[i]==n/2)continue;
		c[i]++;
		dfs(x+1,sum+a[x][i]);
		c[i]--;
	}
}
void solve(){
	cin>>n;
	c[1]=c[2]=c[3]=0;ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	dfs(1,0);
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	
	cin>>t;
	while(t--)solve();

    srand(time(0));
	int t=200;
	cout<<t<<"\n";
	while(t--){
		cout<<"10\n";
		int n=10;
		for(int i=1;i<=n;i++){
			cout<<rand()%200+1<<" ";
			cout<<rand()%200+1<<" ";
			cout<<rand()%200+1<<"\n";
		}
	}
}
#endif