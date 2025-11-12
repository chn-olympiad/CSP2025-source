#include<bits/stdc++.h>
using namespace std;
int n,k,cnt=0,a[5000][5000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i][i];
	for(int j=1;j<=n;j++){
		for(int i=1;i<=j;i++){
			if(i==j)continue;
			a[i][j]=a[i][j-1]^a[j][j];
			//if(i==1&&j==2)cout<<a[i][j]<<"999"<<endl;
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=j;i++){
			if(a[i][j]==k)cnt++;
			//cout<<a[i][j];
		}
	}
	cout<<cnt<<endl;
	return 0;
}
