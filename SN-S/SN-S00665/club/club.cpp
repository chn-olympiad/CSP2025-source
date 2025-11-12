#include<bits/stdc++.h>
using namespace std;
int t;
int l[10000][10000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	int cnt = 3*t;
	for(int i = 1;i <= cnt;i++){
		for(int j = 1;j <= 3;j++){
			cin >> l[i][j];
		}
	}
	
	return 0;
}
