#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N][4],f[N],s[N];
priority_queue<int>q[3];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		while(!q[0].empty()) q[0].pop();
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			f[i]=s[i]=-1;
			for(int j=0;j<3;j++)
				if(f[i]==-1||a[i][j]>a[i][f[i]]){
					s[i]=f[i];
					f[i]=j;
				}
				else if(s[i]=='-1'||a[i][j]>a[i][s[i]]) s[i]=j;
		}
		for(int i=1;i<=n;i++)
			if(q[f[i]].size()<n/2){
				ans+=a[i][f[i]];
				q[f[i]].push(a[i][s[i]]-a[i][f[i]]);
			}
			else{
				int ans1=a[i][s[i]],ans2=q[f[i]].top()+a[i][f[i]];
				if(ans1>ans2) ans+=ans1;
				else{
					ans+=ans2;
					q[f[i]].pop();
					q[f[i]].push(a[i][s[i]]-a[i][f[i]]);
				}
			}
		cout<<ans<<'\n';
	}
	return 0;
}
