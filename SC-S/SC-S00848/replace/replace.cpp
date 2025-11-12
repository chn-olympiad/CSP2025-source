#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
int ans=0;
struct p{
	string s1,s2;
	int s1b,s2b;
}a[200010]; 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		for(int j=0;j<a[i].s1.size();j++){
			if(a[i].s1[j]=='b'){
				a[i].s1b=j+1;
				break;
			}
		}
		for(int j=0;j<a[i].s2.size();j++){
			if(a[i].s2[j]=='b'){
				a[i].s2b=j+1;
				break;
			}
		}
	}
	for(int Q=1;Q<=q;Q++){
		string t1,t2;
		cin>>t1>>t2;
		int t1b,t2b;
		for(int i=0;i<t1.size();i++){
			if(t1[i]=='b'){
				t1b=i+1;
				break;
			}
		}
		for(int i=0;i<t2.size();i++){
			if(t2[i]=='b'){
				t2b=i+1;
				break;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(t1b-t2b==a[i].s1b-a[i].s2b&&t1b>=a[i].s1b&&t1.size()-t1b>=a[i].s1.size()-a[i].s1b){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 