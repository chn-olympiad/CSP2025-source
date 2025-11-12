#include <bits/stdc++.h>
using namespace std;
string s;
int t[100005],maxn=-1e9;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0' && s[i]<='9') {
			int n=s[i]-'0';
			t[n]++;
		}
	}
	for(int i=9;i>=0;--i){
		if(t[i]!=0){
			for(int j=1;j<=t[i];++j){
				cout<<i;
			}
		}
	}
	return 0;
}
