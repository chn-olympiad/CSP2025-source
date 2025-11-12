#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int l,ts;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9') a[ts++]=s[i]-'0';
	}
	sort(a,a+ts);
	if(a[ts-1]==0) cout<<'0'<<endl;
	else for(int i=ts-1;i>=0;i--) cout<<a[i];
	return 0;
}
