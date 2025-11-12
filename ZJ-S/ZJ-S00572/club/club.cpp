#include <bits/stdc++.h>
using namespace std;
int T,n,i,j,t,ma,ans,a[100010][4],f[4],fr[100010];
priority_queue <int, vector<int>, greater<int> > st;
void dfs(int t,int s){
	int i;
	if(t==n+1){
		ma=max(ma,s);
		return ;
	}
	for(i=1;i<=3;i++)
		if(f[i]+1<=n/2){
			f[i]++;
			dfs(t+1,s+a[t][i]);
			f[i]--;
		}
}
bool pd(){
	int i;
	for(i=1;i<=n;i++)
		if(a[i][2]!=0||a[i][3]!=0) return 0;
	return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)
			for(j=1;j<=3;j++)
				cin>>a[i][j];
		if(pd()){
			for(i=1;i<=n;i++) st.push(a[i][1]);
			while(!st.empty()) ++t,fr[t]=st.top(),st.pop();
			for(i=t;i>=t-n/2+1;i--) ans+=fr[i];
			cout<<ans<<"\n";
			ans=0;
			t=0;
			continue;
		}
		dfs(1,0);
		cout<<ma<<"\n";
		ma=0;
		memset(f,0,sizeof f);
	}
	return 0;
}