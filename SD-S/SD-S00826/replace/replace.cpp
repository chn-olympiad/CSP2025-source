#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,ans;
string st1,st2,k,l;
struct node{
	string s1,s2;
}a[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	while(q--){
		ans=0;
		cin>>st1>>st2;
		if(st1.size()!=st2.size()){
			cout<<0<<'\n';
			continue;
		}
		while(st1[0]==st2[0]) {
			st1.erase(0,1);
			st2.erase(0,1);
		}
		while(st1[st1.size()-1]==st2[st2.size()-1]) {
			st1.erase(st1.size()-1,1);
			st2.erase(st2.size()-1,1);
		}
		for(int i=1;i<=n;i++){
			if(a[i].s1.find(st1)<=a[i].s1.size()&&a[i].s2.find(st2)<=a[i].s2.size()){
				k=a[i].s1,l=a[i].s2;
				k.replace(a[i].s1.find(st1),st1.size(),st2);
				if(k==l){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
