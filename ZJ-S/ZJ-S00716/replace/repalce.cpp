#include<bits/stdc++.h>
using namespace std;

int n,q;

string sc[200005][2];

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sc[i][0]>>sc[i][2];
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int ans=0;
		for(int i=0,e=s1.size();i<e;i++){
			for(int j=e-1;j>=i;j--){
				string d1="",d2="";
				for(int k=i;k<=j;k++){
					d1+=s1[k];
					d2+=s2[k];
				}
				for(int k=1;k<=n;k++){
					if(d1==sc[k][0]&&d2==sc[k][1]){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
