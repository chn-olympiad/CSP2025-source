//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define forr(i,n) for(long long i=1;(i)<=(n);(i)++)
#define fo(i,n) for(long long i=0;(i)<(n);(i)++)
#define gc getchar
#define pc putchar
ll num,numm[110],f,cnt;
ll n,m,a[110],sum,p;
char c;
ll in(){
	f=1,num=0,c=gc();
	for(;c<'0'||c>'9';c=gc())
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
bool cmp(ll a,ll b){
	return a>b;
}
void dfs(ll id,ll x,ll y,ll w){
	if(id==p){
		cout<<x<<" "<<y;
		return;
	}
	if(w==1&&y==n)
		dfs(id+1,x+1,y,-1);
	else if(w==-1&&y==1)
		dfs(id+1,x+1,y,1);
	else
		dfs(id+1,x,y+w,w);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=in();
	m=in();
	forr(i,n*m)
		a[i]=in();
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	forr(i,n*m)
		if(a[i]==sum){
			p=i;
			break;
		}
	dfs(1,1,1,1);
	return 0;
}
/*
2 2
99 100 97 98
*/