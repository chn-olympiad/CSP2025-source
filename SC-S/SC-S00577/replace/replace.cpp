#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull base=211;
const int maxn=2e5;
int n,q,ans[maxn+5];
int LS[maxn+5],RS[maxn+5];ull preS[maxn+5];
int LT[maxn+5],RT[maxn+5];
string S[maxn+5][2],T[maxn+5][2];
int LCP(string&S,string&T){
	for(int i=0;i<S.size();i++)if(S[i]!=T[i])return i-1;
	return S.size();
}
int LCS(string&S,string&T){
	int ed=S.size()-1;
	for(int i=ed;i>=0;i--)if(S[i]!=T[i])return i+1;
	return S.size();
}
struct UPD{
	ull key1,key2;
	int id,opt;
}A[maxn*2+5];int tot;
int operator <(UPD A,UPD B){
	if(A.key1!=B.key1)return A.key1<B.key1;
	return A.key2<B.key2;
}
const int maxL=1.2e7;
int ch[maxL+5][26],rt,ed;
int head1[maxL+5],nxt1[maxn+5];
int head2[maxL+5],nxt2[maxn+5];
map <ull,int> Ans;
int query(ull key){
	auto it=Ans.find(key);
	if(it==Ans.end())return 0;
	return it->second;
}
void solve(int now){
	for(int i=head1[now];i;i=nxt1[i])++Ans[preS[i]];
	for(int i=head2[now];i;i=nxt2[i]){
		ull now=0;ans[i]+=query(now);
		for(int j=LT[i]-1;j>=0;j--){
			now=now*base+T[i][0][j];
			ans[i]+=query(now);
		}
	}
	for(int c=0;c<26;c++)if(ch[now][c])solve(ch[now][c]);
	for(int i=head1[now];i;i=nxt1[i])--Ans[preS[i]];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>S[i][0]>>S[i][1];
	for(int i=1;i<=q;i++)cin>>T[i][0]>>T[i][1];
	for(int i=1;i<=n;i++){
		LS[i]=LCP(S[i][0],S[i][1])+1;
		RS[i]=LCS(S[i][0],S[i][1])-1;
		if(LS[i]<=RS[i]){
			for(int j=LS[i]-1;j>=0;j--)preS[i]=preS[i]*base+S[i][0][j];
			ull res1=0,res2=0;
			for(int j=LS[i];j<=RS[i];j++)res1=res1*base+S[i][0][j],res2=res2*base+S[i][1][j];
			A[++tot]={res1,res2,i,1};
		}
	}
	for(int i=1;i<=q;i++)if(T[i][0].size()==T[i][1].size()){
		LT[i]=LCP(T[i][0],T[i][1])+1;
		RT[i]=LCS(T[i][0],T[i][1])-1;
		ull res1=0,res2=0;
		for(int j=LT[i];j<=RT[i];j++)res1=res1*base+T[i][0][j],res2=res2*base+T[i][1][j];
		A[++tot]={res1,res2,i,2};
	}
	sort(A+1,A+1+tot);
	for(int l=1;l<=tot;l++){
		int r=l;
		while(r+1<=tot&&A[r].key1==A[r+1].key1&&A[r].key2==A[r+1].key2)r++;
		rt=++ed;
		for(int j=l;j<=r;j++){
			int now=rt,id=A[j].id;
			if(A[j].opt==1){
				for(int k=RS[id]+1;k<S[id][0].size();k++){
					int&v=ch[now][S[id][0][k]-'a'];
					if(!v)v=++ed;
					now=v;
				}
				nxt1[id]=head1[now];head1[now]=id;
			}else{
				for(int k=RT[id]+1;k<T[id][0].size();k++){
					int&v=ch[now][T[id][0][k]-'a'];
					if(!v)v=++ed;
					now=v;
				}
				nxt2[id]=head2[now];head2[now]=id;
			}
		}
		solve(rt);Ans.clear();
		l=r;
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	return 0;
}
//考虑对于一个修改操作的对,找到修改区间,用哈希+map分类
//对每一类的后半部分建trie,那么修改对询问有贡献当且仅当为询问的祖先并且前缀相包含
//具体的
//先找出所有对的修改区间,按照修改区间分类,接下来只考虑一个类里的对子
//对于修改和询问,对[r+1,n]建trie,然后在trie上遍历,遇到修改就把[1,l-1]的哈希值加进去,遇到查询就把[i,l-1]的哈希值都查一遍
//总复杂度O(L1+L2+n log n)的,常熟有点大
//你家提高给我整这个玩意?
//不是,喵喵能去WC了?
//注意完全不修改的情况