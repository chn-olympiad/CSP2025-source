#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<int>a;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a.push(s[i]-'0');
	while(!a.empty())
		printf("%d",a.top()),a.pop();
	return 0;
}

