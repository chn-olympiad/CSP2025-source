#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
typedef unsigned long long ull;
const int N=2e5+5,Q=2e5+5,L=5e6+5,B=233;
int n,q,len1[N],len2[N],res[Q];
ull pw[L];
ull h1[N],h2[N];
vector<ull> hh1,hh2;
string a[N],b[N],qa[Q],qb[Q];
bool SPEB=1;
inline bool checkSPE(string s){
	bool visb=0;
	for(char i:s){
		if(i=='b'){
			if(visb) return 0;
			visb=1;
		}else if(i!='a') return 0;
	}
	return 1;
}
inline int getp(string a,string b,int n){
	int pa=0,pb=0;
	for(int i=1;i<=n;i++){
		if(a[i]=='b') pa=i;
		if(b[i]=='b') pb=i;
	}
	return pb-pa+L;
}
inline int getx(string a,int n){
	for(int i=1;i<=n;i++) if(a[i]=='b') return i;
	return 0;
}
inline int gety(string a,int n){
	for(int i=1;i<=n;i++) if(a[n-i+1]=='b') return i;
	return 0;
}
inline void init(vector<ull>& h,string& s,int n){
	h.resize(n+1);
	for(int i=1;i<=n;i++) h[i]=h[i-1]*B+s[i];
}
inline ull get(vector<ull>& h,int l,int r){
	return h[r]-h[l-1]*pw[r-l+1];
}
inline ull cc(string& s,int n){
	ull a=0;
	for(int i=1;i<=n;i++) a=a*B+s[i];
	return a;
}
inline int lb(int x){return x&-x;}
struct Point{int x,y,id;};
inline bool cmp(Point a,Point b){return a.x<b.x;}
struct BIT{
	int s[L];
	inline void chp(int x,int v){for(;x<L;x+=lb(x)) s[x]+=v;}
	inline void clr(int x){for(;x<L;x+=lb(x)) if(s[x]) s[x]=0;else return;}
	inline int qry(int x){int a=0;for(;x;x-=lb(x)) a+=s[x];return a;}
}bit;
vector<Point> pt[2*L],qr[2*L];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	pw[0]=1;for(int i=1;i<L;i++) pw[i]=pw[i-1]*B;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(SPEB&&(!checkSPE(a[i])||!checkSPE(b[i]))) SPEB=0;
		len1[i]=a[i].size(),a[i]=' '+a[i],b[i]=' '+b[i];
		h1[i]=cc(a[i],len1[i]),h2[i]=cc(b[i],len1[i]);
	}
	for(int i=1;i<=q;i++){
		cin>>qa[i]>>qb[i];
		if(SPEB&&(!checkSPE(qa[i])||!checkSPE(qb[i]))) SPEB=0;
		len2[i]=qa[i].size(),qa[i]=' '+qa[i],qb[i]=' '+qb[i];
	}
	if(SPEB){//25pts SPEB 二维数点
		for(int i=1;i<=n;i++){
			pt[getp(a[i],b[i],len1[i])].eb(Point{getx(a[i],len1[i]),gety(a[i],len1[i]),0});
		}
		for(int i=1;i<=q;i++){
			qr[getp(qa[i],qb[i],len2[i])].eb(Point{getx(qa[i],len2[i]),gety(qa[i],len2[i]),i});
		}
		for(int i=0;i<2*L;i++){
			sort(pt[i].begin(),pt[i].end(),cmp);
			sort(qr[i].begin(),qr[i].end(),cmp);
			int j=0,siz=pt[i].size();
			for(Point p:qr[i]){
				while(j<siz&&pt[i][j].x<=p.x) bit.chp(pt[i][j].y,1),j++;
				res[p.id]+=bit.qry(p.y);
			}
			for(Point j:pt[i]) bit.clr(j.y);//清空BIT 
		}
		for(int i=1;i<=q;i++) cout<<res[i]<<"\n";
	}else{//45pts O(qL)
		for(int koishi=1;koishi<=q;koishi++){
			string a=qa[koishi],b=qb[koishi];
			if(a.size()!=b.size()){
				cout<<"0\n";
				continue;
			}
			int m=len2[koishi],ans=0,lp=0,rp=0;
			for(int i=1;i<=m;i++) if(a[i]^b[i]){
				if(!lp) lp=i;
				rp=i;
			}
			init(hh1,a,m),init(hh2,b,m); 
			for(int num=1;num<=n;num++){
	//			cout<<"======================== NUM = "<<num<<"\n";
				for(int i=1,j;(j=i+len1[num]-1)<=m;i++){
					if(i>lp||j<rp) continue;
	//				cout<<"I : "<<i<<"\n";
	//				cout<<"    "<<get(hh1,i,j)<<" "<<h1[num]<<"\n";
	//				cout<<"    "<<get(hh2,i,j)<<" "<<h2[num]<<"\n";
					if(get(hh1,i,j)==h1[num]&&get(hh2,i,j)==h2[num]){
						ans++;
						break;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
