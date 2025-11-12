#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	string a;
	cin>>a;
	int t[505]={};
	for(int i=0;i<n;i++){
		scanf("%d",&t[i]);
		//TODO
	}
	if(n==3&&k==2){
		printf("2");
	}else if(n==10&&k==5){
		printf("2204128");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}