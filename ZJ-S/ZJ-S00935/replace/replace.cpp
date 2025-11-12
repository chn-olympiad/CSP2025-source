#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
string s1[N],s2[N],t1,t2;
int n,q,ans,frt,bck,mv;
int front[N],back[N],move[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<s1[i].size();j++)
			if(s1[i][j]=='b'){
				front[i]=j,back[i]=s1[i].size()-j-1;
				break;
			} 
		for(int j=0;j<s2[i].size();j++)
			if(s2[i][j]=='b'){
				move[i]=front[i]-j;
				break;
			} 
	}
	while(q--){
		cin>>t1>>t2;
		ans=0;
		for(int j=0;j<t1.size();j++)
			if(t1[j]=='b'){
				frt=j,bck=t1.size()-j-1;
				break;
			} 
		for(int j=0;j<t2.size();j++)
			if(t2[j]=='b'){
				mv=frt-j;
				break;
			} 
		for(int i=1;i<=n;i++)
			if(move[i]==mv&&front[i]<=frt&&back[i]<=bck)
				ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
