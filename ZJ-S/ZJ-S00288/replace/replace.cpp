#include<bits/stdc++.h>
using namespace std;
int a,b;
string n[200010],m[200010],x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>n[i]>>m[i];
	}
	while(b--){
		int s=0;
		cin>>x>>y;
		int xx=x.size(),yy=0;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				xx=min(xx,i);
				yy=max(yy,i);
			}
		}
		for(int i=0;i<a;i++){
			bool kyy=0;
			for(int j=max(0,int(yy-n[i].size()+1));j<=min(int(x.size())-int(n[i].size()),xx+int(n[i].size())-1);j++){
				bool ky=1;
				for(int k=0;k<n[i].size();k++){
					if(n[i][k]!=x[j+k] or m[i][k]!=y[j+k]){
						ky=0;
						break;
					}
				}
				if(ky){
					kyy=1;
					break;
				}
			}
			s+=kyy;
		}
		cout<<s<<endl;
	}
	return 0;
}
