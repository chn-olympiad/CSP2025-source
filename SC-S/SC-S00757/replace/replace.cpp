#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
struct node{
	string a,b;
}s[N];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i].a>>s[i].b;
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		int len1=t1.size(),len2=t2.size();
		if(len1!=len2)continue;
		for(int i=1;i<=n;i++){
			int fl=1;
			int	lena=s[i].a.size(),lenb=s[i].b.size();
			if(lena==lenb)continue;
			int t1_find=t1.find(s[i].a),t2_find=t2.find(s[i].b);
			if(t1_find==t2_find&&t1_find!=-1){
				for(int j=0;j<len1;j++){
					if(j>=t1_find&&j<=t1_find+lena-1)continue;
					if(t1[j]!=t2[j])fl=0;
				}
			}
			if(fl)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}