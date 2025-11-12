#include<bits/stdc++.h>
using namespace std;
string gi[100000][5];
string qu[100000][5];
int c[1000];

int cha(string x,string y){
	int an=0;
	for(int i=0;i<x.size();i++){
		if(x[i]!=y[i]){
			an++;
		}
	}
	return an;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>gi[i][1];
		cin>>gi[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>qu[i][1];
		cin>>qu[i][2];
		c[i]=cha(qu[i][1],qu[i][2]);
	}
	for(int k=1;k<=q;k++){
		int ans=0;
		string oq=qu[k][1];
		for(int j=1;j<=n;j++){
			
			for(int t=0;t<qu[k][1].size()-gi[j][1].size()+1;t++){
				
				string e="";
				
				for(int v1=0;v1<gi[j][1].size();v1++){
					e+=oq[t+v1];
					
				}
				//cout<<e<<' ';
				
				if(e==gi[j][1]){
					string nq=oq;
					string h=gi[j][2];
					
					for(int v2=0;v2<gi[j][1].size();v2++){
						nq[t+v2]=h[v2];
					
					}
					//cout<<nq<<' ';
					
					if(cha(nq,qu[k][2])==0){
						
						oq=qu[k][1];
						ans++;
						
						
						break;
						}
				}
				
			}
			
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
