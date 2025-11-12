#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+7;
int len,i,cnt;
char s[maxn];
int b[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;len=strlen(s+1);
	for(i=1;i<=len;i++)
		if('0'<=s[i]&&s[i]<='9')
			b[++cnt]=-(s[i]-48);
	sort(b+1,b+1+cnt);
	for(i=1;i<=cnt;i++)	cout<<-b[i];
	return 0;
}
//#Shang4Shan3Ruo6Shui4