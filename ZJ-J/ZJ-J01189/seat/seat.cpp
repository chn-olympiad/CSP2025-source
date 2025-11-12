#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000050],b[50][50],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int cnt=a[0];
	sort(a,a+n*m,cmp);
	int p=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[p];
				p++;
			}
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[p];
				p++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==cnt){
				cout<<j<<' '<<i;
				return 0;
				
			}
		}
	}
	return 0;
}

