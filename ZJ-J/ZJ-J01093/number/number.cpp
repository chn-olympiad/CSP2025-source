#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int b[N];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>s;
	int n=s.size();
	s=' '+s;
	for(int i=1;i<=n;++i){
		if(s[i]>='0'&&s[i]<='9')b[s[i]-'0']++;
	}
	for(int i=9;i>=0;--i){
		for(int j=1;j<=b[i];++j){
			cout<<i;
		}
	}
	return 0;
}