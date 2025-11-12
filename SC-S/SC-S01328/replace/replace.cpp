#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[1010],b[1010];
map<string,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("repalce.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		mp[a[i]]=i;
		mp[b[i]]=i;
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		int l=0,r=x.size()-1,ans=0;
		while(x[l]==y[l])l++;
		while(x[r]==y[r])r--;
		for(int i=0;i<=l;i++){
			for(int j=r;j<x.size();j++){
				int len=j-i+1;
				if(mp[x.substr(i,len)]==mp[y.substr(i,len)]&&mp[y.substr()]!=0){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}