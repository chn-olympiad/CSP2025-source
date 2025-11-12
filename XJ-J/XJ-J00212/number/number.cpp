#include<bits\stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
int ans[N],p;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	int n=1;
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')ans[n++]=s[i]-'0';
	n--;
	sort(ans+1,ans+1+n,cmp);
	for(int i=1;i<=n;i++)
		cout<<ans[i];
	return 0;
}
