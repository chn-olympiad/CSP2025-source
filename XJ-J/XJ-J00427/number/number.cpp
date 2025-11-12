#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long ans=0;
	long long a[100005];
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans++;
			a[ans]=s[i]-'0';
		}
	}
	sort(a+1,a+ans+1);
	for(long long i=ans;i>=1;i--){
		cout<<a[i];
	}
	return 0;
 } 
