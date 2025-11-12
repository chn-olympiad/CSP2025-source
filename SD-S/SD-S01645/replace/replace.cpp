#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N=5e6+9,b=13331;
ull s1[N],s2[N];
ull pb[N];
ull t1[N],t2[N];
int l[N];
ll fr(){
	ll x=0;
	char c=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x;
}
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pb[0]=1;
	for(int i=1;i<=5e6;i++) pb[i]=pb[i-1]*b;
	n=fr(),q=fr();
	for(int i=1;i<=n;i++){
		char c=getchar();
		ull s=0,t=0;
		while(c>='a'&&c<='z') s*=b,s+=c,t++,c=getchar();
		s1[i]=s,l[i]=t;
		c=getchar(),t=0,s=0;
		while(c>='a'&&c<='z') s*=b,s+=c,t++,c=getchar();
		s2[i]=s;
	}
	for(int i=1;i<=q;i++){
		ull ans=0;
		char c=getchar();
		int tot1=0,tot2=0;
		t1[0]=t2[0]=0;
		while(c>='a'&&c<='z') tot1++,t1[tot1]=t1[tot1-1]*b+c,c=getchar();
		c=getchar();
		while(c>='a'&&c<='z') tot2++,t2[tot2]=t2[tot2-1]*b+c,c=getchar();
		if(tot1!=tot2){
			printf("0");
			puts("");
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=tot1-l[i]+1;j++){
				if(s1[i]==t1[j+l[i]-1]-t1[j-1]*pb[l[i]]&&s2[i]==t2[j+l[i]-1]-t2[j-1]*pb[l[i]]){
					if(t1[j-1]==t2[j-1]&&t1[tot1]-t1[j+l[i]-1]*pb[tot1-j-l[i]+1]==t2[tot1]-t2[j+l[i]-1]*pb[tot1-j-l[i]+1]){
						ans++;break;
					}
				}
			}
		}
		printf("%llu",ans);
		puts("");
	}
	return 0;
}

