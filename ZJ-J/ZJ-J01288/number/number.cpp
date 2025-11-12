#include<bits/stdc++.h>
using namespace std;
long long len,f,a[20];
char s[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>s+1;
	len=strlen(s+1);
	for(long long i=1;i<=len;i++)
		if('0'<=s[i]&&s[i]<='9')a[int(s[i])-48]++;
	for(long long i=9;i>=0;i--)
		if((a[i]>0&&i!=0)||(i==0&&f==1)){
			for(long long j=1;j<=a[i];j++)cout<<i;
			f=1;
		}
		else if(i==0&&f==0)cout<<0;
	return 0;
}
