#include<bits/stdc++.h>
using namespace std;
#define maxn 200022
#define mod 1000000007
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long ll;
void file(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
int n,q;
string s[maxn][2];
int len[maxn],st[maxn],ed[maxn];
ll dif[maxn];
unordered_map<ll,int> idx;
int cnt;
vector<int> id[maxn];
void differ(int id){
	len[id]=s[id][0].size();
	string &s1=s[id][0],&s2=s[id][1];
	st[id]=0,ed[id]=len[id]-1;
	while(st[id]<len[id]&&s1[st[id]]==s2[st[id]]){
		++st[id];
	}
	dif[id]=0;
	if(st[id]==len[id]){
		return ;
	}
	while(s1[ed[id]]==s2[ed[id]]){
		--ed[id];
	}
	for(int i=st[id];i<=ed[id];++i){
		dif[id]=(dif[id]*13131+s1[i]*26+s2[i])%mod;
	}
}
int main(){
	file();
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
		differ(i);
		if(dif[i]){
			if(idx[dif[i]]){
				id[idx[dif[i]]].push_back(i);
			}else{
				idx[dif[i]]=++cnt;
				id[cnt].push_back(i);
			}
		}
	}
	while(q--){
		cin>>s[n+1][0]>>s[n+1][1];
		if(s[n+1][0].size()!=s[n+1][1].size()){
			cout<<"0\n";
			continue;
		}
		differ(n+1);
		int tmp=idx[dif[n+1]];
		if(!tmp){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int now:id[tmp]){
			int flag=1,py=st[n+1]-st[now];
			for(int i=0;i<len[now];++i){
				if(s[now][0][i]!=s[n+1][0][i+py]||
				   s[now][1][i]!=s[n+1][1][i+py]){
				   	flag=0;
				   	break;
				}
			}
			ans+=flag;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

