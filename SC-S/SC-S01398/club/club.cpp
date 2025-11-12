#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,a[maxn][4];
bool t1=0,t2=0,p[maxn];
int dfs(int j,int total,int k,int start,int cnt){
	if(k==n/2||start>n){
		if(j==3||(!t2&&j==2))return total;
		else {
			j++;
			start=0;
			k=0;
		}
	}
	int ma=0;
	for(int i=start;i<=n;i++){
		if(p[i])continue;
		p[i]=1;
		if(j==1)ma=max(dfs(j+1,total+a[i][j],0,0,cnt+1),ma);
		if(j==2&&cnt>=n/2)ma=max(dfs(j+1,total+a[i][j],0,0,cnt+1),ma);
		ma=max(dfs(j,total+a[i][j],k+1,i+1,cnt+1),ma);
		p[i]=0;
	}
	return ma;
}
void read(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]!=0&&(j==2||j==3)){
					t1=1;
					if(j==3)t2=1;
				}
			}
		}
		if(!t1){
			int temp[maxn];
			for(int i=1;i<=n;i++){
				temp[i]=a[i][1];
			}
			sort(temp+1,temp+n+1,greater<int>());
			int sum=0;
			for(int i=1;i<=n/2;i++)sum+=temp[i];
			cout<<sum<<"\n";
		}
		else {
			cout<<dfs(1,0,0,1,0)<<"\n";
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	read();
	
	return 0;
}