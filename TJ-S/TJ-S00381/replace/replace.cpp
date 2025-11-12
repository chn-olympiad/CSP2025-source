#include<bits/stdc++.h>
using namespace std;
int n,q,l,ll,ans;
pair<string,string> a[100005];
string s,s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	cout<<1<<endl;
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>s>>s1;
		l=s.size();
		if(l==1){
			for(int i=1;i<=n;i++){
				if(s==a[i].first){
					if(a[i].second==s1){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++){
				ll=a[i].first.size();
				for(int x=0;x<l-ll+1;x++){
					if(s.substr(x,ll)==a[i].first){
						if(s.substr(0,x)+a[i].second+s.substr(x+ll,l-x-ll)==s1){
							ans++;
						}
					}
				}
			}
			
			cout<<ans<<endl;
		}

	}
	return 0;
}
