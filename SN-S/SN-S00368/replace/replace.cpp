//Li Ruisi SN-S00368 Xi'an Tieyi High School
#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mod (998244353)
#define int long long
using namespace std;
inline int read(){
	int n=0,s=1;
	char x=0;
	while((x=getchar())<'0'||x>'9')
		if(x=='-')
			s=-1;
	while(x>='0'&&x<='9'){
		n=(n*10)+(x^48);
		x=getchar();
	}
	return n*s;
}
void write(int n,char x=0){
	if(n<0){
		putchar('-');
		n=-n;
	}
	if(n>=10)write(n/10);
	putchar('0'+n%10);
	if(x)putchar(x);
}
const int p1=73,p2=137,m1=998244853,m2=1004535809;
struct Node{
	int a1,a2;
	Node(){a1=a2=0;}
	bool operator<(Node x)const{if(a1!=x.a1)return a1<x.a1;return a2<x.a2;}
	Node operator+(char x){
		int o=x-'`'+1;
		Node ans=*this;
		ans.a1=(a1*p1+o)%m1,ans.a2=(a2*p2+o)%m2;
		return ans;
	}
	Node& operator+=(char x){return *this=this->operator+(x);}
};
int ch[5000001][27],fa[5000001],siz[5000001],tot;
bool tag[5000001];
map<Node,int>root;
char s1[5000005],s2[5000005];
void add(int rt){
	for(int i=1;s1[i];i++){
		int g=s1[i]-'`';
		if(!ch[rt][g])ch[rt][g]=++tot;
		rt=ch[rt][g];
	}
	siz[rt]++;
}
void bfs(){
	queue<int>que;
	for(int i=1;i<=tot;i++)if(tag[i])
		for(int j=0;j<=26;j++)if(ch[i][j])fa[ch[i][j]]=i,que.push(ch[i][j]);else ch[i][j]=i;
	while(!que.empty()){
		int x=que.front();
		siz[x]+=siz[fa[x]];
		que.pop();
		for(int j=0;j<=26;j++)if(ch[x][j])fa[ch[x][j]]=ch[fa[x]][j],que.push(ch[x][j]);else ch[x][j]=ch[fa[x]][j];
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),aqx=read();
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		int l=0,r=0;
		for(int j=1;s1[j];j++)if(s1[j]!=s2[j]){
			if(!l)l=j;
			r=j;
		}
		if(!l)continue;
		Node has;
		for(int j=l;j<=r;j++)has+=s1[j],has+=s2[j],s1[j]=s2[j]='`';
		if(!root[has])root[has]=++tot,tag[tot]=1;
		add(root[has]);
	}
	bfs();
	while(aqx--){
		scanf("%s%s",s1+1,s2+1);
		int l=0,r=0;
		for(int j=1;s1[j];j++)if(s1[j]!=s2[j]){
			if(!l)l=j;
			r=j;
		}
		if(!l)continue;
		Node has;
		for(int j=l;j<=r;j++)has+=s1[j],has+=s2[j],s1[j]=s2[j]='`';
//		cout<<s1+1<<" "<<s2+1<<"\n";
		if(!root[has]){puts("0");continue;}
		int now=root[has];
		int ans=0;
		for(int j=1;s1[j];j++)now=ch[now][(int)(s1[j]-'`')],ans+=siz[now];
		write(ans,'\n');
	}
	return 0;
}

