#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int const N=200010,L=5000010;
ull const P=131;
int n,q,res;
string s1,s2,ss[N],st[N];
ull p1[L],p2[L];

ull Pow(ull x,int a){
	if (a==0) return 1;
	if (a==1) return x;
	ull p=Pow(x,a>>1);
	if (a%2) return p*p*x;
	return p*p;
}

bool eql(int l,int r,int x){
	ull u=p1[r]-p1[l-1],v=0;
	for (int i=0;i<ss[x].length();i++){
		v+=(ull)ss[x][i]*Pow(P,i+l-1);
	}
	if (u!=v) return 0;
	u=p2[r]-p2[l-1],v=0;
	for (int i=0;i<st[x].length();i++){
		v+=(ull)st[x][i]*Pow(P,i+l-1);
	}
	//printf("%d %d %d\n%lld %lld\n",l,r,x,u,v);
	return u==v;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>ss[i]>>st[i];
	int l,r,len;
	for (int x=1;x<=q;x++){
		cin>>s1>>s2;
		//memset(p1,0,sizeof(p1));
		//memset(p1,0,sizeof(p2));
		res=0,l=L,r=0;
		s1=" "+s1,s2=" "+s2;
		len=s1.length();
		for (int i=1;i<=len;i++){
			if (s1[i]!=s2[i]){
				l=min(l,i),r=max(r,i);
			}
			p1[i]=p1[i-1]+(ull)s1[i]*Pow(P,i-1),p2[i]=p2[i-1]+(ull)s2[i]*Pow(P,i-1);
		}
		for (int i=1;i<=n;i++){
			if (ss[i].length()<r-l+1) continue;
			//printf("%d %d\n",l,r);
			int p=r-ss[i].length()+1;
			for (int k=max(1,p);k<=l && k+ss[i].length()-1<=len;k++){
				if (eql(k,k+ss[i].length()-1,i)) res++;
			}
		}
		cout<<res<<'\n';
	}
	
	return 0;
} 
