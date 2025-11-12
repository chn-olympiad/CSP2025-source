#include<bits/stdc++.h>
using namespace std;
int n,m,c[100001],b[100001],C_,M,N;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	char s[n + 1];
	for(int i = 1;i <= n;i++) cin >> s[i];
	for(int i = 1;i <= n;i++) cin >> c[i];
	sort(c + 1,c + 1 + n);
	c[0] = c[1];
	for(int i = 2;i <= n;i++){
		if(c[0] == c[i]) b[c[0]]++;
		else c[0] == c[i];
	}
	for(int i = 1;i <= n;i++){
		if(M == m){
			N = b[c[i - 1]] + 1;
			break;
		}
		if(s[i] == '0') C_++;
		if(s[i] == '1'){
			if(c[i] >= C_) M++;
		}
	}
	cout << 2;
	return 0;
} 
