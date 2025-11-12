#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,ans;
int flag[10];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		flag[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(flag[i]){
			for(int j=1;j<=flag[i];j++){
				cout<<i;
			}
		}
	}
    return 0;
}
