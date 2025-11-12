#include<bits/stdc++.h>
using namespace std;
long long n,q;
string a,b;
struct node{
	string fs,ss;
};
vector<node> s[5000000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		int l,r;
		for(int j=0;j<a.size();j++){
			if(a[j]!=b[j]){
				l=j;
				break;
			}
		}
		for(int j=a.size()-1;j>=0;j--){
			if(a[j]!=b[j]){
				r=j;
				break;
			}
		}
		string x,y;
		for(int j=l;j<=r;j++){
			x+=a[j];
			y+=b[j];
		}
		//cout<<x<<' '<<y;
		s[x.size()].push_back(node{x,y});
	}
	string ft,st;
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>ft>>st;
		int l,r;
		for(int j=0;j<ft.size();j++){
			if(ft[j]!=st[j]){
				l=j;
				break;
			}
		}
		for(int j=ft.size()-1;j>=0;j--){
			if(ft[j]!=st[j]){
				r=j;
				break;
			}
		}
		string x="",y="";
		for(int j=l;j<=r;j++){
			x+=ft[j];
			y+=st[j];
		}
		int len=x.size();
		for(int j=0;j<s[len].size();j++){
			if(x==s[len][j].fs&&y==s[len][j].ss)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
