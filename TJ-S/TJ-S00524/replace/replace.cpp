#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
template <typename T> bool tense(T &a,const T &b){return b<a?a=b,true:false;}
template <typename T> bool relax(T &a,const T &b){return b>a?a=b,true:false;}

int n,q;

namespace Force{
	const int N = 110,L = 210,P = 131,mod = 13331;
	char str[L];
	std::string s1[N],s2[N],t1,t2;
	std::vector<int> h1[N],h2[N],ht1,ht2;
	int pp[N];
	
	void scan(std::string &t){
		scanf("%s",str);t = str;
	}
	void hasher(std::string s,std::vector<int> h){
		pp[0] = 1;
		for(int j=0;j<(int)s.size();j++){
			int ha = s[j]%P;
			if(j>0) ha = (1ll*h.back()*P+ha)%mod;
			h.push_back(ha);
			pp[j+1] = (1ll*pp[j]*P)%mod;
		}
	}
	int geth(std::vector<int> h,int l,int r){
		if(l==0) return h[r];
		return ((h[r]-h[l-1]*pp[l-1])%mod+mod)%mod;
	}
	bool _equal(std::vector<int> h1,std::vector<int> h2,int l,int r){
		return geth(h1,l,r)==geth(h2,l,r);
	}
	void solve(){
		for(int i=1;i<=n;i++) scan(s1[i]),scan(s2[i]);
		for(int i=1;i<=n;i++) hasher(s1[i],h1[i]),hasher(s2[i],h2[i]);
		while(q--){
			scan(t1),scan(t2);
			hasher(t1,ht1),hasher(t2,ht2);
			int res = 0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<(int)t1.size();j++){
					if(j>=(int)s1[i].size()){
						if(!_equal(h1[i],ht1,j-(int)s1[i].size()+1,j)) continue;
						if(_equal(h1[i],ht1,0,j-s1[i].size()) && _equal(h2[i],ht2,j-(int)s1[i].size()+1,j) && _equal(h1[i],ht1,s1[i].size()+1,t1.size())) res++;
					}
				}
			} 
			printf("%d\n",res);
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	Force::solve();
	return 0;
}

