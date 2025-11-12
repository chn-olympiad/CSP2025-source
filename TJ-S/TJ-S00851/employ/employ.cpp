#include <bits/stdc++.h>
using namespace std;
int c[10000001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//CCF最牛*了 
	int n,m;
	string s;
	cin >> n >> m >> s;
	int ifs1 = 1;//所有人的耐心都不为0,； 
	for (int i = 1;i <= n;i++){
		cin >> c[i];
		if (c[i] == 0){
			ifs1 = 0;
		} 
	}
	if (ifs1 == 1){
		int sum = 0;
		for (int i = m;i <= n;i++){
			int cnt = 1;
			for (int j = 1;j <= i;j++){
				cnt *= j;
			}
			sum += cnt; 
		}
		cout << sum;
	}
	return 0;
}
