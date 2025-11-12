#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5,M=5e6+5,K=15;

bool st;

int n,q;
string S[2][N];
string T[2][N];
struct node
{
	node* ch[26];
	vector<int> h,t;
	int val;
}pol[M];int cnt=0;
node* rt[2];
map<pair<int,int>,int> difn;int tot;
int ans[N];

namespace Hash
{
	const int N=5e6+5,MOD[2]={998244853,998244353},base[2]={73,57};
	
	int mul(int a,int b,int j){return 1ll*a*b%MOD[j];}
	int add(int a,int b,int j){return a+b>=MOD[j]?a+b-MOD[j]:a+b;}
	
	struct dududu
	{
		int siz;
		vector<int> h[2];
		
		void insert(string &s)
		{
			siz=s.size();
			for(int j=0;j<2;j++)
			{
				h[j].resize(siz);
				for(int i=0;i<siz;i++)
					if(i) h[j][i]=add(mul(h[j][i-1],base[j],j),s[i]-'a'+1,j);
					else h[j][i]=s[i]-'a'+1;
			}
//			cout<<s<<'\n';
			return ;
		}
		
		int all(){return h[0][siz-1];}
		
		void clear()
		{
			vector<int>().swap(h[0]);
			vector<int>().swap(h[1]);
			return ;
		}
	};
};

node* newpoint()
{
	++cnt;
	for(int i=0;i<26;i++) pol[cnt].ch[i]=nullptr;
	vector<int>().swap(pol[cnt].h);
	vector<int>().swap(pol[cnt].t);
	pol[cnt].val=0;
	return &pol[cnt];
}

void insertS(string &s,int id,node *rt)
{
	if(!rt) rt=newpoint();
	node *now=rt;
	for(int i=0;i<s.size();i++)
	{
		char k=s[i]-'a';
		if(now->ch[k]==nullptr)
			now->ch[k]=newpoint();
		now=now->ch[k];
	}
	now->h.push_back(id);
}

void insertT(string &s,int id,node *rt)
{
	if(!rt) rt=newpoint();
	node *now=rt;
	for(int i=0;i<s.size();i++)
	{
		char k=s[i]-'a';
		if(now->ch[k]==nullptr)
			now->ch[k]=newpoint();
		now=now->ch[k];
	}
	now->t.push_back(id);
}

void update(string &s,int id,node *rt,int d)
{
	if(!rt) rt=newpoint();
	node *now=rt;
	for(int i=0;i<s.size();i++)
	{
		char k=s[i]-'a';
		if(now->ch[k]==nullptr)
			now->ch[k]=newpoint();
		now=now->ch[k];
	}
	now->val+=d;
}

int query(string &s,int id,node *rt)
{
	if(!rt) rt=newpoint();
	node *now=rt;
	int sum=0;
	for(int i=0;i<s.size();i++)
	{
		char k=s[i]-'a';
		if(now->ch[k]==nullptr)
			now->ch[k]=newpoint();
		sum+=now->val;
		now=now->ch[k];
	}
	sum+=now->val;
	return sum;
}

void dfs(node* u)
{
	if(u==nullptr) return ;
	for(int p:u->h) update(S[1][p],p,rt[1],1);
	for(int p:u->t) ans[p]+=query(T[1][p],p,rt[1]);
	for(int i=0;i<26;i++)
		if(u->ch[i]) dfs(u->ch[i]);
	for(int p:u->h) update(S[1][p],p,rt[1],-1);
}

vector<int> Ins[N],Int[N];

void solveT(string *t,int id)
{
	int l=-1,r=-1;
	if(t[0].size()!=t[1].size()) return ;
	for(int i=0;i<t[0].size();i++)
		if(t[0][i]!=t[1][i])
		{
			if(l==-1) l=i;
			r=i;
		}
	string dif1,dif2;
	T[0][id]="",T[1][id]="";
	for(int i=l;i<=r;i++) dif1+=t[0][i],dif2+=t[1][i];
	for(int i=r+1;i<t[0].size();i++) T[1][id]+=t[0][i];
	for(int i=l-1;i>=0;i--) T[0][id]+=t[0][i];
	Hash::dududu f1,f2;
	f1.insert(dif1),f2.insert(dif2);
	int df1=f1.all(),df2=f2.all();
	if(!difn.count({df1,df2})) difn[{df1,df2}]=++tot;
	Int[difn[{df1,df2}]].push_back(id);
}

void solveS(string *t,int id)
{
	int l=-1,r=-1;
	if(t[0]==t[1]) return ;
	if(t[0].size()!=t[1].size()) return ;
	for(int i=0;i<t[0].size();i++)
		if(t[0][i]!=t[1][i])
		{
			if(l==-1) l=i;
			r=i;
		}
	string dif1,dif2;
	S[0][id]="",S[1][id]="";
	for(int i=l;i<=r;i++) dif1+=t[0][i],dif2+=t[1][i];
	for(int i=r+1;i<t[0].size();i++) S[1][id]+=t[0][i];
	for(int i=l-1;i>=0;i--) S[0][id]+=t[0][i];
	Hash::dududu f1,f2;
	f1.insert(dif1),f2.insert(dif2);
	int df1=f1.all(),df2=f2.all();
	if(!difn.count({df1,df2})) difn[{df1,df2}]=++tot;
	Ins[difn[{df1,df2}]].push_back(id);
}

void solve(int now)
{
	cnt=0,rt[0]=newpoint(),rt[1]=newpoint();
//	cout<<now<<":\n";
	bool flag=0;
	for(int p:Ins[now]) insertS(S[0][p],p,rt[0]);
	for(int p:Int[now]) insertT(T[0][p],p,rt[0]),flag|=p==105;
//	if(flag)
//	{
//		cerr<<T[0][105]<<"\n"<<T[1][105]<<'\n';
//		for(int p:Ins[now])
//			cerr<<S[0][p]<<"\n"<<S[1][p]<<'\n';
//	}
	dfs(rt[0]);
}

bool ed;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	cerr<<((&st)-(&ed))*(sizeof (bool))*1.00/1024.0/1024.0<<"MB\n";
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a[2];
		cin>>a[0]>>a[1];
		solveS(a,i);
	}
	for(int i=1;i<=q;i++)
	{
		string a[2];
		cin>>a[0]>>a[1];
		solveT(a,i);
//		if(i==105) cerr<<a[0]<<"\n"<<a[1]<<'\n';
//		if(i==105) cerr<<T[0][i]<<"\n"<<T[1][i]<<'\n';
	}
//	for(int i=1;i<=n;i++) cout<<S[0][i]<<" "<<S[1][i]<<'\n';
//	for(int i=1;i<=q;i++) cout<<T[0][i]<<" "<<T[1][i]<<'\n';
	for(int i=1;i<=tot;i++) solve(i);
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
}

