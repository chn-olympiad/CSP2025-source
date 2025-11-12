#include<bits/stdc++.h>
using namespace std;
int a[1000001];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int cnt=0;
	for(int i=0;i<len;i++) if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>0;i--)cout<<a[i];
	return 0;
}
