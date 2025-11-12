#include<bits/stdc++.h>
#define ll long long
#define p1 1000000993
#define p2 1000000933
#define b 325609
using namespace std;
int n,m,qr,x,l,r,u,c[5000010][27],fl[5000010],sm[5000010],ans;
ll h1,h2;
string s,t;
map<ll,int>rt;
queue<int>q;
int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>qr;
	while(n--){
		cin>>s>>t,x=s.length(),s=" "+s,t=" "+t,l=r=h1=h2=0;
		for(int i=1;i<=x;i++)if(s[i]!=t[i])l=!l?i:l,r=i;
		if(!l)continue;
		for(int i=l;i<=r;i++)h1=((h1*b+s[i]-97)%p1*b+t[i]-97)%p1,h2=((h2*b+s[i]-97)%p2*b+t[i]-97)%p2,s[i]='{';
		if(!rt[h1+=h2*p1])rt[h1]=u=++m;else u=rt[h1];
		for(int i=1;i<=x;i++){
			if(!c[u][s[i]-97])c[u][s[i]-97]=++m;
			u=c[u][s[i]-97];
		}sm[u]++;
	}
	for(map<ll,int>::iterator i=rt.begin();i!=rt.end();i++){
		u=(*i).second;
		for(int i=0;i<27;i++)if(!c[u][i])c[u][i]=u;else q.push(c[u][i]),fl[c[u][i]]=u;
	}
	while(!q.empty()){
		u=q.front(),q.pop(),sm[u]+=sm[fl[u]];
		for(int i=0;i<27;i++)if(!c[u][i])c[u][i]=c[fl[u]][i];else q.push(c[u][i]),fl[c[u][i]]=c[fl[u]][i];
	}
	while(qr--){
		cin>>s>>t,x=s.length(),s=" "+s,t=" "+t,l=r=h1=h2=ans=0;
		for(int i=1;i<=x;i++)if(s[i]!=t[i])l=!l?i:l,r=i;
		for(int i=l;i<=r;i++)h1=((h1*b+s[i]-97)%p1*b+t[i]-97)%p1,h2=((h2*b+s[i]-97)%p2*b+t[i]-97)%p2,s[i]='{';
		u=rt[h1+h2*p1];
		for(int i=1;i<=x;i++)u=c[u][s[i]-97],ans+=sm[u];
		cout<<ans<<"\n";
	}
	return 0;
}
