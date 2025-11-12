#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define pb push_back
#define pii pair<int,int> 
#define p_q priority_queue
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
namespace cute_fzj_kuai_ruarua{
	int n,q;
	map<pair<ull,ull>,ve<int> >mp;
	map<ull,int>_,__;
	struct node{
		ull H1,H2,H3,H4;
	}a[200005];
	int cnt=0;
	void main(){
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			string s1,s2;
			cin>>s1>>s2;
			ll H1=0,H2=0;
			int l=0,r=s1.size()-1;
			if(s1==s2){
				continue;
			}
			int len=s1.size();
			while(l<len){
				if(s1[l]==s2[l]) l++;
				else break;
			}
			while(r>=0){
				if(s1[r]==s2[r]) r--;
				else break;
			}
			for(int i=l;i<=r;i++){
				H1=H1*131+s1[i];
				H2=H2*131+s2[i];
			}
			ull H3=0,H4=0;
			for(int i=l-1;i>=0;i--){
				H3=H3*131+s1[i];
			}
			for(int i=r+1;i<len;i++){
				H4=H4*131+s1[i];
			}
			cnt++;
			a[cnt].H1=H1;
			a[cnt].H2=H2;
			a[cnt].H3=H3;
			a[cnt].H4=H4;
			mp[mk(H1,H2)].pb(cnt);
		}
		while(q--){
			string t1,t2;
			cin>>t1>>t2;
			if(t1.size()!=t2.size()){
				cout<<0<<endl;
				continue;
			}
			ull H1=0,H2=0;
			int l=0,r=t1.size()-1;
			int len=t1.size();
			while(l<len){
				if(t1[l]==t2[l]) l++;
				else break;
			}
			while(r>=0){
				if(t1[r]==t2[r]) r--;
				else break;
			}
			for(int i=l;i<=r;i++){
				H1=H1*131+t1[i];
				H2=H2*131+t2[i];
			}
			_.clear();
			__.clear();
			ull H3=0,H4=0;
			_[0]=1;
			for(int i=l-1;i>=0;i--){
				H3=H3*131+t1[i];
				_[H3]=1;
			} 
			__[0]=1;
			for(int i=r+1;i<len;i++){
				H4=H4*131+t1[i];
				__[H4]=1;
			}
			int ans=0;
			for(auto i:mp[mk(H1,H2)]){
				if(H1==a[i].H1&&H2==a[i].H2&&_.count(a[i].H3)&&__.count(a[i].H4)){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
}
using namespace cute_fzj_kuai_ruarua;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cute_fzj_kuai_ruarua::main();
	return 0;
}
