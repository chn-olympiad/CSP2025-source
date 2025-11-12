//number
#include<bits/stdc++.h>
#define N 1000010
using namespace std;
string s;int n,a[N];bool b=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	for(int i=9;i>=1;i--)
		while(a[i]--) b=1,cout<<i;
	if(b) while(a[0]--) cout<<0;
	else cout<<0;
	return 0;
}