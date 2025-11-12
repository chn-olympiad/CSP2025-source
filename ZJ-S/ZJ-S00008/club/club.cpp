#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define forr(i,n) for(long long i=1;(i)<=(n);i++)
#define fo(i,n) for(long long i=0;(i)<(n);i++)
#define gc getchar
#define pc putchar
ll num,numm[100010],f,cnt;
char cc;
ll t,n,ans;
struct aa{
	ll a,b,c;
}s[100010];
vector<aa> a,b,c;
ll in(){
	f=1,num=0,cc=gc();
	for(;cc>'9'||cc<'0';cc=gc())
		if(cc=='-')
			f=-1;
	for(;cc<='9'&&cc>='0';cc=gc())
		num=num*10+cc-'0';
	return num*f;
}
void out(ll x){
	cnt=0,f=1;
	if(x==0)
		pc('0');
	else{
		if(x<0)
			x=-x,f=-1;
		while(x)
			numm[++cnt]=x%10,x/=10;
		for(ll i=cnt;i>=1;i--)
			pc(numm[i]+'0');
	}
}
bool cmpa(aa x,aa y){
	return (x.a-max(x.b,x.c))<(y.a-max(y.b,y.c));
}
bool cmpb(aa x,aa y){
	return (x.b-max(x.a,x.c))<(y.b-max(y.a,y.c));
}
bool cmpc(aa x,aa y){
	return (x.c-max(x.a,x.b))<(y.c-max(y.a,y.b));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=in();
	while(t--){
		ans=0;
		a.clear();
		b.clear();
		c.clear();
		n=in();
		forr(i,n){
			s[i].a=in(),s[i].b=in(),s[i].c=in();
			if(s[i].a>s[i].b&&s[i].a>s[i].c){
				ans+=s[i].a;
				a.push_back(s[i]);
			}
			else if(s[i].b>s[i].a&&s[i].b>s[i].c){
				ans+=s[i].b;
				b.push_back(s[i]);
			}
			else if(s[i].c>s[i].a&&s[i].c>s[i].b){
				ans+=s[i].c;
				c.push_back(s[i]);
			}
			else
				ans+=max(s[i].a,max(s[i].b,s[i].c));
		}
		if(a.size()>n/2){
			sort(a.begin(),a.end(),cmpa);
			for(ll i=0;i<a.size()-n/2;i++){
				if(a[i].b>=a[i].c)
					ans=ans-a[i].a+a[i].b;
				else if(a[i].c>a[i].b)
					ans=ans-a[i].a+a[i].c;
			}
		}
		if(b.size()>n/2){
			sort(b.begin(),b.end(),cmpb);
			for(ll i=0;i<b.size()-n/2;i++){
				if(b[i].a>=b[i].c)
					ans=ans-b[i].b+b[i].a;
				else if(b[i].c>b[i].a)
					ans=ans-b[i].b+b[i].c;
			}
		}
		if(c.size()>n/2){
			sort(c.begin(),c.end(),cmpc);
			for(ll i=0;i<c.size()-n/2;i++){
				if(c[i].a>=c[i].b)
					ans=ans-c[i].c+c[i].a;
				else if(c[i].b>c[i].a)
					ans=ans-c[i].c+c[i].b;
			}
		}
		out(ans);
		pc('\n');
	}
	return 0;
}