#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=1e5+5;
void read(int& x){
	char c;
	bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=x*10+c-48;
	x=(f ? -x : x);
}
int t,n;
int a[maxn][3];
int c[maxn],s[maxn];
int p[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		p[0]=p[1]=p[2]=0;
		LL ans=0;
		for(int i=1;i<=n;i++){
			read(a[i][0]),read(a[i][1]),read(a[i][2]);
			int k=max({a[i][0],a[i][1],a[i][2]});
			if(k==a[i][0]) ++p[0],c[i]=0,s[i]=a[i][0]-max(a[i][1],a[i][2]);
			else if(k==a[i][1]) ++p[1],c[i]=1,s[i]=a[i][1]-max(a[i][0],a[i][2]);
			else ++p[2],c[i]=2,s[i]=a[i][2]-max(a[i][0],a[i][1]);
			ans+=k;
		}
		int op;
		if(p[0]==max({p[0],p[1],p[2]})) op=0;
		else if(p[1]==max({p[0],p[1],p[2]})) op=1;
		else op=2;
		vector<int> v;
		for(int i=1;i<=n;i++){
			if(c[i]==op) v.push_back(s[i]);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<max({p[0],p[1],p[2]})-n/2;i++){
			ans-=v[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
