#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,q,ans;
struct node{
	string s1,s2;
	int len;
}a[maxn];
bool cmp(node a,node b){
	return a.len>b.len;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		a[i].len=a[i].s1.size();
		a[i].s1=' '+a[i].s1;
		a[i].s2=' '+a[i].s2;
	}
	sort(a+1,a+n+1,cmp);
	while(q--){
		ans=0;
		string s,t;
		cin>>s>>t;
		int m=s.size();
		if(s.size()!=t.size()){
			cout<<0<<"\n";
			continue;
		}
		s=' '+s;
		t=' '+t;
		int st=0,en=0;
		for(int i=1;i<=m;i++){
			if(s[i]!=t[i]){
				if(!st){
					st=i;
				}
				en=i;
			}
		}
		int len=en-st+1;
		for(int i=1;i<=n;i++){
			if(a[i].len<len)break;
			for(int r=en;r<=m;r++){
				int l=r-a[i].len+1;
				if(l<1||l>st){
					continue;
				}
				string q="",p="";
				int ffffff=1;
				int now=1;
				for(int k=l;k<=r;k++){
					if(s[k]!=a[i].s1[now]||t[k]!=a[i].s2[now]){
						ffffff=0;
						break;
					}
					now++;
				}
				ans+=ffffff;
			}
		}
		cout<<ans<<"\n";
	}
}
