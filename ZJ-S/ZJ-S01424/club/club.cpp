#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Stu{
    ll a,b,c;
}stu[100010];
bool cmp(Stu a,Stu b){
    if(a.a>b.a)return 0;
    if(a.a<b.a)return 1;
    if(a.b>b.b)return 0;
    if(a.b<b.b)return 1;
    if(a.c>b.c)return 0;
    if(a.c<b.c)return 1;
    return 1;
}
ll n;
ll t;
ll ans;
int a[100010],b[100010],c[100010];
ll na=0,nb=0,nc=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	ans=0;
    	na=nb=nc=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>stu[i].a>>stu[i].b>>stu[i].c;
        }
        sort(stu+1,stu+n+1,cmp);
        for(int i=1;i<=n-1;i++){
        	int aa,bb,cc;
        	aa=stu[i].a-stu[i+1].a;
        	bb=stu[i].b-stu[i+1].b;
        	cc=stu[i].c-stu[i+1].c;
        	if(na>=(n/2)){
        		aa=-1;
			}
			if(nb>=(n/2)){
				bb=-1;
			}
			if(nc>=(n/2)){
				cc=-1;
			}
			int maxn=max(max(aa,bb),cc);
			if(maxn==aa){
				if(aa!=bb&&aa!=cc){
					a[++na]=i;
				}
				if(aa==bb&&aa==cc){
					int minn=min(min(na,nb),nc);
					if(minn==na){
						a[++na]=i;
					}else if(minn==nb){
						b[++nb]=i;
					}else{
						c[++nc]=i;
					}
				}else if(aa==bb){
					if(na<=nb){
						a[++na]=i;
					}else{
						b[++nb]=i;
					}
				}else{
					if(na<=nc){
						a[++na]=i;
					}else{
						c[++nc]=i;
					}
				}
			}else if(maxn==bb){
				if(bb==cc){
					if(nb<=nc){
						b[++nb]=i;
					}else{
						c[++nc]=i;
					}
				}else{
					b[++nb]=i;
				}
			}else{
				c[++nc]=i;
			}
		}
		int aa=stu[n].a,bb=stu[n].b,cc=stu[n].c;
		if(na>=(n/2))aa=-1;
		if(nb>=(n/2))bb=-1;
		if(nc>=(n/2))cc=-1;
		int maxn=max(max(aa,bb),cc);
		if(maxn==stu[n].a)a[++na]=n;
		else if(maxn==stu[n].b)b[++nb]=n;
		else if(maxn==stu[n].c)c[++nc]=n;
//		for(int i=1;i<=na;i++)cout<<stu[a[i]].a<<' ';
//		cout<<endl;
//		for(int i=1;i<=nb;i++)cout<<stu[b[i]].b<<' ';
//		cout<<endl;
//		for(int i=1;i<=nc;i++)cout<<stu[c[i]].c<<' ';
//		cout<<endl;
		for(int i=1;i<=na;i++)ans+=stu[a[i]].a;
		for(int i=1;i<=nb;i++)ans+=stu[b[i]].b;
		for(int i=1;i<=nc;i++)ans+=stu[c[i]].c;
        cout<<ans<<endl;        
    }
    return 0;
}