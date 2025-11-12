#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long unll;
using namespace std;
const int N=1e6+100;
string s;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int num=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++num]=s[i]-'0';
	}
	sort(a+1,a+1+num,greater<int>());
	for(int i=1;i<=num;i++) cout<<a[i];
	cout<<'\n';
	return 0;
}
