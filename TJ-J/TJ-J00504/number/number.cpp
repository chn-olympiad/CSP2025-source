#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long a[10001] = {},cnt = 0,ans = 0;
	string s;
	cin>>s;
	for(int i = 1;i<=s.length();i++){
		if('0'<=s[i-1]&&'9'>=s[i-1]){
			cnt++;
			a[cnt] = s[i-1]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i = cnt;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
