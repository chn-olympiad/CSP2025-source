#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,vis[100][100],b;
struct node{
	int s,id;
}a[110];
bool cmp(node q,node h){
	return q.s>h.s;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s; a[i].id=i;
	}
	b=a[1].s;
	sort(a+1,a+1+n*m,cmp);
	int k=1;
	for(int j=1;j<=m;j++){
		if(j%2){
			for(int i=1;i<=n;i++) vis[i][j]=k++;
		}else{
			for(int i=n;i>=1;i--) vis[i][j]=k++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[vis[i][j]].s==b){
				return cout<<j<<" "<<i,0;
			}
		}
	}
	return 0;
}