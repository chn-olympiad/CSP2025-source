#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN=2e5+10,MAXM=5e6+10,INF=5e6;

int N,Q,cnt,len[MAXN];
string s[MAXN],str[MAXN],A,B;
bool taskB=true;

void solve1(){ //最原始的暴力O(N^2QL)
	for(int i=1;i<=N;++i){
		cin>>s[i]>>str[i];
		len[i]=s[i].size();
	}
	while(Q--){
		cin>>A>>B;cnt=0;
		int Len=A.size(),l=INF,r=0;
		for(int i=0;i<Len;++i){
			if(A[i]!=B[i]) l=min(l,i),r=max(r,i);
		}
		for(int k=1;k<=N;++k){ //暴力匹配每一个字符串
			if(r-l+1>len[k]||len[k]>Len) continue; //没有办法,补不完
			bool f=false;
			for(int i=max(0,r-len[k]+1);i<=min(l,Len-len[k]+1);++i){ //枚举替换的开头
				for(int j=0;j<len[k];++j){ //匹配每一个字母
					if(s[k][j]!=A[i+j]||str[k][j]!=B[i+j]) break;
					if(j==len[k]-1) f=true;
				}
				if(f) break;
			}
			if(f) ++cnt;
		}
		cout<<cnt<<'\n';
	}
}

int pos[MAXN];
vector<int> ad[MAXM<<1];
void solveB(){
	for(int k=1;k<=N;++k){
		int l=0,r=0;
		for(int i=0;i<len[k];++i){
			if(s[k][i]=='b') l=i;
			if(str[k][i]=='b') r=i;
		}
		pos[k]=l;ad[r-l+INF].push_back(k);
	}
	while(Q--){
		cin>>A>>B;
		int l=0,r=0,Len=A.size(),ans=0;
		for(int i=0;i<Len;++i){
			if(A[i]=='b') l=i;
			if(B[i]=='b') r=i;
		}
		for(int k:ad[r-l+INF]){
			if(l>=pos[k]&&Len-l>=len[k]-pos[k]) ++ans;
		}
		cout<<ans<<'\n';
	}
}

void solve(){
	while(Q--){
		cin>>A>>B;cnt=0;
		int Len=A.size(),l=INF,r=0;
		for(int i=0;i<Len;++i){
			if(A[i]!=B[i]) l=min(l,i),r=max(r,i);
		}
		for(int k=1;k<=N;++k){ //暴力匹配每一个字符串
			if(r-l+1>len[k]||len[k]>Len) continue; //没有办法,补不完
			bool f=false;
			for(int i=max(0,r-len[k]+1);i<=min(l,Len-len[k]+1);++i){ //枚举替换的开头
				for(int j=0;j<len[k];++j){ //匹配每一个字母
					if(s[k][j]!=A[i+j]||str[k][j]!=B[i+j]) break;
					if(j==len[k]-1) f=true;
				}
				if(f) break;
			}
			if(f) ++cnt;
		}
		cout<<cnt<<'\n';
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>N>>Q;
	if(N<=100&&Q<=100){solve1();return 0;}
	for(int i=1;i<=N;++i){
		cin>>s[i]>>str[i];len[i]=s[i].size();
		if(!taskB) continue;
		int cnt1=0,cnt2=0;
		for(int k=0;k<len[i];++k){
			if(s[i][k]>'b'||str[i][k]>'b'){taskB=false;break;}
			if(s[i][k]=='b') ++cnt1;
			if(str[i][k]=='b') ++cnt2;
			if(cnt1>1||cnt2>1){taskB=false;break;}
		}
		if(cnt1!=1||cnt2!=1) taskB=false;
	}
	if(taskB){solveB();return 0;}
	solve();
	return 0;
}