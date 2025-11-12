#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int mx=2e5+10;
string a[mx],b[mx];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	string x,y;
	while(q--){
		int ans=0;
		cin>>x>>y;
		int l=0,r=0;
		for(int i=0;i<x.length();i++){
			if(x[i]!=y[i]){
				l=i;
				break;
			}
		}
		for(int i=x.length()-1;i>=0;i--){
			if(x[i]!=y[i]){
				r=i;
				break;
			}
		}
		string tmpx="",tmpy="";
		for(int i=l;i<=r;i++) tmpx.push_back(x[i]);
		for(int i=l;i<=r;i++) tmpy.push_back(y[i]);
		for(int i=1;i<=n;i++){
			int resx=a[i].find(tmpx),resy=b[i].find(tmpy);
			if(resx!=resy||resx==-1||resy==-1) continue;
			bool fl=true;
			for(int j=0;j<a[i].length();j++){
				if(a[i][j]!=x[l-resx+j]){
					fl=false;
					break;
				}
			}
			for(int j=0;j<b[i].length();j++){
				if(b[i][j]!=y[l-resy+j]){
					fl=false;
					break;
				}
			}
			if(fl) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
