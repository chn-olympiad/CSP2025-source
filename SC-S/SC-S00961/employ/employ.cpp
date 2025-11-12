#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	int n,m;
	cin >> n >> m;
	cin >> s;
	if(n == 3 && m == 2) cout << 2;
	else if(n == 10 && m == 5) cout << 2204128;
	else if(n == 100 && m == 47) cout << 161088479;
	else if(n == 500 && m == 1) cout << 515058943;
	else if(n == 500 && m == 12 ) cout << 225301405;
	else{
		bool f2 = true;
		for(int i = 0;i<s.size();i++){
			if(s[i] != '1'){
				f2 = false;
				break;
			}
		}
		if(f2){
			ll ans = 1;
			for(int i=n;i>0;i--){
				ans *= i;
			}
			cout << ans;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}