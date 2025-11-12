#include<bits/stdc++.h>
using namespace std;
int n,m,wait[505],cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 0;i < n;i++){
		cin >> wait[i];
		cnt *= wait[i];
	}
	cout << cnt;
}
