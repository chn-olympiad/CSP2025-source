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
	char *p1,*p2,buf[10002];
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
}
int t,n,a1,a2,a3,tj1,tj2,tj3,mnum,c1[100002],c2[100002],c3[100002];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	//printf("%d\n",t);
	while(t--){
		memset(c1,0x3f,sizeof(c1));
		memset(c2,0x3f,sizeof(c2));
		memset(c3,0x3f,sizeof(c3));
		tj1=tj2=tj3=ans=0;
		n=read();
		//printf("%d\n",n);
		for(int i=1;i<=n;i++){
			a1=read(),a2=read(),a3=read();
			//printf("%d %d %d\n",a1,a2,a3);
			if(a1>=a2&&a1>=a3){
				tj1++;
				c1[i]=a1-max(a2,a3);
				ans+=a1;
			}
			else if(a2>a1&&a2>=a3){
				tj2++;
				c2[i]=a2-max(a1,a3);
				ans+=a2;
			}
			else if(a3>a1&&a3>a2){
				tj3++;
				c3[i]=a3-max(a1,a2);
				ans+=a3;
			}
		}
		if(tj1>n/2){
			mnum=tj1-n/2;
			sort(c1+1,c1+n+1);
			for(int i=1;i<=mnum;i++){
				ans-=c1[i];
			}
		}
		else if(tj2>n/2){
			mnum=tj2-n/2;
			sort(c2+1,c2+n+1);
			for(int i=1;i<=mnum;i++){
				ans-=c2[i];
			}
		}
		else if(tj3>n/2){
			mnum=tj3-n/2;
			sort(c3+1,c3+n+1);
			for(int i=1;i<=mnum;i++){
				ans-=c3[i];
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
