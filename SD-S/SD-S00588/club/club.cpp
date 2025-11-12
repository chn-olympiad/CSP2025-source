#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
struct node{
	int a,b,c;
	int ch;
}s[N];
struct asd{
	long long val,cha;
}a[N],b[N],c[N];
bool cmp(asd x,asd y){
	return x.cha>y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		long long ans=0;
		int cnta=0,cntb=0,cntc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			int maxx=max(s[i].a,max(s[i].b,s[i].c));
			if(maxx==s[i].a){
				cnta++;
				a[cnta].cha=maxx-max(s[i].b,s[i].c);
				a[cnta].val=maxx;
			}
			else if(maxx==s[i].b){
				cntb++;
				b[cntb].cha=maxx-max(s[i].a,s[i].c);
				b[cntb].val=maxx;
			}
			else{
				cntc++;
				c[cntc].cha=maxx-max(s[i].a,s[i].b);
				c[cntc].val=maxx;
			}
		}
		if(cnta>(n>>1)){
			sort(a+1,a+cnta+1,cmp);
			for(int i=1;i<=cnta;i++)ans+=a[i].val;
			for(int i=n/2+1;i<=cnta;i++)ans-=a[i].cha;
			for(int i=1;i<=cntb;i++)ans+=b[i].val;
			for(int i=1;i<=cntc;i++)ans+=c[i].val;
		}
		else if(cntb>(n>>1)){
			sort(b+1,b+cntb+1,cmp);
			for(int i=1;i<=cntb;i++)ans+=b[i].val;
			for(int i=n/2+1;i<=cntb;i++)ans-=b[i].cha;
			for(int i=1;i<=cnta;i++)ans+=a[i].val;
			for(int i=1;i<=cntc;i++)ans+=c[i].val;
		}
		else if(cntc>(n>>1)){
			sort(c+1,c+cntc+1,cmp);
			for(int i=1;i<=cntc;i++)ans+=c[i].val;
			for(int i=n/2+1;i<=cntc;i++)ans-=c[i].cha;
			for(int i=1;i<=cnta;i++)ans+=a[i].val;
			for(int i=1;i<=cntb;i++)ans+=b[i].val;
		}
		else{
			for(int i=1;i<=cnta;i++)ans+=a[i].val;
			for(int i=1;i<=cntb;i++)ans+=b[i].val;
			for(int i=1;i<=cntc;i++)ans+=c[i].val;
		}
		cout<<ans<<"\n";
		for(int i=1;i<=cnta;i++)a[i].cha=a[i].val=0;
		for(int i=1;i<=cntb;i++)b[i].cha=b[i].val=0;
		for(int i=1;i<=cntc;i++)c[i].cha=c[i].val=0;
	}
	
	return 0;
}
//luogu uid:547760
//by:lain_yc
