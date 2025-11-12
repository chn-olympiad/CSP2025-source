#include<bits/stdc++.h>
using namespace std;
struct node{
	int pre,nex,res;
}s[200004];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;int flag;
		for(int j=0;j<a.size();j++){
			if(a[j]=='b'){
				s[i].pre=j,s[i].nex=a.size()-j;
			}
			if(b[j]=='b'){
				flag=j;
			}
		}
		s[i].res=flag-s[i].pre;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		string a,b;
		cin>>a>>b;
		int pre,nex,res,flag;
		for(int j=0;j<a.size();j++){
			if(a[j]=='b'){
				pre=j,nex=a.size()-j;
			}
			if(b[j]=='b'){
				flag=j;
			}
		}
		res=flag-pre;
		for(int j=1;j<=n;j++){
			if(s[j].pre<=pre&&s[j].nex<=nex&&s[j].res==res) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
