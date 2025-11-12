#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200];
int s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
		//	cout<<j*n-n+i<<" "<<a[j*n-n+i]<<endl;
			if(a[j*n-n+i]==s){
				cout<<j<<" ";
				if(j%2){
					cout<<i;
				}
				else cout<<n-i+1;
			}
		}
	}
}