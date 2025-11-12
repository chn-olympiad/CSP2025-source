#include<bits/stdc++.h>
#define endl '\n' 
int n;
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N];
struct node{
	long long a,b,c;
}mb[N];
int cg[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int ca=0,cb=0,cc=0;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>mb[i].a>>mb[i].b>>mb[i].c;
			int mx=max(mb[i].a,max(mb[i].b,mb[i].c));
			if(mx==mb[i].a){
				a[++ca]=i;
				ans+=mb[i].a;
			}
			else if(mx==mb[i].b){
				b[++cb]=i;
				ans+=mb[i].b;
			}
			else{
				c[++cc]=i;
				ans+=mb[i].c;
			}
		} 
		if(ca>n/2){
			int cnt=0;
			for(int i=1;i<=ca;i++){
				int x=0;
				if(mb[a[i]].b>mb[a[i]].c)x=mb[a[i]].b;
				else x=mb[a[i]].c;
				x-=mb[a[i]].a;
				cg[++cnt]=x;
			}
			sort(cg+1,cg+1+ca);
			for(int i=n/2+1;i<=cnt;i++){
				ans+=cg[i];
			}
		}
		if(cb>n/2){
			int cnt=0;
			for(int i=1;i<=cb;i++){
				int x=0;
				if(mb[b[i]].a>mb[b[i]].c)x=mb[b[i]].a;
				else x=mb[b[i]].c;
				x-=mb[b[i]].b;
				cg[++cnt]=x;
			}
			sort(cg+1,cg+1+cb);
			for(int i=n/2+1;i<=cnt;i++){
				ans+=cg[i];
			}
			
		}
		if(cc>n/2){
			int cnt=0;
			for(int i=1;i<=cc;i++){
				int x=0;
				if(mb[c[i]].a>mb[c[i]].b)x=mb[c[i]].a;
				else x=mb[c[i]].b;
				x-=mb[c[i]].c;
				cg[++cnt]=x;
			}
			sort(cg+1,cg+1+cc);
			for(int i=n/2+1;i<=cnt;i++){
				ans+=cg[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
