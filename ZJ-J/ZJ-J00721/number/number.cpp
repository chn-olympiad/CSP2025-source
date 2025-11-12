#include<bits/stdc++.h>
using namespace std;
int cnt[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int j=9;j>=0;j--){
		for(int i=1;i<=cnt[j];i++){
			cout<<j;
		}
	}
	return 0;
}
//made by S_A_T_E_L_L_I_T_E(luogu_737070)
//maybe 100
//I love phigros
