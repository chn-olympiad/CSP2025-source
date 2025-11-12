#include<bits/stdc++.h>
using namespace std;
int n,m,flag=1,x=1,y=1,b[15][15],l;
struct Node{
	int sc,idx;
}a[105];
bool cmp(Node a,Node b){
	return a.sc>b.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].sc,a[i].idx=i;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				b[j][i]=a[++l].idx;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[++l].idx;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==1)return cout<<j<<" "<<i,0;
		}
	}
	return 0;
}