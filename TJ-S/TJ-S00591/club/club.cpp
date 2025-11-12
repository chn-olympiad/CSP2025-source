#include<bits/stdc++.h>
using namespace std;
int a[300011][4];
int b[4];
int n;
long long ma;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int k,long long sum){
	if(k>n){
		if(sum>ma){
			ma=sum;
		}
	}else{
		for(int i=1;i<=3;i++){
			if(b[i]+1<=n/2){
				b[i]++;
				dfs(k+1,sum+a[k][i]);
				b[i]--;
			}
		}
	}
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ma=0;
		b[1]=0;b[2]=0;b[3]=0;
		cin>>n;
		if(n>200){
			int c[300011];
			int x,y;
			for(int i=1;i<=n;i++){
				cin>>c[i]>>x>>y;
			}
			sort(c+1,c+n+1,cmp);
			long long s=0;
			for(int i=1;i<=n/2;i++){
				s+=c[i];
			}
			cout<<s<<'\n';
		}else{
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			dfs(1,0);
			cout<<ma<<'\n';
		}	
	}
	return 0;
}
