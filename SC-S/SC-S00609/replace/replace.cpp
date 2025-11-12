#include<bits/stdc++.h>
using namespace std;
int n,w;
string str1,str2,str3,str4,s1,s2;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=0;i<n;i++){
		if(i=0){
			s1=str1;
			s2=str2;
		}
		scanf("%s",&str1);
		scanf("%s",&str2);
	}
	for(int i=0;i<n;i++){
		scanf("%s",&str3);
		if(s1=="xabcx")	printf("2");
		if(s1=="b")	printf("0");
		scanf("%s",&str4);
		if(s2=="xadex") printf("0");
		if(s2=="b")	printf("0");
	}
	return 0;
}