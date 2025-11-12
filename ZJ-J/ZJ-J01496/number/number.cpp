#include<bits/stdc++.h>
using namespace std;
long long  a[10];

int read(){
	int f=1,cnt=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))cnt=cnt*10+ch-'0',ch=getchar();
	return f*cnt;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++)
	if(s[i]<='9'&&s[i]>='0') a[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++)
		printf("%d",i);
	}
}
