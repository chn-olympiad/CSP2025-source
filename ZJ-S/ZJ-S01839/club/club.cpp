#include<bits/stdc++.h>
using namespace std;
int a[100001][4];
int re[11],d[4];
int n,ans;
struct node{
	int ma,md,mi;
}m[100001];
void dfs(int step){
	if(step==n+1){
		int sum=0;
		for(int i=1;i<=n;i++) sum+=a[i][re[i]];
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(d[i]<(n/2)){
			re[step]=i;
			d[i]++;
			dfs(step+1);
			d[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n<=10) dfs(1);
		else{
			int d[4]={};
			for(int i=1;i<=n;i++){
				int te=-1,te2=1e9;
				for(int j=1;j<=3;j++){
					if(te<a[i][j]){
						m[i].ma=j;
						te=a[i][j];
					}
					if(te2>a[i][j]){
						m[i].mi=j;
						te2=a[i][j];
					}
				}
				for(int j=1;j<=3;j++){
					if(m[i].ma!=j&&m[i].mi!=j){
						m[i].md=j;
					}
				}
				if(d[m[i].ma]<(n/2)){
					d[m[i].ma]++;
					ans+=a[i][m[i].ma];
				}
				else if(d[m[i].md]<(n/2)){
					d[m[i].md]++;
					ans+=a[i][m[i].md];
				}
				else{
					d[m[i].mi]++;
					ans+=a[i][m[i].mi];
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
