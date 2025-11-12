#include<bits/stdc++.h>
using namespace std;
int n,q;
string cinx,ciny;
vector<pair<int,int>>v[10000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int j=1;j<=n;j++){
		cin>>cinx>>ciny;
		int cnt,ans;
		for(int i=0;i<cinx.size();i++)
		    if(cinx[i]=='b')cnt=i;
		for(int i=0;i<ciny.size();i++)
		    if(ciny[i]=='b')ans=i;
		v[cnt-ans+5000000].push_back({cnt,ciny.size()-ans});
	}
	for(int j=1;j<=q;j++){
		cin>>cinx>>ciny;
		int cnt,ans,num=0;
		for(int i=0;i<cinx.size();i++)
		    if(cinx[i]=='b')cnt=i;
		for(int i=0;i<ciny.size();i++)
		    if(ciny[i]=='b')ans=i;
		for(auto i:v[cnt-ans+5000000])
		    if(i.first<=cnt&&i.second<=ciny.size()-ans)
		        num++;
		cout<<num<<endl;
    }
    return 0;
} 
