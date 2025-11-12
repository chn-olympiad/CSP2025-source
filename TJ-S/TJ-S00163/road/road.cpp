//remember ll
//remember change file
//remember run in Lunix
//remember don't use hack name
#include<iostream>
#include<string>
#include<cstdlib>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
namespace KitoTaisu{
	char *p1,*p2,buf[10000];
	#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,stdin),p1==p2)?EOF:*p1++)
	int read(){
		int x=0,f=1;
		char ch;
		ch=nc();
		while(ch<48||57<ch){
			if(ch=='-')f=-1;
			ch=nc();
		}
		while(47<ch&&ch<58){
			x=x*10+ch-48;
			ch=nc();
		}
		return x*f;
	}
	#undef nc
}
using KitoTaisu::read;
namespace Chtholly{
	struct Chtholly{
		int l,r;
		mutable int val;
		bool operator <(const Chtholly a)const{
			return l<a.l;
		}
	};
	#define si set<Chtholly>::iterator
	class ChthollyTree{
		private:
			set<Chtholly> tree;
			si split(int x){
				si it=tree.lower_bound({x,0,0});
				if(it!=tree.end()&&it->l==x)return it;
				it--;
				int l=it->l,r=it->r,val=it->val;
				tree.erase(it);
				tree.insert({l,x-1,val});
				return tree.insert({x,r,val}).first;
			}
			si get(int x){
				si it=tree.lower_bound({x,0,0});
				if(it!=tree.end()&&it->l==x)return it;
				it--;
				return it;
			}
		public:
			void assign(int l,int r,int val){
				si itr=split(r+1),itl=split(l);
				tree.erase(itl,itr);
				tree.insert({l,r,val});
			}
			void change(int l,int r,int val){
				si itr=split(r+1),itl=split(l);
				for(si it=itl;it!=itr;it++){
					//do
				}
			}
			int query(int l,int r,int val){
				int ret=0;
				si itr=split(r+1),itl=split(l);
				for(si it=itl;it!=itr;it++){
					//do
				}
				return ret;
			}
	};
	#undef si
}
namespace Miyazono{
	int fa[10002];
	void init(int n){
		for(int i=1;i<=n;i++)fa[i]=i;
	}
	int find(int x){
		int ret=x,nv;
		while(ret!=fa[ret]){
			ret=fa[ret];
		}
		while(x!=ret){
			nv=fa[x];
			fa[x]=ret;
			x=nv;
		}
		return ret;
	}
	void merge(int x,int y){
		x=find(x),y=find(y);
		fa[x]=y;
	}
}
int n,m,k,used,Min,c[12],a[10002][12];
long long ans=0x7fffffffffffffff,sum;
bool mark;
struct Nephren{
	int u,v,val,pic;
	bool operator <(const Nephren a)const{
		return val<a.val;
	}
};
Nephren mp[11000002];
void solve(int seed){
	Miyazono::init(n);
	used=0;
	sum=0;
	for(int i=0;i<k;i++){
		if(seed&(1<<i))sum+=c[i];
	}
	for(int i=1;i<=m;i++){
		if(used==n-1)break;
		if(Miyazono::find(mp[i].u)==Miyazono::find(mp[i].v)||(mp[i].pic!=0x75&&(!(seed&(1<<mp[i].pic))))){
			continue;
		}
		sum+=mp[i].val;
		Miyazono::merge(mp[i].u,mp[i].v);
		used++;
	}
	//if(used==n-1)
	ans=min(ans,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		mp[i].u=read(),mp[i].v=read(),mp[i].val=read(),mp[i].pic=0x75;
	}
	mark=1;
	for(int i=0;i<k;i++){
		c[i]=read();
		if(c[i])mark=0;
		for(int j=1;j<=n;j++)a[j][i]=read();
	}
	if(k&&mark){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				Min=a[i][0]+a[j][0];
				for(int p=1;p<k;p++){
					Min=min(Min,a[i][p]+a[j][p]);
				}
				m++;
				mp[m].u=i,mp[m].v=j,mp[m].val=Min,mp[m].pic=0x75;
			}
		}
		sort(mp+1,mp+m+1);
		solve(0);
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				for(int p=0;p<k;p++){
					m++;
					mp[m].u=i,mp[m].v=j,mp[m].val=a[i][p]+a[j][p],mp[m].pic=p;
				}
			}
		}
		sort(mp+1,mp+m+1);
		for(int i=(1<<k)-1;i>=0;i--){
			solve(i);
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
