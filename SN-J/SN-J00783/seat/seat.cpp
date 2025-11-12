#include<bits/stdc++.h>
using namespace std;
int n,m,n_,m_,l;
int a[15][15];
int cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(cnt==1){
				l=a[i][j];
			}
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]<=a[i+1][j]){
				swap(a[i][j],a[i+1][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==l){
				n_=i;
				m_=j;
			}
		}
	}
	cout<<n_<<" "<<m_;
	return 0;
} 
