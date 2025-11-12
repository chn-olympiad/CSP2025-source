#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
string ss(string x,int a,int b){
	if(a+b>x.size())
		return "";
	string c="";
	for(int i=a;i<a+b;i++)
		c=c+x[i];
	return c;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=0;i<q;i++){
		string x,y;
		bool f=0;
		int ans=0;
		cin>>x>>y;
		for(int k=0;k<n;k++){
			f=0;
			if(x.size()<s[k][0].size()||y.size()<s[k][1].size())
				continue;
			for(int j=0;j<x.size()-s[k][0].size()+1;j++){
				if(x[j]!=s[k][0][0]||y[j]!=s[k][1][0])
					continue;
				if(ss(x,j,s[k][0].size())==s[k][0]&&ss(y,j,s[k][1].size())==s[k][1]){
					f=1;
					for(int z=0;z<j;z++)
						if(x[z]!=y[z])
							f=0;
					for(int z=j+s[k][0].size();z<x.size();z++)
						if(x[z]!=y[z-s[k][0].size()+s[k][1].size()])
							f=0;
				}
			}
			if(f){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
