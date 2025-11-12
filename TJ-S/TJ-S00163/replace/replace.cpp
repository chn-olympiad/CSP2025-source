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
	int readstr(char* str){
		int len=0;
		char ch;
		ch=nc();
		while(ch<'a'||'z'<ch){
			ch=nc();
		}
		while('a'<=ch&&ch<='z'){
			str[len++]=ch;
			ch=nc();
		}
		return len;
	}
	#undef nc
}
using KitoTaisu::read;
using KitoTaisu::readstr;
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
namespace Violet{
	#define mod1 998244353
	#define mod2 1000000007
	int p131[2500002],p137[2500002];
	unsigned long long p233[2500002];
	void init(){
		p131[0]=p137[0]=p233[0]=1;
		for(int i=1;i<2500001;i++){
			p131[i]=(long long)(p131[i-1])*131%mod1;
			p137[i]=(long long)(p137[i-1])*137%mod2;
			p233[i]=p233[i-1]*233;
		}
	}
	struct hash_type{
		int len,hs1,hs2;
		unsigned long long hs3;
		bool operator ==(hash_type a){
			if(len==a.len&&hs1==a.hs1&&hs2==a.hs2&&hs3==a.hs3){
				return true;
			}
			return false;
		}
		bool operator <(const hash_type a)const{
			if(len!=a.len)return len<a.len;
			if(hs1!=a.hs1)return hs1<a.hs1;
			if(hs2!=a.hs2)return hs2<a.hs2;
			return hs3<a.hs3;
		}
		hash_type operator -(hash_type a){
			hash_type ret;
			ret.len=len-a.len;
			ret.hs1=(hs1+mod1-a.hs1)%mod1;
			ret.hs2=(hs2+mod2-a.hs2)%mod2;
			ret.hs3=hs3-a.hs3;
			return ret;
		}
		hash_type operator *(int x){
			hash_type ret;
			ret.len=len;
			ret.hs1=(long long)(hs1)*p131[x]%mod1;
			ret.hs2=(long long)(hs2)*p137[x]%mod2;
			ret.hs3=hs3*p233[x];
			return ret;
		}
		void print(){
			printf("len=%d hs1=%d hs2=%d hs3=%llu\n",len,hs1,hs2,hs3);
		}
	};
	hash_type hash_get(char* str,int len){
		hash_type ret={0,0,0,0};
		ret.len=len;
		for(int i=0;i<len;i++){
			ret.hs1=((long long)(ret.hs1)*131+str[i])%mod1;
			ret.hs2=((long long)(ret.hs2)*137+str[i])%mod2;
			ret.hs3=ret.hs3*233+str[i];
		}
		return ret;
	}
	void hash_array_get(char* str,int len,hash_type* hs){
		hs[0]={0,0,0,0};
		for(int i=1;i<=len;i++){
			hs[i].len=i;
			hs[i].hs1=((long long)(hs[i-1].hs1)*131+str[i-1])%mod1;
			hs[i].hs2=((long long)(hs[i-1].hs2)*137+str[i-1])%mod2;
			hs[i].hs3=hs[i-1].hs3*233+str[i-1];
		}
	}
	#undef mod1
	#undef mod2
}
set<int> possible_len;
map<Violet::hash_type,int> mp;
int n,q,tot_map,tot,rd1,rd2,head[200002];
long long ans;
struct Nephren{
	Violet::hash_type to;
	int nxt;
};
Nephren lk[200002];
Violet::hash_type qzh1[2500002],qzh2[2500002];
void add(Violet::hash_type u,Violet::hash_type v){
	int mpu;
	if(mp.find(u)==mp.end()){
		mp[u]=++tot_map;
		mpu=tot_map;
	}
	else mpu=mp[u];
	lk[++tot].nxt=head[mpu];
	lk[tot].to=v;
	head[mpu]=tot;
}
char str1[5000002],str2[5000002];
bool mark,lp[2500002];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Violet::init();
	n=read(),q=read();
	while(n--){
		rd1=readstr(str1),rd2=readstr(str2);
		possible_len.insert(rd1);
		//Violet::hash_get(str1,rd1).print(),Violet::hash_get(str2,rd2).print();
		add(Violet::hash_get(str1,rd1),Violet::hash_get(str2,rd2));
	}
	while(q--){
		rd1=readstr(str1),rd2=readstr(str2);
		//printf("Violet %d %s\nViolet %d %s\n",rd1,str1,rd2,str2);
		if(rd1!=rd2){
			//printf("Algebra ");
			printf("0\n");
			continue;
		}
		ans=0,mark=1;
		Violet::hash_array_get(str1,rd1,qzh1);
		Violet::hash_array_get(str2,rd2,qzh2);
		lp[rd1]=1;
		for(int i=rd1-1;i>=0;i--){
			if(mark){
				if(str1[i]!=str2[i]){
					mark=false;
					lp[i]=0;
				}
				else lp[i]=1;
			}
			else lp[i]=0;
		}
		for(int i=0;i<rd1;i++){
			if(i&&str1[i-1]!=str2[i-1]){
				//printf("Miyazono %c %c\n",str1[i-1],str2[i-1]);
				break;
			}
			for(set<int>::iterator it=possible_len.begin();it!=possible_len.end();it++){
				int sl=(*it);
				if(i+sl>rd1)break;
				if(!lp[i+sl])continue;
				Violet::hash_type zc1=qzh1[i+sl]-qzh1[i]*sl,zc2=qzh2[i+sl]-qzh2[i]*sl;
				//zc1.print(),zc2.print();
				if(mp.find(zc1)==mp.end()){
					//printf("Simaminikfilia\n");
					continue;
				}
				//printf("Siyuan\n");
				for(int j=head[mp[zc1]];j;j=lk[j].nxt){
					//printf("Chtholly %d\n",j);
					if(lk[j].to==zc2){
						ans++;
						//break;
					}
				}
			}
		}
		printf("%lld\n",ans);
		//for(int i=0;i<=rd1;i++)qzh1[i]=qzh2[i]={0,0,0,0};
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
