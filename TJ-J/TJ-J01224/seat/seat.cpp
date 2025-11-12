#include <bits/stdc++.h>
using namespace std;
const int N=15;
int a[N][N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> b(n*m);
    int p,cnt=0;
    cin>>p;
    b[0]=p;
    for(int i=1;i<n*m;i++){
    	cin>>b[i];
	}
	sort(b.begin(),b.end(),greater<int>());
    for(int i=1;i<=m;i+=2){
    	for(int j=1;j<=n;j++){
    		a[i][j]=b[cnt];
    		cnt++;
		}
		for(int j=n;j>=1;j--){
			a[i+1][j]=b[cnt];
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(p==a[i][j]) cout<<i<<' '<<j;
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
