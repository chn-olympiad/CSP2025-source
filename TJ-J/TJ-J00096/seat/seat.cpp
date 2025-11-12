#include <bits/stdc++.h>
using namespace std;
int arr[105][105];
int n,m,a[1005],c,r,grade;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n >>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	grade=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1;
	bool flag=0;
	int cnt=1;
	for(int j=1;j<=m;++j){
		if(j%2==1){
			for(int i=1;i<=n;++i){
				arr[i][j]=a[cnt++];
			}
		}
		if(j%2==0){
			for(int i=n;i>=1;--i){
				arr[i][j]=a[cnt++];
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(arr[i][j]==grade){
				cout<<j<<' '<<i<<'\n';
			}
		}
	}
	return 0;
}
