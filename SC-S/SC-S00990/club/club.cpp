#include<bits/stdc++.h>
using namespace std;
const int A=1e5+5;
long long a[A][4],cnt[4];
long long sum,limit;
int n,t,maxn=-100;
void dfs(int p,long long l){
	if(p==n+1) {
	maxn=max(sum,maxn);return;	
	}	
	for(int i=p;i<=n;i++){
		for(int j=1;j<=3;j++){	
			if(cnt[j]<=l){
				sum+=a[i][j];
				cnt[j]++;
				dfs(p+1,l);
				sum-=a[i][j];
				cnt[j]--;
				}
			else return;
			}
		}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		limit=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
			cin>>a[i][j];
		}
		dfs(1,limit);
		cout<<maxn<<'\n';
		maxn=-100;
	}
	return 0;
}