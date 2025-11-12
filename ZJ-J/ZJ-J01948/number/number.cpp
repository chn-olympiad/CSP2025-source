#include<bits/stdc++.h>
#define LL long long
#define Fcin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
priority_queue<int> q;
string s;
int main()
{
	Fcin;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	sort(s.begin(),s.end());
	for(int i=len-1;i>=0;--i)
		if(s[i]>='0' && s[i]<='9') cout<<s[i];
	return 0;
}

