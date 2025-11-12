#include<bits/stdc++.h>
using namespace std;
int n,m,it=0,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	it=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[n*(i-1)+j]==it){
				if(i%2==1){
					cout<<i<<" "<<j<<"\n";
				}else{
					cout<<i<<" "<<n-j+1<<"\n";
				}
				return 0;
			}
		}
	}
	return 0;
}