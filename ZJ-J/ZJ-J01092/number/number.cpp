#include<bits/stdc++.h>
using namespace std;
int t[15];
char s[1000005];
int cnt=0;
int n; 
int main()
{
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
    scanf("%s",&s);
    while(isdigit(s[n]) || (s[n]>='a' && s[n]<='z')){
    	n++;
	}
    for(int i=0;i<n;i++){
    	if(isdigit(s[i]))t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
