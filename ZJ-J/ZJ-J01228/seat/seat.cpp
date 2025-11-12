#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
	bool id;
	int x;
}a[110];
int ord[20][20];
bool cmp(stu xx,stu yy){
	return xx.x>yy.x;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		if(i==1) a[i].id=1;
		else a[i].id=0;
	}
	sort(a+1,a+1+n*m,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				ord[i][j]=++cnt;
			}			
		}else{
			for(int j=n;j>=1;j--){
				ord[i][j]=++cnt;
			}			
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[ord[i][j]].id==1){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
