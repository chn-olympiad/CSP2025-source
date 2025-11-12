#include<bits/stdc++.h>
#define int long long 
using namespace std;
string s;
int a[15];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			a[x]++;
		}
	}for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
