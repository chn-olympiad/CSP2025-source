//SN-S00754  陈钰婉  西安高新第一中学 
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxn=5e6+10,base=10311083;
int n,q,l[200005],ans=0;

pair<string,string> s[200005];
pair<ull,ull> c[200005]; 
#define mk make_pair

ull p[maxn],hsha[maxn],hshb[maxn];

ull qa(int l,int r){
	return hsha[r]-hsha[l-1]*p[r-l+1];
}
ull qb(int l,int r){
	return hshb[r]-hshb[l-1]*p[r-l+1];
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<maxn;i++){
		p[i]=p[i-1]*base;
	}

	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		int la=a.size(),lb=b.size();
		l[i]=la;
		a=" "+a,b=" "+b;
		s[i]=mk(a,b);
		ull x=0,y=0;
		for(int j=1;j<=la;j++){
			x=x*base+(ull)a[j]-'a';
		}
		for(int j=1;j<=lb;j++){
			y=y*base+(ull)b[j]-'a';
		}
		c[i]=mk(x,y); 
	}
	
	while(q--){
		int ans=0;
		string a,b;
		cin>>a>>b;
		int len=a.size();
		a=" "+a,b=" "+b;
		string t=a;
		
		for(int i=0;i<=len;i++) hsha[i]=hshb[i]=0;
		for(int l=1;l<=len;l++){
			hsha[l]=hsha[l-1]*base+(ull)a[l]-'a';
		}
		for(int l=1;l<=len;l++){
			hshb[l]=hshb[l-1]*base+(ull)b[l]-'a';
		}
		
		for(int i=1;i<=len;i++){
			for(int j=1;j<=n;j++){
				ull x=c[j].first,o=qa(i,min(len,i+l[j]-1));
				string y=s[j].second;
				if(x==o){
					int p1=i;
					for(int p2=1;p2<=l[j];p2++,p1++){
						t[p1]=y[p2];
					}
					if(t==b) ans++;
					t=a;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
/*1 1
xabcx xadex
xabcx xadex
*/
