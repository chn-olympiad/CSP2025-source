#include<bits/stdc++.h>
using namespace std;
string s1[200010],s2[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>s1[i]>>s2[i]; 
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			//cout<<s1[i]<<endl;
			for(int j=0;j<t1.size();j++){
				string t=t1;
				if(j+s1[i].size()>t.size()){
					//cout<<j<<' '<<'B'<<endl;
					break;
				}
				int flag=1;
				for(int k=j;k<j+s1[i].size() && k<t.size();k++){
					if(t[k]!=s1[i][k-j]){
						//cout<<t[k]<<' '<<s1[i][k-j]<<' ';
						flag=0; 
						break;
					}
				}
				if(flag==0){
					//cout<<j<<' '<<'C'<<endl;
					continue;
				} 
				for(int k=j;k<j+s1[i].size() && k<t.size();k++){
					t[k]=s2[i][k-j];
				}
				if(t==t2) {
					ans++;
					//cout<<t<<' '<<t2<<' '<<j<<' '<<"Y"<<' '<<ans<<endl;
				}/*else{
					cout<<t<<' '<<t2<<' '<<j<<' '<<"N"<<endl;
				}*/
			}
		}
		cout<<ans<<endl;
		//cout<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/


