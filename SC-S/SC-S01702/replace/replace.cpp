#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using LL=long long;
using VI=vector<int>;
const int MAXN=2e5+5;
string S[MAXN][2],T[MAXN][2];
int n,q;
void solve1(){
	map<array<string,2>,int> mp;
	REP(i,1,n)mp[{S[i][0],S[i][1]}]++;
	REP(i,1,q){
		if(T[i][0].size()!=T[i][1].size()){
			cout<<0<<"\n";
			continue;
		}
		int len=T[i][0].size(),ans=0;
		int st=len-1,ed=0;
		while(st>=0&&T[i][0][st]==T[i][1][st])st--;
		while(ed<len&&T[i][0][ed]==T[i][1][ed])ed++;
		//cout<<st<<" "<<ed<<"\n";
		FOR(j,0,len){
			string cnt0="",cnt1="";
			for(int k=j;k<len;k++){
				cnt0+=T[i][0][k],cnt1+=T[i][1][k];
				if(!(j<=ed&&k>=st))continue;
				ans+=mp[{cnt0,cnt1}];
			}
		}
		cout<<ans<<"\n";
	}
}
void solve2(){
	map<int,int> mp;
	REP(i,1,n)mp[S[i][0].find('b')-S[i][1].find('b')]++;
	REP(i,1,q)cout<<mp[T[i][0].find('b')-T[i][1].find('b')]<<"\n";
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int len=0;cin>>n>>q;
	REP(i,1,n)cin>>S[i][0]>>S[i][1];
	REP(i,1,q)cin>>T[i][0]>>T[i][1],len+=T[i][0].size(),len+=T[i][1].size();
	solve1();//25pts
	return 0;
}
