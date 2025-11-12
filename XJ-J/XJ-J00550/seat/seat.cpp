#include <bits/stdc++.h>
using namespace std;
const int MAXN=14;
int n,m,x,t,ans;
int a[MAXN][MAXN],b[110],flag[MAXN][MAXN];
int main() {
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>b[i];
		ans=b[1];
		x++;
	}
		for(int i=1; i<=x; i++) {
		for(int j=i+1; j<=x; j++) {
			if(b[i]<b[j]) {
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
//			cout<<b[i]<<b[j]<<endl;
		}
	}
//	for(int i=1; i<=x; i++) {
//		cout<<b[i];
//	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			for(int q=(j-1)*n+1; q<=j*n;q++)
			{	
				if(q>n*m){
					continue;
				}
				a[i][j]=b[q];
//				cout<<a[i][j]<<" ";
				
			}
//			cout<<endl;
		}
		
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(flag[i][j]==0){
				if(i%2==0&&j%2!=0){
					swap(a[i][j],a[n][j]);
					flag[i][j]=1;
					flag[n][j]=1;
				}
			} 
			if(ans==a[i][j]){
				if(flag[i][j]){
					cout<<n<<" "<<j;
				}
				else{
					cout<<i<<" "<<j;
				}
			}
		}
	}
	return 0;
}
