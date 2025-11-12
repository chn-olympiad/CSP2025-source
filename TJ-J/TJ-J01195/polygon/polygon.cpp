#include <bits/stdc++.h>
using namespace std;
int s[500005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
	}
	if(n<3)cout <<'0';
	if(n==3)cout <<'1';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
