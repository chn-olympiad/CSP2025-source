#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int len=s.length();
    s=" "+s;
    for(int i=1;i<=len;i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			cout<<i;
		}
	}
	return 0;
}
