#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define maxn 200006
int C;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
map<pair<int,int>,int>mp;
int cnt=0;
int pr[maxn],ba[maxn];
int ls[maxn],rs[maxn],ms[maxn];
vector<int>tag[maxn];
set<int>far,bar;
int qpow(int x,int t){
	int res=1;
	while(t){
		if(t&1)res*=x;
		x*=x; t>>=1;
	}
	return res;
}
int hs(int x){
	return (x<<1)+(x>>3)+(x>>C);
}
int countt=0;
void solve(){
	countt++;
	int ans=0;
	far.clear(); bar.clear();
	far.insert(0); bar.insert(0);
	string In1,In2;
	cin>>In1>>In2;
	if(In1.size()!=In2.size()){
		printf("0\n");
		return;
	}
	int l=-1,r=In1.size();
	while(l+1<In1.size()&&In1[l+1]==In2[l+1])l++;
	while(r-1>=0&&In1[r-1]==In2[r-1])r--;
	l++,r--;
	int e1,e2,e3;
	if(l>r){
		e1=0,e2=0,e3=In1.length();
		int res=0;
		for(int i=0;i<In1.length();i++)res+=hs((In1[i]-'a'+1)*qpow(C,i));
		pair<int,int>R; R.first=res; R.second=res;
		if(mp.count(R)){
			int p=mp[R];
			for(int i=0;i<tag[p].size();i++){
				if(far.count(pr[tag[p][i]])&&bar.count(ba[tag[p][i]])&&ls[tag[p][i]]<=e1&&rs[tag[p][i]]<=e2&&ms[tag[p][i]]==e3)ans++;
			}
		}
	}
	else{
		e1=l; e2=In1.length()-1-r; e3=r-l+1;
		int u1=0,u2=0;
		for(int i=l;i<=r;i++)u1+=hs((In1[i]-'a'+1)*qpow(C,i-l));
		for(int i=l;i<=r;i++)u2+=hs((In2[i]-'a'+1)*qpow(C,i-l));
		int num=0;
		for(int i=l-1;i>=0;i--)num=(num*C+(In1[i]-'a'+1)),far.insert(num);
		num=0;
		for(int i=r+1;i<In1.size();i++)num+=hs((In1[i]-'a'+1)*qpow(C,i-r-1)),bar.insert(num);
		pair<int,int> P;
		P.first=u1; P.second=u2;
		if(mp.count(P)){
			int p=mp[P];
			for(int i=0;i<tag[p].size();i++){
				if(far.count(pr[tag[p][i]])&&bar.count(ba[tag[p][i]])&&ls[tag[p][i]]<=e1&&rs[tag[p][i]]<=e2&&ms[tag[p][i]]==e3)ans++;
			}
		}
	}
	write(ans); cout<<'\n';
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0)); C=119;
	int n,q;
	n=read();  q=read(); string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int l=-1,r=s1.size(); int sz=s1.size();
		while(l+1<sz&&s1[l+1]==s2[l+1])l++;
		while(r-1>=0&&s1[r-1]==s2[r-1])r--;
		l++; r--;
		int u1=0,u2=0,u3=0,u4=0;
		if(l>r){
			int res=0;
			for(int j=0;j<s1.length();j++)res+=hs((s1[j]-'a'+1)*qpow(C,j));
			u3=u4=res;
			ls[i]=rs[i]=0,ms[i]=s1.length();
		}
		else{
			int res=0;
			for(int j=l;j<=r;j++)res+=hs((s1[j]-'a'+1)*qpow(C,j-l));
			u3=res; res=0;
			for(int j=l;j<=r;j++)res+=hs((s2[j]-'a'+1)*qpow(C,j-l));
			u4=res; res=0;
			for(int j=0;j<l;j++)res+=(s1[j]-'a'+1)*qpow(C,j);
			u1=res; res=0;
			for(int j=r+1;j<s1.size();j++)res+=hs((s1[j]-'a'+1)*qpow(C,j-r-1));
			u2=res; res=0;
			ls[i]=l; rs[i]=s1.length()-1-r; ms[i]=r-l+1;
		}
		pair<int,int>T; T.first=u3; T.second=u4;  pr[i]=u1; ba[i]=u2;	
		if(!mp.count(T)){
			++cnt; mp[T]=cnt;
		}
		tag[mp[T]].push_back(i);
	}
	for(int i=1;i<=q;i++){
		solve();
	}
	return 0;
}