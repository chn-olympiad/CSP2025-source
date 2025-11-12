#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m];
	vector<int>b(n*m);
	for(int i=0; i<n*m; i++) {
		cin>>b[i];
	}
	int k=b[0],cnt=0;
	sort(b.begin(),b.end(),cmp);
	for(int j=0; j<m; j++) {
		if(j%2==0) {
			for(int i=0; i<n; i++) {
				a[i][j]=b[cnt];
				cnt++;
			}
		} else {
			for(int i=n-1; i>=0; i--) {
				a[i][j]=b[cnt];
				cnt++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==k){
				cout<<j+1<<' '<<i+1;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
