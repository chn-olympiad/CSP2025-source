#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cstdlib>
using namespace std;
long long read(){
	long long dat=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')t=-t;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		dat=(dat<<1)+(dat<<3)+(ch&15);
		ch=getchar();
	}
	return dat*t;
}
struct node{
	long long ans;
	long long sum;
};
node c[500004];
long long n,m,k,t,tot,a[500004],b[500004],d[500004],e[500004],p[500004];
bool cmp(node x,node y){
	if(x.sum==y.sum){
		return x.ans>y.ans;
	}
	return x.sum<y.sum;
}
bool eemp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long i;
	n=read();
	k=read();
	if(n>10000){
		for(i=1;i<=n;i++){
			a[i]=read();
			b[i]=b[i-1]^a[i];
			c[i].sum=b[i];
			c[i].ans=i;
		}
		sort(c+1,c+n+1,cmp);
		for(i=1;i<=n;i++){
			d[i]=c[i].sum;
			e[i]=c[i].ans;
			p[i]=-1;
		}
		e[n+1]=-999999999;
		for(i=1;i<=n;i++){
			if(a[e[i]]==k){
				p[e[i]]=e[i];
				continue;
			}
			long long l,r,j;
			t=k^d[i];
			l=lower_bound(d,d+n,t)-d;
			r=upper_bound(d,d+n,t)-d;
			j=upper_bound(e+l,e+r+1,e[i],eemp)-e;
			if(e[j]<e[i]&&d[j]==t){
				p[e[i]]=e[j]+1;
			}
		}
		for(i=1;i<=n;i++){
			if(p[i]!=-1&&p[i]>m){
				m=p[i];
				tot+=1;
			}
		}
		printf("%lld",tot);
	}else{
		long long j;
		for(i=1;i<=n;i++){
			a[i]=read();
			b[i]=b[i-1]^a[i];
		}
		m=0;
		for(i=1;i<=n;i++){
			for(j=m;j<i;j++){
				long long h=b[i]^b[j];
				if(h==k){
					m=i;
					tot+=1;
					long long h=b[i]^b[j];
					break;
				}
			}
		}
		printf("%lld",tot);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

