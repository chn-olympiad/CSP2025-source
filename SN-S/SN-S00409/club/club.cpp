#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int a[N][5],n;
bool k[31][31][31];
int maxx(int a,int b,int c){
	return max(max(a,b),c);
}
int ma=0;
void dfs(int x,int a1,int a2,int a3,int p){
//	cout<<x<<" "<<a1<<" "<<a2<<" "<<a3<<" "<<p<<"\n";
//	if(p[a1][a2][a3])return;
//	p[1][2][3]=1;
	if(x==n+1){
		ma=max(ma,p);
		return;
	}
	if(a1<n/2)dfs(x+1,a1+1,a2,a3,p+a[x][1]);
	if(a2<n/2)dfs(x+1,a1,a2+1,a3,p+a[x][2]);
	if(a3<n/2)dfs(x+1,a1,a2,a3+1,p+a[x][3]);
}
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n>200){
			cout<<n/2;
			continue;
		}
//		memset(a,sizeof(a),0);
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}dfs(1,0,0,0,0);
		cout<<ma<<"\n";
		ma=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1

1
2
0 0 1
1 0 0
*/
