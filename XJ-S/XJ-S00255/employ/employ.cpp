#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,c[1010],flag=1,ans=0;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]!='1'){
			flag=0;
			break;
		}
	}
	if(flag==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i;
			ans=ans%998244353;
		}
		cout << ans%998244353;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
