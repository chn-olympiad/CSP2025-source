#include<bits/stdc++.h>
using namespace std;
int n,k;
string a[200005],b[200005];
int q;
string s,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		k=0;
		for(int j=1;j<=n;j++){
			size_t id=s.find(a[j]);
			if(id<s.size()){
				string x,y,z,ans;
				for(int w=0;w<id-1;w++){
					x+=s[w];
				}
				y=b[j];
				for(int w=id+a[j].size();w<t.size();w++){
					z+=s[w];
				}
				ans=x+y+z;
				if(ans==t)k++;
			}
		}
		cout<<k;
	}
	return 0;
}
