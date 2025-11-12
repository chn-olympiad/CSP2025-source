#include<bits/stdc++.h>
#include<string>
using namespace std;
string a[200005][2];
int rpc(string s1,string s2,int n){
	int ls=s1.size();
	int ans=0;
	for(int i=0;i<n;i++){
		int la0=a[i][0].size();
		for(int j=0;j<ls;j++){
			if(a[i][0]==s1.substr(j,la0)&&a[i][1]==s2.substr(j,la0)){
				if(s1.substr(0,j)==s2.substr(0,j)&&s1.substr(j+la0,ls-j-la0)==s2.substr(j+la0,ls-j-la0)){
					ans++;	
				}
			}
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=0;i<m;i++){
		string t1="",t2="";
		cin>>t1>>t2;
		int ans=rpc(t1,t2,n);
		cout<<ans<<endl;
	}
	return 0;
}
