#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int read(){
	int x;
	scanf("%d",&x);
	return x;
}
struct node{
	int pos;
	int crit;
	int s;
}ex[100001];
int t;
int a[100001];
int b[100001];
int c[100001];
bool cmp(node q,node w){
	if(q.s!=w.s) return q.s<w.s;
	return q.crit<w.crit;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read(); 
	while(t--){
		int n=read();
		int aa=0,bb=0,cc=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			b[i]=read();
			c[i]=read();
			if(a[i]>=b[i]&&a[i]>=c[i]) aa++;
			else if(b[i]>=c[i]&&b[i]>=a[i]) bb++;
			else if(c[i]>=a[i]&&c[i]>=b[i]) cc++;
		}
		int sz=n/2;
		int cnt=0;
		if(aa>sz){
			int x=aa-sz;
			int ans=0;
			for(int i=1;i<=n;i++){
				if(max(a[i],max(b[i],c[i]))!=a[i]){
					ans+=max(a[i],max(b[i],c[i]));
					continue;
				}
				ex[++cnt].s=min(a[i]-b[i],a[i]-c[i]);
				ex[cnt].pos=i;
				ex[cnt].crit=a[i];
				ans+=a[i];
			}
			sort(ex+1,ex+cnt+1,cmp);
			for(int i=1;i<=x;i++){
				ans-=ex[i].s;
			}
			printf("%d\n",ans);
		}else if(bb>sz){
			int x=bb-sz;
			int ans=0;
			for(int i=1;i<=n;i++){ 
				if(max(a[i],max(b[i],c[i]))!=b[i]){
					ans+=max(a[i],max(b[i],c[i]));
					continue;
				}
				ex[++cnt].s=min(b[i]-a[i],b[i]-c[i]);
				ex[cnt].pos=i;
				ex[cnt].crit=b[i];
				ans+=b[i];
			}
			sort(ex+1,ex+cnt+1,cmp);
			for(int i=1;i<=x;i++){
				ans-=ex[i].s;
			}
			printf("%d\n",ans);
		}else if(cc>sz){
			int x=cc-sz;
			int ans=0;
			for(int i=1;i<=n;i++){
				if(max(a[i],max(b[i],c[i]))!=c[i]){
					ans+=max(a[i],max(b[i],c[i]));
					continue;
				}
				ex[++cnt].s=min(c[i]-a[i],c[i]-b[i]);
				ex[cnt].pos=i;
				ex[cnt].crit=c[i];
				ans+=c[i];
			}
			sort(ex+1,ex+cnt+1,cmp);
			for(int i=1;i<=x;i++){
				ans-=ex[i].s;
			}
			printf("%d\n",ans);
		}else{
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(a[i],max(b[i],c[i]));
			} 
			printf("%d\n",ans);
		}
	}
	return 0;
}
