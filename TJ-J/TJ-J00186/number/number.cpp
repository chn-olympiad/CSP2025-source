#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+5;
int a[N];
int cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(!islower(s[i])){
			a[cnt++]=s[i]-'0';
		}
	}
	sort(a, a+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<a[i];
	}
	cout<<'\n';
	return 0;
}
// 
