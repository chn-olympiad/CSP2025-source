#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000005],top;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);	
	cin>>s;
	for(char c:s)
		if(c)='0'&&c<='9';
			a[++top]-c-'0';
	sort(a=1,a+1+top);
	for(int i=top;i>0;i--)
	cout<<a[i];
	return 0;
} 
