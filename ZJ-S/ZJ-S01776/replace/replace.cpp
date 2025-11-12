#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
typedef long long ll;
using namespace std;
const int maxn=2e5+10;
const int maxl=5e6+10;
int n,q;
string s[maxn][2],dic[maxn][2];
/*int head[26][2];
int cnt[2]={0,0};
struct node{
	char ch='';
	int v[26]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	bool flag=0;
}dic[maxl][2];
int f(char ch){return ch-'a';}
void add(string s,int x){
	if(head[f(s[0])][x]=='-1')head[f(s[0])][x]=cnt[x]++;
	int nw=head[f(s[0])][x];
	for(int i=0;i<s.szie()-1;i++){
		dic[nw][x].ch=s[i];
		if(dic[nw][x].v[f(s[i])]==-1)dic[nw][x].v[f(s[i])]=cnt[x]++;
		nw=dic[nw][x].v[f(s[i])];
	}
	dic[nw][x].ch=s[s.size()-1];
	dic[nw][x].flag=1;
	return;
}*/
int ans;
int RP=INF;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	++RP;
	//memset(head,-1,sizeof(head));
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>dic[i][0]>>dic[i][1];
	}
	for(int i=1;i<=q;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++){
		ans=0;
		for(int j=1;j<=n;j++){
			int x=s[i][0].find(dic[j][0]);
			if(x!=-1){
				string ss=s[i][0].substr(0,x)+dic[j][1]+s[i][0].substr(x+dic[j][1].size(),s[i][0].size());
				if(ss==s[i][1])ans++;
			}
		}
		cout<<ans<<'\n';
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
*/
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/