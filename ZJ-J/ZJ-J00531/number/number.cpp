#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[9];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//wo yao wan Honkai:Starrail!!!
//luogu:1547417(?,wo wang ji le,bu zhi dao dui bu dui)
//ke yi jin hao huo da shang ma OvO
//baby wachin'burn, send death to i~so~la~tion~
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'<=9 && s[i]-'0'>=0)a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
}
