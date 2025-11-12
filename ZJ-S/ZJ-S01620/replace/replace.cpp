#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
struct node{
	string x,y;
}a[100005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	for(int i=1;i<=q;i++){
		string xx,yy;
		cin>>xx>>yy;
		int st,ed;
		for(int j=1;j<=n;j++){
			string c=a[j].x;
			bool flag=true,vis=false;
			for(int ii=0;ii<xx.size();ii++){
				if(c[ii]==xx[ii]){
					for(int jj=ii;jj<=ii+c.size()-1;jj++){
						if(c[jj-ii]!=xx[jj]){
							if(!(vis&&flag)) flag=false;
						}
					}
					if(flag){
						vis=true;
						st=ii,ed=ii+c.size()-1;
					}
				} 
			}
			if(flag&&vis){
				string d="",e="";
				for(int ii=0;ii<=st;ii++) d+=xx[ii];
				for(int ii=ed;ii<xx.size();ii++) e+=xx[ii];
				xx=d+a[j].y;
				xx+=e;
				if(xx==yy) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}