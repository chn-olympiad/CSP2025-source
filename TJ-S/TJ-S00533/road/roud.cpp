include<iostream>
using namespace std;
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cout << i;
		for(int j=1;j<=k;j++){
			cout << j;
			for(int i=1;i<=n;i++){
				cout << i;
			}
		}
	}
	return 0;
}
