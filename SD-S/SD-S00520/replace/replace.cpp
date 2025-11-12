#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<cstring>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define ll long long
#define ull usdigned long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int N=1e5+5;
ll read(){
	ll x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){w=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*w;
}
void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,q;
string s1[N],s2[N];
string qus1[N],qus2[N];
map<string,vector<string> > ma;
int main(){
	file("replace");
	ll ans=0;
	n=read();q=read();
	for (int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		ma[s1[i]].pb(s2[i]);
	}
	for (int i=1;i<=q;i++){
		cin>>qus1[i]>>qus2[i];
		string now;
		ans=0;
		for (int l=0;l<qus1[i].length();l++){
			for (int r=l;r<qus1[i].length();r++){
				now=qus1[i].substr(l,r-l+1);
				if(ma[now].size()!=0){
					for (int j=0;j<ma[now].size();j++){
						string ppp=ma[now][j];
						if(qus1[i].substr(0,l)+ppp+qus1[i].substr(r+1)==qus2[i]) ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
