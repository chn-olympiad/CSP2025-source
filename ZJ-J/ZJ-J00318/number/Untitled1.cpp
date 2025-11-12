#include<bits/stdc++.h>
using namespace std;
string s;
long long a[6000005],j,l;
long long main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++)if(s[i]<='9'&&s[i]>='0')a[++j]=s[i]-'0';
	sort(a+1,a+1+j);
	if(a[j]==0){
		cout<<0<<'\n';
		return 0;
	}
	for(int i=j;i;i--){
		cout<<a[i];
	}
	return 0;
}
