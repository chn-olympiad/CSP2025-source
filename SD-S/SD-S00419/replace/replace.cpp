#include<bits/stdc++.h>
#define rd read()
#define ll long long
#define ULL unsigned long long
#define lbt(x) ((x)&(-(x)))
#define Cmax(a,b) (a=max(a,(b)))
#define Cmin(a,b) (a=min(a,(b)))
#define for_(a,b,c) for(int a=(b);a<=(c);++a)
#define For_(a,b,c) for(int a=(b);a>=(c);--a)
#define md ((l+r)/2)
#define pi pair<int,int>
#define fs first
#define sc second
using namespace std;
	int n,q;
	const int N=5e6+10;
	ULL hsbs=233,hsp[N];
	struct node{
		string a,b;
		int len,L,R;
		vector<ULL>ha;
		vector<ULL>hb;
		ULL getha(int l,int r){
			return ha[r]-ha[l-1]*hsp[r-l+1];
		}
		ULL gethb(int l,int r){
			return hb[r]-hb[l-1]*hsp[r-l+1];
		}
		void init(){
			len=a.length()-1;
			ha.resize(len+2);
			hb.resize(len+2);
			ha[0]=0;
			for_(i,1,len){
				ha[i]=ha[i-1]*hsbs+a[i]-'a'+1;
			}
			hb[0]=0;
			for_(i,1,len){
				hb[i]=hb[i-1]*hsbs+b[i]-'a'+1;
			}
			int l=1,r=len;
			while(l<r){
				int mid=l+r>>1;
				if(getha(1,mid)!=gethb(1,mid))r=mid;
				else l=mid+1;
			}
			L=l;
			l=1,r=len;
			while(l<r){
				int mid=l+r+1>>1;
				if(getha(mid,len)!=gethb(mid,len))l=mid;
				else r=mid-1;
			}
			R=l;
		}
	}e[200010],qr;
	map<ULL,int>mp;
	vector<int>v[N];
	void work_BF(){
		int totres=0;
		for_(i,1,n){
			cin>>e[i].a>>e[i].b;
			e[i].a=' '+e[i].a;
			e[i].b=' '+e[i].b;
			e[i].init();
			ULL res=e[i].getha(e[i].L,e[i].R)*hsp[e[i].R-e[i].L+1]+e[i].gethb(e[i].L,e[i].R);
			if(mp.find(res)!=mp.end()){
				v[mp[res]].push_back(i);
			}
			else{
				mp[res]=++totres;
				v[totres].push_back(i);
			}
//			cout<<e[i].L<<" "<<e[i].R<<"\n";
		}
//		cout<<"\n\n";
		for_(TT,1,q){
			cin>>qr.a>>qr.b;
			if(qr.a.length()!=qr.b.length()){
				cout<<"0\n";continue;
			}
			qr.a=' '+qr.a;
			qr.b=' '+qr.b;
			int cnt=0;
			qr.init();
			ULL res=qr.getha(qr.L,qr.R)*hsp[qr.R-qr.L+1]+qr.gethb(qr.L,qr.R);
			if(mp.find(res)==mp.end()){
				cout<<"0\n";continue;
			}
			for(auto i:v[mp[res]]){
				if(e[i].getha(e[i].L,e[i].R)==qr.getha(qr.L,qr.R)&&e[i].gethb(e[i].L,e[i].R)==qr.gethb(qr.L,qr.R)){
					int lftlen=e[i].L-1;
					if(qr.L-1-lftlen+1<1)continue;
					if(e[i].getha(1,lftlen)!=qr.getha(qr.L-1-lftlen+1,qr.L-1))continue;
					int rgtlen=e[i].len-e[i].R;
					if(qr.R+1+rgtlen-1>qr.len)continue;
					if(e[i].getha(e[i].R+1,e[i].R+1+rgtlen-1)!=qr.getha(qr.R+1,qr.R+1+rgtlen-1))continue;
					++cnt;
				}
			}
			cout<<cnt<<"\n";
		}
	}
//	inline ll read(){ll d=0,f=0;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}while(ch>='0'&&ch<='9'){d=(d<<1)+(d<<3)+ch-'0';ch=getchar();}return f?-d:d;}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	hsp[0]=1;
	for_(i,1,N-5)hsp[i]=hsp[i-1]*hsbs;
	work_BF();
	
	
	
	
	
	
	return 0;
}
