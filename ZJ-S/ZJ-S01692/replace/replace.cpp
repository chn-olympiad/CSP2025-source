#include<bits/stdc++.h>
using namespace std;
int n,t,cnt=0;
string s1[200005],s2[100005],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(t--){
		cnt=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			for(int j=0;j<t1.size();j++){
				if(t1[j]==s1[i][0]){
					bool f=true;
					for(int k=1;k<s1[i].size();k++){
						if(t1[j+k]!=s1[i][k]){
							f=false;
							
							break;
						}
					}
					if(f){
						string st=t1;
						for(int k=0;k<s1[i].size();k++){
							st[j+k]=s2[i][k];
						}
						if(st==t2){
							cnt++;
						}
						j=j+s1[i].size()-1;
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
