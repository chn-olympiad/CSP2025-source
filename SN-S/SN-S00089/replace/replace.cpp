#include<bits/stdc++.h>
using namespace std;
int n,q,ans,len1;
string str[200005][2];
string rep[10000005];
string tt1,tt2;

void meiju(int num){
	for(int i=1;i<=n;i++){
		int len2=str[i][0].length();
		for(int i=0;i<=len1-len2;i++){
			if(tt1.substr(i,len2)==str[i][0]){
				rep[num++]=
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>str[i][0]>>str[i][1];
	while(q--){
		ans=0;
		cin>>tt1>>tt2;
		len1=tt1.length();
		for(int i=1;i<=n;i++){
			if(tt1==str[i][0]&&tt2==str[i][1]) ans++;
		}
		for
	}
}
