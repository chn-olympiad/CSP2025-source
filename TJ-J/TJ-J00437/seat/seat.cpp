#include<bits/stdc++.h>
using namespace std;
int n,m,len,xy;
int arr[100005];
int maps[105][105];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>arr[i];
		if(i==1) xy=arr[i];
		len++;
	}
	sort(arr+1,arr+len+1,cmp);
//	for(int i=1; i<=len; i++) {
//		cout<<arr[i]<<' ';
//	}
	int x=1,y=1,sum=len+1;
	while(len!=0) {
		if(y%2==1) {
			if(x==n) {
				maps[x][y]=arr[sum-len];
				y++;
				len--;
				continue;
			}
			maps[x][y]=arr[sum-len];
			x++;
			len--;
		}
		if(y%2==0) {
			if(x==1) {
				maps[x][y]=arr[sum-len];
				y++;
				len--;
				continue;
			}
			maps[x][y]=arr[sum-len];
			x--;
			len--;
		}
	}

//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=m; j++) {
//			cout<<maps[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(maps[i][j]==xy) {
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
}
