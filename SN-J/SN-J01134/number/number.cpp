// SN-J01134 雷曜玮 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int s,x,b[10],ans[100005],u=0; 
char a[100005]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	s=strlen(a);
	for(int i=0;i<=s;i++){
		x=a[i]-'0';
		if(x>=0&&x<=9) 	
			b[x]++;
	}
	for(int j=9;j>=0;j--)
		while(b[j]>=1){
			cout<<j;
			b[j]--;
		}
	return 0;
}
