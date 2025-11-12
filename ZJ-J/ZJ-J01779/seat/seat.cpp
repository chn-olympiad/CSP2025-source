#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int n,m,N;
struct node{
	int mark;
	int id;
}a[210];
bool cmp(node x,node y){
	return x.mark>=y.mark;
}
int mp[210][210];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	N=n*m;
	for(int i=1;i<=N;i++){
		cin>>a[i].mark;
		a[i].id=i;
	}
	sort(a+1,a+1+N,cmp);
	int top=0;
	for(int i=1;i<=m;i++){
		if(i&1) for(int j=1;j<=n;j++) mp[j][i]=a[++top].id;
		else for(int j=n;j>=1;j--) mp[j][i]=a[++top].id;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==1) cout<<j<<" "<<i;
		}
	}
	return 0;
}
