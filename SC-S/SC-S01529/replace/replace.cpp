#include<bits/stdc++.h>
using namespace std;
int n,q,aa[200005],ab[200005],ba[200005],bb[200005];
string s,e;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>e;
		for(int _=0;_<s.size();_++){
			if(s[_]=='b'){
				aa[i]=_;
				ab[i]=s.size()-_-1;
			}
			else if(s[_]!='a'){
				while(q--)cout<<0<<"\n";
				return 0;
			}
		}
		for(int _=0;_<e.size();_++){
			if(e[_]=='b'){
				ba[i]=_;
				bb[i]=e.size()-_-1;
			}
			else if(e[_]!='a'){
				while(q--)cout<<"0\n";
				return 0; 
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		int a,b,x,y;
		for(int j=0;j<s.size();j++){
			if(s[j]=='b'){
				a=j;
				b=s.size()-a-1;
			}
			else if(s[j]!='a'){
				q=q-i+1;
				while(q--)cout<<"0\n";
				return 0; 
			}
		}
		for(int j=0;j<e.size();j++){
			if(e[j]=='b'){
				x=j;
				y=e.size()-x-1;
			}
			else if(e[j]!='a'){
				q=q-i+1;
				while(q--)cout<<"0\n";
				return 0; 
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(aa[i]<=a&&ab[i]<=b&&ba[i]<=x&&bb[i]<=y)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}