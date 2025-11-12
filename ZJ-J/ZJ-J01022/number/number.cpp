#include<bits/stdc++.h>
using namespace std;
int n,i,cnt,a[1000010];
char s[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;
	n=strlen(s+1);
	for(i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-48;
	sort(a+1,a+cnt+1);
	for(i=cnt;i>=1;i--)
		cout<<a[i];
	return 0;
}
//#Shang4Shan3Ruo6Shui4
