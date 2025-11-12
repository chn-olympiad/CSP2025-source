#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,sc;
}a[105];
int n,m,q[15][15],cnt;
bool cmp(node a,node b){
	return a.sc>b.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sc;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				q[i][j]=a[++cnt].id;
			}
		}else{
			for(int j=n;j>=1;j--){
				q[i][j]=a[++cnt].id;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(q[i][j]==1){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}

