#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
struct node{
	string fr,to;
}a[200005];
bool check(string s,int t,string e){
	int l=0;
	string x;
	for(int i=0;i<=(int)s.size()-(int)a[t].fr.size();i++){
		char c=s[i];
		if(c==a[t].fr[l]){
			bool f=true;
			for(int j=i+1;j<i+(int)a[t].fr.size();j++){
				l++;
				if(s[j]!=a[t].fr[l]){
					f=false;
				}
			}
			if(f){
				string z;
				for(int j=i+(int)a[t].fr.size();j<(int)s.size();j++){
					z+=(char)s[j];
				}
				string res=x+a[t].to+z;
				if(res==e){
					return true;
				}
			}
			l=0;
		}
		x+=c;
	}
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].fr>>a[i].to;
	}
	while(q--){
		ans=0;
		string s,e;
		cin>>s>>e;
		for(int j=1;j<=n;j++){
			if(check(s,j,e)){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 