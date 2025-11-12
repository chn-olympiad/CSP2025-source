#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q,ans;
struct node{
	string s1;
	string s2;
	int l;
	int r;
}s[maxn];
int len[maxn];
string t1,t2;
int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
		len[i]=s[i].s1.size();
		for(int j=0;j<len[i];j++){
			if(s[i].s1[j]!=s[i].s2[j]){
				s[i].l=j;
				break;
			}
		}
		for(int j=len[i]-1;j>=0;j--){
			if(s[i].s1[j]!=s[i].s2[j]){
				s[i].r=j;
				break;
			}
		}
	}
	while(q--){
		cin>>t1>>t2;
		int l=t1.size();
		int u,v;
		ans=0;
		for(int i=0;i<l;i++){
			if(t1[i]!=t2[i]){
				u=i;
				break;
			}
		}
		for(int i=l-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				v=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i].r-s[i].l+1==v-u+1&&s[i].l<=u&&len[i]<=l){
				int flag=1;
				for(int j=0;j<len[i];j++){
					if(s[i].s1[j]!=t1[u-s[i].l+j]){
						flag=0;
						break;
					}
					if(s[i].s2[j]!=t2[v-s[i].r+j]){
						flag=0;
						break;
					}
				}
				ans+=flag;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

