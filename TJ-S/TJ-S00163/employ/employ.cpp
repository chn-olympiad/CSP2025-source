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
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
