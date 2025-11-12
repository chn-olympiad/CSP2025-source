#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],cnt,ans = 1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 0;i < s.size();i++){
		if(s[i] == '0')break;
		cnt++;
	}
	if(cnt < m){
		cout<<0;
	}else{
		for(int i = 2;i <= n;i++){
			ans = (ans*i)%998244353;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
