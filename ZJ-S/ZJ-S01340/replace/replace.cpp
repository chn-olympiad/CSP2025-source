#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN=2e5+5;
const int MAXL=5e6+5;
int n,q;
string p[MAXN][2];
string s,t;
vector<int>kmp[MAXN];
const int P=97;
ull Hsh_p1[MAXN];
ull Hsh_s[MAXL],Hsh_t[MAXL];
ull h[MAXL];
int lenp[MAXN];
inline ull getHsh(int l,int r,ull *harr){
	return harr[r]%h[r-l+1];
}
void getkmp(string &s,int now){
	int lens=lenp[now],j=0;
	for(int i=2;i<=lens;i++){
		while(j&&s[j+1]!=s[i])j=kmp[now][j];
		if(s[j+1]==s[i]) j++;
		kmp[now][i]=j;
	}
}
bool rplace(string &s,string &t,int now){
	int lens=s.size()-1,lent=t.size()-1,j=0;
	for(int i=1;i<=lens;i++){
		while(j&&p[now][0][j+1]!=s[i]) j=kmp[now][j];
		if(p[now][0][j+1]==s[i]) j++;
		if(j==lenp[now]){
			//cerr<<j<<endl;
			int beg=i-lenp[now]+1;
			
			bool flag=true;
			for(int k=1,o=beg;k<=lenp[now],o<=beg+lenp[now]-1;k++,o++)
				if(p[now][1][k]!=t[o]){
					flag=false;
				}
			for(int k=1;k<=lent;k++){
				if(k>=beg&&k<=beg+lenp[now]-1)continue;
				if(s[k]!=t[k])
					flag=false;
			}
			if(flag==true)
				return true;
			/*	bool flag=true;
			if(getHsh(beg,beg+lenp[now]-1,Hsh_t)!=getHsh(1,lenp[now],Hsh_p1))
				flag=false;
			if(beg>1){
				if(getHsh(1,beg-1,Hsh_s)!=getHsh(1,beg-1,Hsh_t))
					flag=false;
			}
			if(lent>beg+lenp[now]-1){
				if(getHsh(beg+lenp[now],lent,Hsh_s)!=getHsh(beg+lenp[now],lent,Hsh_t))
					flag=false;
			}
			if(flag==true)
				return true;*/
			j=kmp[now][j];
		}
	}
	return false;
}
signed main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	h[0]=1;
	for(int i=1;i<=MAXL;i++)
		h[i]=h[i-1]*P;
	for(int i=1;i<=n;i++){
		cin>>p[i][0]>>p[i][1];
		lenp[i]=p[i][0].size();
		p[i][0].insert(0," ");
		p[i][1].insert(0," ");
		kmp[i].resize(lenp[i]+5);
		Hsh_p1[0]=0;
		for(int j=1;j<=lenp[i];j++)
			Hsh_p1[j]=(Hsh_p1[j-1]*P)+(p[i][1][j]-'a');
		getkmp(p[i][0],i);
	}
	for(;q;q--){
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<0<<"\n";
			continue;
		}
		s.insert(0," "),t.insert(0," ");
		Hsh_s[0]=0,Hsh_t[0]=0;
		for(int i=1;i<=s.size()-1;i++)
			Hsh_s[i]=(Hsh_s[i-1]*P)+(s[i]-'a');
		for(int i=1;i<=t.size()-1;i++)
			Hsh_t[i]=(Hsh_t[i-1]*P+(s[i]-'a'));
		int ans=0;
		for(int i=1;i<=n;i++)
			if(rplace(s,t,i))
				ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
