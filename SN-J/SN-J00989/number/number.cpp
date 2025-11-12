#include<bits/stdc++.h>
using namespace std;
string s; 
vector<int> num;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>s;
	for(char x:s) if(x>='0'&&x<='9') num.push_back(x-'0');
	sort(num.begin(),num.end(),[](int a,int b)
	{
		return a>b;
	});
	for(int x:num) cout<<x;
	cout<<"\n";
	return 0;
}
