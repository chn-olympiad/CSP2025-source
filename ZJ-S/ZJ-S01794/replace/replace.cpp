#include<bits/stdc++.h>
#define forUp(i,a,b) for(int i=(a);i<=(b);++i)
#define forUP(i,a,b) for(int i=(a);i<(b);++i)
constexpr int N=2e5+10;using namespace std;void solve();
int n,q;string s[N][2],t[N][2];
namespace solve1{
	bool check(){
		int L1=0,L2=0;
		forUp(i,1,n)L1+=s[i][0].length()+s[i][1].length();
		forUp(i,1,q)L2+=t[i][0].length()+t[i][1].length();
		return L1<=2000&&L2<=2000;
	}
	void solve(){
		forUp(i,1,q){
			if(t[i][0].length()!=t[i][1].length()){
				cout<<"0\n";
				continue;
			}
			int lent=t[i][0].length(),ans=0;
			forUp(j,1,n){
				int lens=s[j][0].length();
				if(lens>lent)continue;
				forUp(k,0,lent-lens){
					bool flag=true;
					forUP(pos,0,k)if(t[i][0][pos]!=t[i][1][pos]){flag=false;break;}
					if(flag)forUP(pos,k,k+lens)if(t[i][0][pos]!=s[j][0][pos-k]||t[i][1][pos]!=s[j][1][pos-k]){flag=false;break;}
					if(flag)forUP(pos,k+lens,lent)if(t[i][0][pos]!=t[i][1][pos]){flag=false;break;}
					if(flag){
						++ans;
						break;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
}//1,2,3,4,5
namespace solve2{
	bool check(string s){
		bool ab=true;int b=0,len=s.length();
		forUP(i,0,len)ab&=s[i]=='a'||s[i]=='b',b+=s[i]=='b';
		return ab&&b==1;
	}
	bool check(){
		forUp(i,1,n)if(!check(s[i][0])||!check(s[i][1]))return false;
		forUp(i,1,q)if(!check(t[i][0])||!check(t[i][1]))return false;
		return true;
	}
	array<int,2> calc(string s1,string s2){
		int len1=s1.length(),len2=s2.length(),pos1=0,pos2=0;
		forUP(i,0,len1)if(s1[i]=='b')pos1=i;
		forUP(i,0,len2)if(s2[i]=='b')pos2=i;
		return {pos1,pos2};
	}
	struct node{
		int opt,llen,rlen,id;
		friend operator<(const node &lhs,const node &rhs){return lhs.llen==rhs.llen?lhs.rlen==rhs.rlen?lhs.opt<rhs.opt:lhs.rlen<rhs.rlen:lhs.llen<rhs.llen;}
	};
	vector<node> arr[N<<1];
	struct fenwick{
		int c[N],tp,stk[N];
		fenwick(){tp=0;memset(c,0,sizeof(c));memset(stk,0,sizeof(stk));}
		void add(int pos){
			stk[++tp]=pos;
			for(;pos<=n;pos+=pos&-pos)++c[pos];
		}
		int ask(int pos){
			int ans=0;
			for(;pos;pos-=pos&-pos)ans+=c[pos];
			return ans;
		}
		void clear(){
			while(tp){
				int pos=stk[tp--];
				for(;pos<=n;pos+=pos&-pos)--c[pos];
			}
		}
	}BIT;
	int ans[N];
	void solve(){
		forUp(i,1,n){
			if(s[i][0]==s[i][1])continue;
			array<int,2> pos=calc(s[i][0],s[i][1]);int len=s[i][0].length();
			arr[pos[0]-pos[1]+N].push_back({0,min(pos[0],pos[1]),len-max(pos[0],pos[1]),i});
		}
		forUp(i,1,q){
			if(t[i][0].length()!=t[i][1].length())continue;
			array<int,2> pos=calc(t[i][0],t[i][1]);int len=t[i][0].length();
			arr[pos[0]-pos[1]+N].push_back({1,min(pos[0],pos[1]),len-max(pos[0],pos[1]),i});
		}
		forUP(i,0,N<<1){
			if(arr[i].empty())continue;
			sort(arr[i].begin(),arr[i].end());
			for(node nd:arr[i]){
				if(nd.opt==0)BIT.add(nd.rlen);
				else ans[nd.id]=BIT.ask(nd.rlen);
			}
			BIT.clear();
		}
		forUp(i,1,q)cout<<ans[i]<<'\n';
	}
}//6,9,10,15,16
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	forUp(i,1,n)cin>>s[i][0]>>s[i][1];
	forUp(i,1,q)cin>>t[i][0]>>t[i][1];
	if(solve1::check())solve1::solve();
	else if(solve2::check())solve2::solve();
	return 0;
}