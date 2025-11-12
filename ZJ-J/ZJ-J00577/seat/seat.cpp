#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans[15][15],t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)t=a[i];
	}
	int nx=1,ny=0,now=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m/2;i++){
		nx=1;
		ny++;
		for(int j=1;j<=n;j++){
			//cout<<nx<<" "<<ny<<" "<<a[now]<<" "<<ans[nx][ny]<<endl;
			ans[nx][ny]=a[now];
			now++;
			nx++;
		}
		ny++;
		nx=n;
		for(int j=1;j<=n;j++){
			//cout<<nx<<" "<<ny<<" "<<a[now]<<" "<<ans[nx][ny]<<endl;
			ans[nx][ny]=a[now];
			now++;
			nx--;
		}
	}
	if(m%2==1){
		nx=1,ny=m;
		for(int j=1;j<=n;j++){
			ans[nx][ny]=a[now];
			now++;
			nx++;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<ans[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==t){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	
	return 0;
}
