#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int xy[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	sort(a+1,a+n*m+1);
	int yn=n*m;
	for(int i=1;i<=n*m;i++){
		b[i]=a[yn];
		yn--;
	}
	int num=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				xy[i][j]=b[num];
				num++;
			}
		}else{
			for(int j=1;j<=n;j++){
				xy[i][j]=b[num];
				num++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(xy[j][i]==cnt){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}