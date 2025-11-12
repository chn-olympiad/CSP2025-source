#include<bits/stdc++.h>
using namespace std;

int a[100005][4];
int t,n;
int maxn = -1; 
void solve1(int x,int y,int z,int sum,int now){
	if(x+y+z>=n){
		maxn = max(maxn,sum);
		return;
	}
	if(x<n/2){
		solve1(x+1,y,z,sum+a[now+1][1],now+1);
	}
	if(y<n/2){
		solve1(x,y+1,z,sum+a[now+1][2],now+1);
	}
	if(z<n/2){
		solve1(x,y,z+1,sum+a[now+1][3],now+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		solve1(0,0,0,0,0); 
		cout<<maxn<<"\n";
	}
	return 0;
}