#include<bits/stdc++.h>
using namespace std;
long long m;
long long st[100000][4];
long long maxn;
long long ans=0;
 long long n[4];
void DFS(int dep){
	if(dep>m){
		maxn=max(maxn,ans);
		return;
	}else{
		for(int i=1;i<=3;i++){
			if(n[i]+1>m/2){
				continue;
			}else{
				ans+=st[dep][i];
				n[i]++;
				DFS(dep+1);
				n[i]--;
				ans-=st[dep][i];
			}
		}
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>m;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=3;j++){
				cin>>st[i][j];
			}
		}
		for(int i=1;i<=4;i++){
			n[i]=0;
		}
		maxn=0;
		DFS(1);
		cout<<maxn<<endl;
	}
}

