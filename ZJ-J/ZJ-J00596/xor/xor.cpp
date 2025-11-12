#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],k,n,xr[1010][1010],vis[1010],mx;
void count(int num,int n,int cnt);
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)cin >> a[i],xr[i][1]=a[i];
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n-i+1;j++){
			xr[i][j]=(int)xr[i][j-1]^a[i+j-1];
		}
	}
	int h_i=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(xr[i][j]==k)h_i++;
		}
	}
	cout << h_i;
	return 0;
}
