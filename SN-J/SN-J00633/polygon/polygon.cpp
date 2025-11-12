#include <bits/stdc++.h>
using namespace std;
int n,a[5000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	vector<int> b{1,2};
	for (int i = 3;i <= n;i++){
		b.push_back(i);
		
	}
	return 0;
}
