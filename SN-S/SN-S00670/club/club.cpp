#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	int a[100010]={};
	int b[100010]={};
	int c[100010]={};
	int g[100030]={};
	cin>>n>>t;
	int l=1;
	int yi=0,er=0,san=0,num=0;
	while(t>0){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){

				num=a[i]+b[j]+c[j];
	
	}
}
	cout<<num<<endl;
		t--;
		num=0;
	}
	
	return 0;
}
