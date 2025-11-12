#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if((s[i]>='1'&&s[i]<='9'))a[++cnt]=char(s[i]-'1'+1);
		else if(s[i]=='0')a[++cnt]=0;
	}
	sort(a+1,a+cnt+1);
	if(a[cnt]!=0)for(int i=cnt;i>=1;i--)cout<<a[i];
	else cout<<0;
	return 0;
}
