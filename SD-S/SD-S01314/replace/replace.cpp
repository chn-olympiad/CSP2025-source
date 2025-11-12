#include<bits/stdc++.h>
using namespace std;
int n,m,len[200010];
string s1[200010],s2[200010],ss1,ss2;
int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
	}
	for(int i=1;i<=m;i++){
		cin>>ss1>>ss2;
		int x=ss1.size(),y=ss2.size(),l=0,r=0;
		if(x!=y){
			cout<<0<<"\n";
		}
		else{
			int h=0;
			for(int j=1;j<=x;j++){
				if(ss1[j-1]!=ss2[j-1]&&!l){
					l=j;
				}
				if(ss1[x-j]!=ss2[x-j]&&!r){
					r=x-j+1;
				}
				if(l&&r){
					break;
				}
			}
			for(int j=1;j<=n;j++){
				if(r-l+1<=len[j]){
					string sss,ssss;
					for(int k=0;k<=x-len[j]+1;k++){
						if(ss1[k]==s1[j][0]){
							int t=1;
							for(int o=1;o<len[j];o++){
								if(ss1[k+o]!=s1[j][o]){
									t=0;
								}
							}
							if(t){
								ssss=sss+s2[j];
								for(int o=k+len[j];o<x;o++){
									ssss=ssss+ss1[o];
								}
								if(ssss==ss2){
									h++;
								}
							}
						}
						sss=sss+ss1[k];
					}
				}
			}
			cout<<h<<"\n";
		}
	}
	return 0;
}
