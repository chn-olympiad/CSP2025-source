#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
int n,q,ans[200005],vis[200005];
string s[200005],ss[200005],t[200005],tt[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i]>>tt[i];
	}
	for(int i=1;i<=q;i++){
		for(int j=0;j<t[i].size();j++){
			for(int k=1;k<=n;k++){
				int flag=0;
				for(int l=0;l<s[k].size();l++){
					if(s[k][l]!=t[i][j+l]||ss[k][l]!=tt[i][l+j]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					string temp=t[i];
					for(int l=0;l<s[k].size();l++){
						temp[j+l]=ss[k][l];
					}
					for(int l=0;l<t[i].size();l++){
						if(temp[l]!=tt[i][l]){
							ans[i]--;
							break;
						}
					}
					ans[i]++;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}

