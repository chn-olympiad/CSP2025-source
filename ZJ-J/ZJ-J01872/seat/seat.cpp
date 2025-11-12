#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int y=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int ss[15][15];
	int x=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ss[j][i]=a[x++];
				if(ss[j][i]==y){
					cout<<i<<' '<<j;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				ss[j][i]=a[x++];
				if(ss[j][i]==y){
					cout<<i<<' '<<j;
				}
			}
		}
	}
	return 0;
}
