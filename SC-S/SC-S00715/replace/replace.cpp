#include<bits/stdc++.h>
using namespace std;
int n,q,c;
string a[200005],b[200005],x,y,z;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while (q--){
		c=0;
		cin>>x>>y;
		for (int i=1;i<=n;i++){
			if (x.size()<a[i].size()){
				break;
			}
			for (int j=0;j<=x.size()-a[i].size();j++){
				int f=1;
				z=x;
				for (int k=0;k<a[i].size();k++){
					if (x[j+k]==a[i][k] && y[j+k]==b[i][k]){
						z[j+k]=y[j+k];						
					}
					else{
						f=0;
						break;
					}
				}
				if (f){
					for (int k=0;k<x.size();k++){
						if (z[k]==y[k]){						
						}
						else{
							f=0;
							break;
						}
					}
					if (f){
						c++;
					}										
				}		
			}		
		}
		cout<<c<<endl;
	}
} 