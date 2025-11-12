#include<iostream>
using namespace std;
int n,m;
int cnt=1;
int t[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin>>t[i][j];
			if(t[i][j]>t[1][1]){
				cnt++;
			}
		}
	}
	if(cnt%n==0){
		cout<<cnt/n<<" ";
		cout<<n;
	}
	else{
		cout<<cnt/n+1<<" ";
		if((cnt/n+1)%2==0){
			cout<<n-cnt%n+1;
		}
		else{
			cout<<cnt%n;
		}
	}
	return 0;
}
