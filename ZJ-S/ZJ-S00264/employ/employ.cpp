#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll _=105,M=998244353;
ll qp(ll x,ll y){ll z=1;for(;y;y>>=1,x=x*x%M)if(y&1)z=z*x%M;return z;}
ll n,m,k,t,x,s,a[_],b[_],A[_],B[_],d[_][_],e[_][_],F[_],G[_],i,j,g,h;string str;
ll p(ll x,ll y,ll z){return (z<=x&&z<=y)?F[x]*G[x-z]%M*F[y]%M*G[y-z]%M*G[z]%M:0;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(F[0]=i=1;i<_;i++)F[i]=F[i-1]*i%M;
	for(i=_-1,G[i]=qp(F[i],M-2);i;i--)G[i-1]=G[i]*i%M;
// for(i=0;i<=9;i++)cout<<F[i]<<" \n"[i==9];
// for(i=0;i<=9;i++)cout<<G[i]<<" \n"[i==9];
// for(i=0;i<=9;i++)cout<<F[i]*G[i]%M<<" \n"[i==9];
	cin>>n>>k>>str;
	for(m=i=0;i<n;i++)(str[i]=='0'?m:a[m])++;
	m++;a[m]=m-1;
	for(i=0;i<n;i++)cin>>x,b[min(m,x)]++;
// cout<<m<<'\n';
// for(i=0;i<=m;i++)cout<<a[i]<<" \n"[i==m];
// for(i=0;i<=m;i++)cout<<b[i]<<" \n"[i==m];
	for(A[0]=a[0],i=1;i<=m;i++)A[i]=A[i-1]+a[i];
	for(B[0]=b[0],i=1;i<=m;i++)B[i]=B[i-1]+b[i];
	for(i=min(a[0],b[0]);~i;i--)d[i][0]=p(a[0],b[0],i);
	for(i=1;i<=m;i++){
		memset(e,0,sizeof(e));
		for(j=min(A[i-1],B[i-1]);~j;j--)if(d[j]){
			t=A[i-1]-j;
			for(g=min(t,b[i]);~g;g--){
				x=p(t,b[i],g);
				for(h=0;h<=j;h++)(e[j+g][h+g]+=d[j][h]*x)%=M;
			}
		}
		memset(d,0,sizeof(d));
		for(j=min(A[i-1],B[i]);~j;j--)if(e[j]){
			t=B[i]-j;
			for(g=min(a[i],t);~g;g--){
				x=p(a[i],t,g);
				for(h=0;h<=j;h++)(d[j+g][h]+=e[j][h]*x)%=M;
			}
		}
	}
// for(i=0;i<=n;i++)cout<<d[n][i]<<" \n"[i==n];
	for(i=k;i<=n;i++)s+=d[n][i];
	cout<<s%M<<'\n';
}