#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n*m);
	int add[maxn][maxn];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int Rs=a[0];
	sort(a.begin(),a.end());
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=n*m-1;k>=0;k--){
				add[i][j]=a[k];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(add[i][j]==Rs){
				cout<<i<<" "<<j<<endl;
				break;
			}
		}
	}	
	return 0;
}
