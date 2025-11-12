#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	queue<int> ans;
	for(int i=0;i<=s.length()-1;i++){
		if(('0' <= s[i]) && (s[i]<='9')) ans.push(s[i]-'0');
	}
	int num[100005];
	long long n=ans.size();
	for(long long i=0;i<=n-1;i++){
		num[i] = ans.front();
		ans.pop();
	}
	sort(num,num+n);
	for(long long i=n-1;i>=0;i--){
		cout << num[i];
	} 
	
	return 0;
}
