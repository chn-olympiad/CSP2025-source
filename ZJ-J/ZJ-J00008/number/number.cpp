//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define forr(i,n) for(long long i=1;(i)<=(n);(i)++)
#define fo(i,n) for(long long i=0;(i)<(n);(i)++)
#define gc getchar
#define pc putchar
ll num,numm[1000010],f,cnt,a[1000010],ans;
char c;
string s;
ll in(){
	f=1,num=0,c=gc();
	for(;c<='0'||c>='9';c=gc())
		if(c=='-')
			f=-1;
	for(;c>='0'&&c<='9';c=gc())
		num=num*10+c-'0';
	return num*f;
}
void out(ll x){
	f=1,cnt=0;
	if(x){
	if(x<0)
		f=-1,x=-x;
	while(x)
		numm[++cnt]=x%10,x/=10;
	for(ll i=cnt;i>=1;i--)
		pc(numm[i]+'0');
	}
	else if(x==0)
		pc('0');
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	cnt=0,ans=0;
	fo(i,s.size())
		if(s[i]>='0'&&s[i]<='9')
			a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1);
	for(ll i=cnt;i>=1;i--)
		out(a[i]);
	return 0;
}