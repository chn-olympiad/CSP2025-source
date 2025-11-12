#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int  i,a[N],t;
string s;
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
		cin>>s;
		for(int i=0;i<s.size();i++)
			if(isdigit(s[i]))
				a[++t]=s[i]-'0';
		sort(a+1,a+1+t,cmp);
		for(int i=1;i<=t;i++)
			cout<<a[i];
		return 0;
}