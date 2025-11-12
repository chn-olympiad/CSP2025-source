#include<bits/stdc++.h>
using namespace std;
string s;
vector<long long> a;
long long b;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b=s[i]-'0';
			a.push_back(b);
		}
	}
	sort(a.begin(),a.end());
	b=0;
	for(int i=a.size()-1;i>=0;i--){
		b=b*10+a[i];
		if(b>=1e15){
			cout<<b;
			b=0;
		}
	}
	return 0;
}
