#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s,s2;

bool cmp(ll a,ll b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(ll i = 0;i<s.size();i++)
		if(s[i] >= '0' && s[i] <= '9') s2+=s[i];
	sort(s2.begin(),s2.end(),cmp);
	cout << s2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
