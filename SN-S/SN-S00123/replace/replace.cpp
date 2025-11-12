//Hash + ACautomation
#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#define  ull  unsigned long long
using namespace std;
constexpr int N=2e5+5,M=5e6+5,p=131;
struct ACautomaiton{
	int n,m;
	char s1[M],s2[M];
	int len[N];
	ull has1[N],has2[N],ps[M];
	ull ha1[M],ha2[M];
	int tr[M][26],cnt,fail[M];
	queue<int> q; vector<int> v[M];
	void build_tree(int ii){
		int le=strlen(s1+1),pos=0;
		for(int i=1;i<=le;i++){
			if(!tr[pos][s1[i]-'a'])
				tr[pos][s1[i]-'a']=++cnt;
			pos=tr[pos][s1[i]-'a'];
		}v[pos].push_back(ii),len[ii]=le;
		for(int i=1;i<=le;i++)
			has1[ii]=has1[ii]*p+s1[i],
			has2[ii]=has2[ii]*p+s2[i];
	}void get_fail(){
		for(int i=0;i<26;i++)
			if(tr[0][i])q.push(tr[0][i]);
		while(!q.empty()){
			int x=q.front(); q.pop();
			for(int i=0;i<26;i++)
				if(!tr[x][i])tr[x][i]=tr[fail[x]][i];
				else fail[tr[x][i]]=tr[fail[x]][i],q.push(tr[x][i]);
		}
	}bool check(int i,int ii,int le){
		ull aa2=ha2[i]-ha2[i-len[ii]]*ps[len[ii]];
		if(aa2!=has2[ii])return 0;
		if(ha1[i-len[ii]]!=ha2[i-len[ii]])return 0;
		ull cc1=ha1[le]-ha1[i]*ps[le-i];
		ull cc2=ha2[le]-ha2[i]*ps[le-i];
//		cout<<i<<' '<<ii<<' '<<le<<'\n';
		if(cc1!=cc2)return 0;
//		cout<<i<<' '<<ii<<'\n';
		return 1;
	}void solve(){
		cin>>(s1+1)>>(s2+1); 
		int le=strlen(s1+1),pos=0,ans=0;
		int le2=strlen(s2+1);
		if(le!=le2){ cout<<"0\n"; return; }
		for(int i=1;i<=le;i++)
			ha1[i]=ha1[i-1]*p+s1[i],
			ha2[i]=ha2[i-1]*p+s2[i];
		for(int i=1;i<=le;i++){
			pos=tr[pos][s1[i]-'a'];
			for(int j:v[pos])ans+=check(i,j,le);
		}cout<<ans<<'\n';
	}void work(){
		ps[0]=1; cin>>n>>m;
		for(int i=1;i<=5e6;i++)ps[i]=ps[i-1]*p;
		for(int i=1;i<=n;i++)
			cin>>(s1+1)>>(s2+1),build_tree(i);
		get_fail();
		for(int i=1;i<=cnt;i++)
			for(int j:v[fail[i]])
				v[i].push_back(j);
		for(int i=1;i<=m;i++)solve();
	}
}ac;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ac.work(); return 0;
}
/*



*/
