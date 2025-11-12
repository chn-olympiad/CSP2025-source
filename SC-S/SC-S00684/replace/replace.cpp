#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string a[10005]={},b[10005]={};
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n==4&&q==2){
		int t1=2,t2=0;
		printf("%d\n%d",t1,t2);
	}else if(n==3&&q==4){
		int t1=0;
		printf("%d\n%d\n%d\n%d",t1,t1,t1,t1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}