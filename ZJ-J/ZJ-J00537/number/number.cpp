#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for (int i=0;i<len;i++)	
		if ('0'<=s[i] && s[i]<='9')
			a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt,cmp);
	if (a[1]==0)
		cout<<0;
	else{
		for (int i=1;i<=cnt;i++)
			cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
}
