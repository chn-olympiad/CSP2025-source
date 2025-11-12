#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> p;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		p[s1]=s2;
	}
//	for(int ii=0;ii<120;ii++){
	while(q--){
		string a,b;
		cin>>a>>b;
		int i=0,j=int(a.size())-1;
		while(a[i]==b[i] && i<=j) i++;
		while(a[j]==b[j] && j>i) j--;
//		cout<<i<<' '<<j<<'\n';
		int ans=0;
		for(int ni=0;ni<=i;ni++){
			for(int k=int(a.size())-1;k>=j;k--){
//				cout<<a.substr(ni,k)<<' '<<p[a.substr(ni,k)]<<' '<<b.substr(ni,k)<<' '<<k<<'\n';
				if(p[a.substr(ni,k-ni+1)]==b.substr(ni,k-ni+1)){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
