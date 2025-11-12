#include<bits/stdc++.h>
using namespace std;
int vis[100005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int a,b,c,num = 0;
	for(int i = 1;i <= m;i++){
		cin >> a >> b >> c;
		num += c;
	}
	cout << num;
	return 0;
}

