#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]<='9'&&a[i]>='0')s[++cnt]=a[i];
	}
	sort(s+1,s+cnt+1);
	for(int i=cnt;i>=1;i--)cout<<s[i];
	return 0;
}
