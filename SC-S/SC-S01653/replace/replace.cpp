#include<bits/stdc++.h>
using namespace std;
struct rep{
	string a,b;
	int l,r;
}r[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans[200005];
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>r[i].a>>r[i].b;
		for(int j=0;j<r[i].a.size();j++){
			if(r[i].a[j]!=r[i].b[j]&&!r[i].l)r[i].l=j+1;
			else if(r[i].a[j]==r[i].b[j]&&r[i].l)r[i].r=j;
		}
	}
	string s1,s2;
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>s1>>s2;
		for(int z=1;z<=n;z++){
			int cnt=r[z].l-1,ml,mr;
			bool q=0;
			for(int j=0;j<s1.size();j++){
				if(s1[j]==r[z].a[cnt]&&s2[j]==r[z].b[cnt])cnt++;
				if(cnt==r[z].r&&s1[j]==s2[j]){
					q=1;
					mr=j;
					ml=j-r[z].r+r[z].l-2;
				}
			}
			if(q){
				for(int j=ml;r[z].l-ml+j-2>=0;j--)if(s1[j]!=r[z].a[r[z].l-ml+j-2])q=0;
				for(int j=mr;j-r[z].r<r[z].a.size();j++)if(s1[j]!=r[z].a[j-r[z].r])q=0;
			}
			if(q)ans++;
		} 
		cout<<ans<<endl;
	}
	return 0; 
}