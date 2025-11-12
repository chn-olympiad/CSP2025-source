#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Men;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

const int N=2500006;
//int vis[2500006];//是否是结尾 
vector<int> vis[2500006];
int tr[2500006][27];//记录在当前这个点， 接一个 'a' 的儿子在哪里 
int cnt=0;
int n,q;
string s1[200005],s2[200005];
//vector<int> hashs[200005];

void add(string s,int id){
	int nowat=0;
	for(auto v:s){
		int use=v-'a'+1;
		if(tr[nowat][use]){
			nowat=tr[nowat][use];
		}
		else{
			tr[nowat][use]=++cnt;
			nowat=tr[nowat][use];
		}
	}
	vis[nowat].push_back(id);
//	vis[nowat]=id;//是个结尾
	return; 
}
string t1,t2;
const int mod=998244353,base=131;
int hash1[N],hash2[N];
int hash3[N],hash4[N];
int ans;
int get1(int nowat){
	if(nowat>=t2.length()) return 0;
	return hash3[nowat];
//	int len=t1.length();
//	nowat--;
//	return (hash1[len]-(hash1[nowat]*pow1[len-nowat])%mod+mod)%mod;
}
int get2(int nowat){
	if(nowat>=t2.length()) return 0;
	return hash4[nowat];
//	int len=t2.length();
//	nowat--; 
//	return (hash2[len]-(hash2[nowat]*pow1[len-nowat])%mod+mod)%mod;
}


void check(int idx,int nowat){
	if(vis[nowat].empty()) return;
	for(auto ids:vis[nowat]){
//		int ids=vis[nowat];
	//	cout<<"IDX "<<idx<<" ids "<<ids<<" nowat "<<nowat<<endl; 
		string tt;
		bool flag=1;
		int len=s1[ids].length();
		
		if(hash1[idx-len]!=hash2[idx-len]||get1(idx+1)!=get2(idx+1)) continue;
		
//		for(int i=idx-len+1;i<t1.length();i++){
		for(int i=idx-len+1;i<=idx;i++){
			if(i>=idx-len+1&&i<=idx){
				if(s2[ids][i-idx+len-1]!=t2[i]){
	//				cout<<"SEFSEF!\n";
//					return false;
					flag=0;
					break;
				}
			}
//			else{
//				if(t1[i]!=t2[i]){
//	//				cout<<"MATCHING "<<i<<endl;
////					return false;
//					flag=0;
//					break;
//				}
//			}
		}
		if(flag) ans++;
	} 
	return;
}
bool Mbe;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace3.in","r",stdin);
//	freopen("test.ans","w",stdout);
//	printf("%.8lfMB\n",(&Mbe-&Men)/1000000.0);
	
	n=read(),q=read();
	
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
//		hashs[i].resize(j+1);
//		hashs[i][0]=s2[i][0];
//		for(int j=1;j<s2[i].length();j++){
//			hashs[i][j]=(hashs[i][j-1]*base+s2[i][j])%mod;
//		} 
		add(s1[i],i);
	}
	while(q--){
		cin>>t1>>t2;
//		check(3,9);
//		if(check(3,9)) cout<<"YES\n";
//		else cout<<"NO\n";
		ans=0;
		if(t1.length()!=t2.length()){
			cout<<0<<endl;
			continue;
		}
		hash1[0]=t1[0];
		for(int i=1;i<t1.length();i++){
			hash1[i]=(hash1[i-1]*base+t1[i])%mod;
		}
		hash2[0]=t2[0];
		for(int i=1;i<t2.length();i++){
			hash2[i]=(hash2[i-1]*base+t2[i])%mod;
		}
		hash3[t1.length()-1]=t1[t1.length()-1];
		for(int i=t1.length()-2;i>=0;i--){
			hash3[i]=(hash3[i+1]*base+t1[i])%mod;
		}
		hash4[t2.length()-1]=t2[t2.length()-1];
		for(int i=t2.length()-2;i>=0;i--){
			hash4[i]=(hash4[i+1]*base+t2[i])%mod;
		}
		
		vector<int> save;save.clear(); 
		int idx=-1;
		for(auto v:t1){
			idx++;
			vector<int> nxt;nxt.clear();
			int use=v-'a'+1;
			for(auto v:save){
				if(tr[v][use]){
					int to=tr[v][use];
					check(idx,to);
//					if(check(idx,to)) ans++;
					nxt.push_back(to);
				}
			}
			int nowat=0;
			if(tr[nowat][use]){
				int to=tr[nowat][use];
				check(idx,to);
//				if(check(idx,to)) ans++;
				nxt.push_back(to);
			}
			save=nxt;
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
/*

对于特殊情况B
我们可以直接记录所有s
为把 'a' 向 前/后
挪动了几个 格子
对吧
对
怎么扩展

这题好像是个trie树
就是把s建成树
然后你对于每个询问给的t1
都遍历一遍
然后记录 目前可能的在trie树上的位置， 最多记录 len 个
然后每次都遍历下一个t1的位置
然后你直接看trie树上的每个点是否需要改变
然后有的点可能遇到结束点了
对于那些遇到结束点了的，再判断一下 s 能否替换（先暴力 待会改成哈希）就行了把 

但是这样对于 s和t全都是'a'这种情况就超时了
所以可以再加一个优化 就是 f[i] 表示当前在t1 的 点i，向前多少个是相同的
如果有f[i]那么可以直接加入新的点， 然后跳过所有相同的那些
这个优化待会加入 

有的可能没有
时间复杂度 O(lent) 


*/
