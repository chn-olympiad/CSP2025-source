#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),a[l],sum=0;
	for(int i=0;i<l;i++) if(s[i]>='0'&&s[i]<='9') a[sum++]=s[i]-'0';
	sort(a,a+sum,greater<int>());
	for(int i=0;i<sum;i++) cout<<a[i];
	return 0;
}
