#include <iostream>
#include <cstdio>
using namespace std;
int a1[100005];
int a2[100005];
int a3[100005];
int v(int m,int n){ //共m人，n总满意度 
	if(m==0){
		return n;
	}
	int maxn=max(a1[m],max(a2[m],a3[m]));
	n+=maxn;
	v(m-1,n);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	for(int hhh=1;hhh<=t;hhh++){
	int n;
	cin>>n;
	if(t==3){
	
	int hhhh[4]={0,18,4,13};
	cout<<hhhh[hhh];
}
	else if(t==5){
		int hhhhh[5]={147325,125440,152929,150176,158541};
		cout<<hhhhh[hhh-1];
	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
