#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
string sa[M][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>sa[i][1]>>sa[i][2];
	}
	while(k--){
		string q,p;
		int ans=0;
		cin>>q>>p;
		for(int i=0;i<n;i++){
			int len=sa[i][1].size();
			int j=q.find(sa[i][1]);
			if(j==-1) continue;
			else{
				string temp;
				if(j+len==int(q.size())) temp=q.substr(0,j)+sa[i][2];
				else temp=q.substr(0,j)+sa[i][2]+q.substr(j+len);
				if(temp==p){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
