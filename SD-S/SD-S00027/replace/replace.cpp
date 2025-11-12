#include <bits/stdc++.h>

using namespace std;

int n,q,l[200050][3];

string s[200050][3];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		l[i][1]=s[i][1].size();
		l[i][2]=s[i][2].size();
	}
	while(q--){
		string a,b;
		int na,nb,bt=0,z=0,bt1=0;
		cin>>a>>b;
		na=a.size();
		nb=b.size();
		if(na!=nb){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<na;i++){
			if(a[i]!=b[i]){
				if(!bt) bt=i;
				bt1=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(na>=l[i][1]){
					int k=0;
					for(int j=0;j<=bt;j++){
						if(a[j]!=s[i][1][k]){
							k=0;
							continue;
						} 
						if(s[i][2][k]!=b[j]){
							k=0;
							continue;
						}
						if(j+l[i][1]-k-1<bt||j+l[i][1]-k-1<bt1){
							k=0;
							continue;
						} 
						k++;
					}
					if(k){
						for(int j=bt+1;j<=bt1;j++){
							if(a[j]!=s[i][1][k]){
								k=0;
								break;
							} 
							if(s[i][2][k]!=b[j]){
								k=0;
								break;
							} 
							k++;
						}			
						if(k){
							for(k=k+1;k<=l[i][1];k++){
								if(s[i][1][k]!=s[i][2][k]){
									z--;
									break;
								}
							}
							z++;
						}		
					}
				

			}
		}
		cout<<z<<"\n";
	}
	return 0;
}

