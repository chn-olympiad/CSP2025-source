#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+10;
const ull Base=2833;
string s1[N],s2[N],t1,t2;
vector<ull>H1[N],H2[N];
ull Pow[N],T1[N],T2[N];
int n,q,sz[N],l[N],r[N],L,R,ans;
ull gethash1(int x,int l,int r){
	return H1[x][r]-H1[x][l-1]*Pow[r-l+1];
}
ull gethash2(int x,int l,int r){
	return H2[x][r]-H2[x][l-1]*Pow[r-l+1];
}
ull gethasht1(int l,int r){
	return T1[r]-T1[l-1]*Pow[r-l+1];
}
ull gethasht2(int l,int r){
	return T2[r]-T2[l-1]*Pow[r-l+1];
}
void solve1(){
	while(q--){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		if(t1==t2){
			for(int i=1;i<=n;i++)
				if(l[i]>r[i])ans++;
			cout<<ans<<'\n';
			continue;
		}
		int szt=t1.size();
		t1=" "+t1,t2="*"+t2;
		for(int i=1;i<=szt;i++){
			T1[i]=T1[i-1]*Base+t1[i];
			T2[i]=T2[i-1]*Base+t2[i];
		}
		L=1,R=szt;
		while(L<=szt&&t1[L]==t2[L])L++;
		while(R>=1&&t1[R]==t2[R])R--;
		for(int i=1;i<=n;i++){
			if(l[i]>r[i])continue;
			if(r[i]-l[i]+1!=R-L+1)continue;
			if(gethash1(i,l[i],r[i])!=gethasht1(L,R)||
			gethash2(i,l[i],r[i])!=gethasht2(L,R))continue;
			if(L<l[i]||szt-R<sz[i]-r[i]){
//				cout<<"ooop! "<<q<<' '<<i<<'\n';
//				cout<<L<<' '<<R<<' '<<l[i]<<' '<<r[i]<<' '<<szt<<'\n';
				continue;
			}
			if(gethash1(i,1,l[i]-1)==gethasht1(L-l[i]+1,L-1)
			&&gethash2(i,r[i]+1,sz[i])==gethasht2(R+1,sz[i]-r[i]+R))ans++;
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	Pow[0]=1;
	for(int i=1;i<=2e5;i++)Pow[i]=Pow[i-1]*Base;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		sz[i]=int(s1[i].size());
		s1[i]=" "+s1[i],s2[i]="*"+s2[i];
		H1[i].push_back(0ull),H2[i].push_back(0ull);
		for(int j=1;j<=sz[i];j++){
			H1[i].push_back(H1[i].back()*Base+s1[i][j]);
			H2[i].push_back(H2[i].back()*Base+s2[i][j]);
		}
		l[i]=1,r[i]=sz[i];
		while(l[i]<=sz[i]&&s1[i][l[i]]==s2[i][l[i]])l[i]++;
		while(r[i]>=1&&s1[i][r[i]]==s2[i][r[i]])r[i]--;
	}
	solve1();
	return 0;
}