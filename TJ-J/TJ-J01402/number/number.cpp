#include<bits/stdc++.h>
using namespace std;

int s[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,sum=0,mx=10;
	for(int i=0;i<=n;i++){
		scanf("%d",&s[i]);
		if(s[i]==0){
			sum+=0;
		}
	}
		sum=0;
	for(int j=0;j<=n;j++){
		if(s[j-1]<s[j])
		sum+=s[j];
	}
		printf("%d",sum);
	
	return 0;
}
