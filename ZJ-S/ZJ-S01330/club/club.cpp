#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int st[3];
int a[N][3];
int n,m,ma;
void dfs(int c,int sum){
	if(c>n){
		ma=max(ma,sum);
	}
	for(int i=1;i<=3;i++){
		if(st[i]<m){
			st[i]++;
			dfs(c+1,sum+a[c][i]);
			st[i]--;
		}
	} 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int cnt1=0,cnt2=0;
		ma=0;
		memset(a,0,sizeof a);
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			if(a[i][3]==0&&a[i][2]==0) cnt1++;
			else if(a[i][3]==0) cnt2++;
		}
		if(cnt1==n){
			sort(a[1],a[1]+n);
			for(int i=1;i<=m;i++){
				ma+=a[i][1];
			}
		}else{
			dfs(1,0);
		}
		cout<<ma<<"\n";
	}
	return 0;
}
