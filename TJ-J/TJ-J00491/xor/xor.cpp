#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<cassert>
int n,k;
const int maxn=5e5+5;
int a[maxn],s[maxn];
namespace Force{
	const int Fmaxn=1e3+5;
	struct item{
		int l,r,len;
		item(){}
		item(int l,int r):l(l),r(r),len(r-l+1){}
		friend bool operator <(item x,item y){
			return x.len<y.len;
		}
	}seg[Fmaxn*Fmaxn];
	int len=0;
	bool f[maxn];
	void solve(){
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				if((s[j]^s[i-1])==k){
					seg[++len]=item(i,j);
				}
			}
		std::sort(seg+1,seg+len+1);
		int max_=-1;
		for(int s=0;s<(1<<len);s++){
			for(int i=1;i<=n;i++) f[i]=false; 
			bool flag=true;
			for(int i=1;i<=len;i++)
				if(s>>(i-1)&1){
					assert(seg[i].l<=seg[i].r);
					for(int j=seg[i].l;j<=seg[i].r;j++){
						assert(1<=j&&j<=n);
						if(f[j]) flag=false; 
						else f[j]=true;
					}
				}
			if(flag){
				int cnt=0;
				for(int i=1;i<=len;i++) if(s>>(i-1)&1) cnt++;
				max_=std::max(max_,cnt);
			}
		}
		printf("%d\n",max_);
	}	
}
namespace maybe{
	const int Fmaxn=1e3+5;
	struct item{
		int l,r,len;
		item(){}
		item(int l,int r):l(l),r(r),len(r-l+1){}
		friend bool operator <(item x,item y){
			if(x.len!=y.len) return x.len<y.len;
			if(x.l!=y.l) return x.l<y.l;
			return x.r<y.r;
		}
	}seg[Fmaxn*Fmaxn];
	int len=0;
	bool f[maxn];
	void solve(){
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				if((s[j]^s[i-1])==k){
					seg[++len]=item(i,j);
				}
			}
		std::sort(seg+1,seg+len+1);
		int cnt=0;
		for(int i=1;i<=len;i++){
			bool flag=true;
			for(int j=seg[i].l;j<=seg[i].r;j++) if(f[j]) flag=false;
			if(flag){
				cnt++;
				for(int j=seg[i].l;j<=seg[i].r;j++) f[j]=true;
			}
		}
		printf("%d\n",cnt);
	}	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	int tmp=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				tmp++;
			}
		}
	if(tmp<=26) Force::solve();
	else maybe::solve();
	return 0;
}
