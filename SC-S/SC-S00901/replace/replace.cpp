#include<bits/stdc++.h>
using namespace std;
struct node{
	string a,b;
};
vector<string>g;
int n,q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	node s[n];
	for(int i=0;i<n;++i) cin>>s[i].a>>s[i].b;
	while(q--){
		string a,b;
		int t=0;
		cin>>a>>b;
		if(a.size()!=b.size()) cout<<"0\n";
		else{
			int t=0;
			for(int i=0;i<n;++i){
				if(s[i].a==a&&s[i].b==b) t++;
				int l=s[i].a.size();
				for(int j=l;j<a.size();++j){
					string v="";
					for(int k=j-l;k<j;++k) v+=a[k];
					if(v==s[i].a){
						string u=a;
						for(int k=j-l;k<j;++k) u[k]=s[i].b[k-j+l];
						if(u==b) t++;
					}
				}
			}
			cout<<t<<endl;
		}
	}
	return 0;
}