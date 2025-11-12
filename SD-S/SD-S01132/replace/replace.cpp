#include<bits/stdc++.h> 
using namespace std;
struct Node{
	string a,b;
}c[10010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>c[i].a>>c[i].b;
	} 
	
	for(int i=1;i<=n;i++){
		int ans=0;
		string x,y;
		cin>>x>>y;
		for(int j=1;j<=m;i++){
			if(x.find(c[j].a)!=x.size()){
				int kkk=x.find(c[j].a);
				string kk="";
				for(int k=0;k<kkk;k++){
					kk.push_back(x[k]);
				}
				for(int k=0;k<c[j].a.size();k++){
					kk.push_back(c[j].a[k]);
				}
				for(int k=kkk+c[k].a.size();k<x.size();k++){
					kk.push_back(x[k]);
				}
				if(kk==y){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
