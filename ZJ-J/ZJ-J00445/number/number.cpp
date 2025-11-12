#include<bits/stdc++.h>
#define int long long
using namespace std;
int b[1000010],i,len,t;
char s[1000010];
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s+1;
	len=strlen(s+1);
	for(i=1;i<=len;i++){
		if(s[i]=='0')b[++t]=0;
		if(s[i]=='1')b[++t]=1;
		if(s[i]=='2')b[++t]=2;
		if(s[i]=='3')b[++t]=3;
		if(s[i]=='4')b[++t]=4;
		if(s[i]=='5')b[++t]=5;
		if(s[i]=='6')b[++t]=6;
		if(s[i]=='7')b[++t]=7;
		if(s[i]=='8')b[++t]=8;
		if(s[i]=='9')b[++t]=9;
	}
	sort(b+1,b+t+1,cmp);
	for(i=1;i<=t;i++)cout<<b[i];
	return 0;
}