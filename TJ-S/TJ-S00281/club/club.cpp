#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t,n,a[N][4],v[N],maxx=-1,spA,spB,c[N];
void build(){
	maxx=-1;
}
void dfs(int i,int ans){
	if(i==n+1){
		maxx=max(maxx,ans);
		return ;
	}
	for(int j=1;j<=3;j++){
		if(v[j]>=n/2) continue;
		v[j]++;
		ans+=a[i][j];
		dfs(i+1,ans);
		v[j]--;
		ans-=a[i][j]; 
	}
}
void Solve3(){
	dfs(1,0);
	cout<<maxx<<'\n';
}
void Solve1(){
	maxx=0;
	for(int i=1;i<=n;i++){
		c[i]=a[i][1];
	}
	sort(c+1,c+n+1);
	for(int i=n;i>=n/2+1;i--){
		maxx+=c[i];
	}
	cout<<maxx<<'\n';
}
void Solve2(){
	
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		build();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			spA=max(a[i][2],max(spA,a[i][3]));
			spB=max(spB,a[i][3]);
		}
		if(spA==0) Solve1();
		else if(spB==0) Solve2();
		else Solve3();
	}
	return 0;
}

