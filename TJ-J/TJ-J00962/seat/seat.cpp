#include<bits\stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=n*m,c[n][m];
	for(int i=1;i<=cnt;i++) cin>>a[i];
	int s=a[1];
	sort(a+1,a+1+cnt);
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--) c[i][j]=a[cnt--];
		}
		else{
			for(int j=1;j<=m;j++) c[i][j]=a[cnt--];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==s){
				cout<<i<<' '<<j;
				return 0;
			} 
		}
	}
	return 0;
}
