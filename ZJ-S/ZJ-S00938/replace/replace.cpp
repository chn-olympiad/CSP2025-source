#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
const int N=2e5+5;
int n,m;
string s[N][2];
bool check(string t1,string t2,int x){
	int len=t1.size();
	int xlen=s[x][0].size();
	for(int i=0;i+xlen-1<len;++i){
		if(t1.substr(i,xlen)!=s[x][0])continue;
		string cnt=t1.substr(0,i)+s[x][1]+t1.substr(i+xlen,len-(i+xlen-1)-1);
		if(cnt==t2)return true;
	}
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=m;++i){
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size();
		if(len!=t2.size())cout<<0<<endl;
		else{
			int res=0;
			for(int j=1;j<=n;++j){
				if(check(t1,t2,j))++res;
			}
			cout<<res<<endl;
		}
	}
	return 0;
}