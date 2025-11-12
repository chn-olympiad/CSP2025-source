#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e6+500;
const unsigned int mod=1331;
int n,m,ans,l1,l2;
struct node{unsigned int x,y;int l1,l2;}a[maxn];
unsigned int h1[maxn],h2[maxn],p[maxn];
char s1[maxn],s2[maxn];
unsigned int get(unsigned int *h,int l,int r){return h[r]-h[l-1]*p[r-l+1];}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&m),p[0]=1;
	for(int i=1;i<=5e6;i++)p[i]=p[i-1]*mod;
	for(int j=1;j<=n;j++){
		scanf("%s%s",s1+1,s2+1),a[j].l1=strlen(s1+1),a[j].l2=strlen(s2+1);
		for(int i=1;i<=a[j].l1;i++)a[j].x=a[j].x*mod+(unsigned int)s1[i]-'a'+1;
		for(int i=1;i<=a[j].l2;i++)a[j].y=a[j].y*mod+(unsigned int)s2[i]-'a'+1;
	}
	while(m--){
		scanf("%s%s",s1+1,s2+1),ans=0,l1=strlen(s1+1),l2=strlen(s2+1);
		for(int i=1;i<=l1;i++)h1[i]=h1[i-1]*mod+s1[i]-'a'+1;
		for(int i=1;i<=l2;i++)h2[i]=h2[i-1]*mod+s2[i]-'a'+1;
		for(int k=1;k<=n;k++){
			if(l1-a[k].l1+a[k].l2!=l2)continue;
			for(int i=1;i+a[k].l1-1<=l1;i++){
				if(s1[i-1]!=s2[i-1])break;
				if(a[k].x==get(h1,i,i+a[k].l1-1)&&a[k].y==get(h2,i,i+a[k].l2-1)&&
					get(h1,i+a[k].l1,l1)==get(h2,i+a[k].l2,l2))ans++;
			}
		}printf("%lld\n",ans);
	}
	return 0;
}


