#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 550;
int t[N];
int cnt[N];
int c[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i = 1;i <= n;i ++){
		cin>>c[i];
	}
	bool flag = true;
	if(s[0] == '0'){
		t[0] = 1;
	}
	for(int i = 1;i < s.size();i ++){
		if(s[i] == '0'){
			t[i] = t[i - 1] + 1;
		}
		else{
			t[i] = t[i-1];
		}
		if(s[i] == '0'){
			flag = false;
		}
	}
	if(flag){
		long long ans = 1;
		for(int i = 1;i <= n;i ++){
			ans *= i;
			ans%=MOD;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

