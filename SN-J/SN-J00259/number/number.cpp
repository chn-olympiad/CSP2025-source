#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> a;
	ios::sync_with_stdio(0);
	cin>>s;
	int len=s.length();
	for (long long i=0;i<len;i++)
		if (s[i]<='9' && s[i]>='0')
			a.push_back(s[i]-'0');
	sort(a.begin(),a.end(),cmp);
	len=a.size();
	for (long long i=0;i<len;i++)
		cout<<a[i];
	return 0;
}
