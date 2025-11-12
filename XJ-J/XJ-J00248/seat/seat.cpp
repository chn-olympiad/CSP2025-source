#include<bits/stdc++.h>
using namespace std;
int n,m,d;
struct node{
	int score,id,i,j;
}a[110];
bool cmp(node x,node y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].score,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1) for(int j=1;j<=n;j++) a[++d].i=i,a[d].j=j;
		else for(int j=n;j>=1;j--) a[++d].i=i,a[d].j=j;
	}
	for(int i=1;i<=n*m;i++) if(a[i].id==1) cout<<a[i].i<<" "<<a[i].j;
	return 0;
}
