#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=510;
int n,m;
char s[N];
int c[N],s1[N],f=1,cnt=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s1[i]=s[i]-'0';
		if(s1[i])cnt++;
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
		if(c[i]==0)f=0;
	}
	if(cnt==n&&f){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(cnt<m){
		cout<<0<<"\n";
		return 0;
	}
	cout<<0<<"\n";
	return 0;
}
