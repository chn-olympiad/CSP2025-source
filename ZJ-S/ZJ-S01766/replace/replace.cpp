#include<bits/stdc++.h>
using namespace std;
#define ll long long
void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
#define B1 31
#define B2 101
#define P1 998244353
#define P2 1000000007
int n,q,st1[200010];
ll pw1[5000010],pw2[5000010];
vector<pair<ll,ll> > sh1[200010],sh2[200010],th1,th2;
string s1[200010],s2[200010],t1,t2;
map<pair<pair<ll,ll>,pair<ll,ll> >,vector<int> > mp;
char s[5000010];
void hsh(string &x,vector<pair<ll,ll> > &v){
	v.clear();
	ll h1=0,h2=0;
	v.push_back({0,0});
	for(int i=0;i<x.size();i++){
		h1=(B1*h1+x[i])%P1;
		h2=(B2*h2+x[i])%P2;
		v.push_back({h1,h2});
	}
}
pair<ll,ll> get(vector<pair<ll,ll> > &v,int l,int r){
	if(l<0||r>=v.size()) return {-1,-1};
	return {((v[r+1].first-v[l].first*pw1[r-l+1])%P1+P1)%P1,((v[r+1].second-v[l].second*pw2[r-l+1])%P2+P2)%P2};
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=5000000;i++)
		pw1[i]=(pw1[i-1]*B1)%P1,pw2[i]=(pw2[i-1]*B2)%P2;
	read(n),read(q);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		s1[i]=string(s);
		hsh(s1[i],sh1[i]);
		scanf("%s",s);
		s2[i]=string(s);
		hsh(s2[i],sh2[i]);
		int st=-1,en=-1;
		for(int j=0;j<s1[i].size();j++)
			if(s1[i][j]!=s2[i][j]){
				if(st==-1) st=j;
				en=j;
			}
		mp[{get(sh1[i],st,en),get(sh2[i],st,en)}].push_back(i);
		st1[i]=st;
	}
	while(q--){
		scanf("%s",s);
		t1=string(s);
		hsh(t1,th1);
		scanf("%s",s);
		t2=string(s);
		hsh(t2,th2);
		if(t1.size()!=t2.size()){
			puts("0");
			continue;
		}
		int st=-1,en=-1;
		for(int j=0;j<t1.size();j++)
			if(t1[j]!=t2[j]){
				if(st==-1) st=j;
				en=j;
			}
		vector<int> id=mp[{get(th1,st,en),get(th2,st,en)}];
		int ans=0;
		for(int i=0;i<id.size();i++){
			int j=id[i],len=s1[j].size(),sst=st1[j];
			if(get(th1,st-sst,st-sst+len-1)==get(sh1[j],0,len-1)){
				assert(get(th2,st-sst,st-sst+len-1)==get(sh2[j],0,len-1));
				ans++;
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
