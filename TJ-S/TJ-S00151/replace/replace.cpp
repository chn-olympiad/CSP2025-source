#include<bits/stdc++.h>
using namespace std;
bool f;
int n,q,cnt;
string s[200100][3],x,z,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int qi=1;qi<=q;qi++){
		cin>>z>>y;
		cnt=0;
		for(int i=0;i<z.size();i++){
			for(int j=1;j<=n;j++){
				if(z[i]==s[j][1][1]){
					f=true;
					for(int k=1;k<s[j][1].size();k++){
						if(k+i>z.size()-1||z[i+k]!=s[j][1][k]){
							f=false;
						}
					}
					if(f){
						x=z;
						for(int k=0;k<s[j][1].size();k++){
							x[i+k]=s[j][1][k];
						}
					}
					if(y==x){
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
