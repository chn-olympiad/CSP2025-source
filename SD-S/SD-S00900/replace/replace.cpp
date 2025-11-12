#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N=2e5+10;
const int M=5e6+10;
const int P=13331;
struct Node {
	ULL to;
	int nxt;
} a[N*2];
unordered_map<ULL,int> pre;
int n,q,K,d[M],len;
LL f[M];
char s[M],t[M],d1[M],d2[M];
ULL s1[M],s2[M],p[M];
void add(ULL x,ULL y) {
	K++;
	a[K]= {y,pre[x]};
	pre[x]=K;
}
ULL get1(int l,int r) {
	if(l>r) return 0;
	return s1[r]-s1[l-1]*p[r-l+1];
}
ULL get2(int l,int r) {
	if(l>r) return 0;
	return s2[r]-s2[l-1]*p[r-l+1];
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	p[0]=1;
	for(int i=1; i<=5000000; i++) p[i]=p[i-1]*P;
	for(int i=1; i<=n; i++) {
		scanf("%s%s",(s+1),(t+1));
		int len=strlen(s+1);
		ULL ss=0;
		for(int j=1; j<=len; j++) ss=ss*P+s[j];
		ULL S=0;
		for(int j=1; j<=len; j++) S=S*P+t[j];
		add(ss,S);
	}
	for(int o=1; o<=q; o++) {
		scanf("%s%s",(d1+1),(d2+1));
		int l1=strlen(d1+1);
		int l2=strlen(d2+1);
		if(l1!=l2) {
			printf("0\n");
		} else {
			for(int j=1; j<=l1; j++) s1[j]=s1[j-1]*P+d1[j];
			for(int j=1; j<=l2; j++) s2[j]=s2[j-1]*P+d2[j];
			LL ans=0;
			if(s1[l1]==s2[l1]) ans++;
			for(int i=pre[s1[l1]];i;i=a[i].nxt){
				ULL to=a[i].to;
				if(to==s2[l1]) ans++;
			}
			for(int i=0;i<=l1;i++){
				for(int j=i+2;j<=l1+1;j++){
					if(i==0&&j==l1+1) continue;
					ULL x=get1(i+1,j-1);
					for(int k=pre[x];k;k=a[k].nxt){
						ULL to=a[k].to;	
						if(get1(1,i)==get2(1,i)&&get1(j,l1)==get2(j,l1)&&to==get2(i+1,j-1)){
						//	cout<<i<<" "<<j<<'\n';	
							ans++;
						}
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}

