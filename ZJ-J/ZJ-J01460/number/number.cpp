#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define R register
#define LL long long
using namespace std;
string s;
int l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	l=s.size();
	for(R int t=9;t>=0;t--)
		for(R int i=0;i<l;i++)
			if(s[i]==char(t+'0'))
				cout<<s[i];
	return 0;
}
