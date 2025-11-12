#include<bits/stdc++.h>
using namespace std;
int i;
string s;
int a[11];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(i=9;i>=0;i--){
		while(a[i]){
			a[i]--;
			cout<<i;
		}
	}
	return 0;
}