#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,k,ans;
	string x,y,z;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		cin>>x>>y;
		ans=0;
		for(int i=1;i<=n;i++){
			k=x.find(s1[i]);
			while(k!=-1){
				string a="",c="";
				for(int j=0;j<k;j++) a+=x[j];
				for(int j=k+s1[i].size();j<x.size();j++) c+=x[j];
				z=a+s2[i]+c;
				if(z==y) ans++;
				k=x.find(s1[i],k+s1[i].size());
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}