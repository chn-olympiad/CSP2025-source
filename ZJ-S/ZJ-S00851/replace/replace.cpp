#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005];
string s2[200005];
string t1,t2;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<0;
			continue;
		}
		int begin=1,end=t1.length();
		for(int i=0;i<=t1.length()-1;i++){
			if(t1[i]!=t2[i]){
				begin=i;
				break;
			}
		}
		for(int i=t1.length()-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				end=i;
				break;
			}
		}
		int ans=0;
		for(int i=0;i<=begin;i++){
			for(int j=end;j<=t1.length()-1;j++){
				for(int k=1;k<=n;k++){
					if(s1[k].length()==j-i+1){
						bool flag=true;
						for(int v=0;v<=j-i;v++){
							if(s1[k][v]!=t1[v+i]||s2[k][v]!=t2[v+i]){
								flag=false;
							}
						}
						if(flag){
							ans++;
						}
					}
					cout<<endl;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}