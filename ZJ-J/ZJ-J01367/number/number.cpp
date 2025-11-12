#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,a[maxn],m;
string s;
int read(){
	int tot=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')tot=tot*10+ch-'0',ch=getchar();
	return tot*f;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')a[++m]=s[i]-'0';
	}
	sort(a+1,a+1+m);
	for(int i=m;i>=1;i--)printf("%d",a[i]);
	return 0;
}