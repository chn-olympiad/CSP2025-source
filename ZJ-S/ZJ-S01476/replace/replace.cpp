#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q,ans;
string s1[200010],s2[200010],t1,t2;
void dfs(string now);
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		for(int j=1;j<=n;j++){ 
			if(t1.find(s1[j])>=0&&t1.find(s1[j])<t1.size()){
				string x="",y=s2[j],z="";
				for(int k=0;k<t1.find(s1[j]);k++) x+=t1[k];
				for(int k=t1.find(s1[j])+s1[j].size();k<t1.size();k++) z+=t1[k];
				string news=x+y+z;
				if(news==t2) ans++;
			}
		}	
		cout<<ans<<endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}