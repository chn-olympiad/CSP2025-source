#include<bits/stdc++.h>
using namespace std;
int a[100010]={0},b[100010]={0},c[100010]={0},max1[100010]={0};
int main(){
  //freopen("club.in","r",stdin);
  //freopen("club.out","w",stdin);
  int t,n;
  cin>>t;
  for(int i=1;i<=t;i++){
  	cin>>n;
	for(int j=1;j<=n;j++){
	  cin>>a[j]>>b[j]>>c[j];
	  max1[j]=max(a[j],b[j]);
	  max1[j]=max(c[j],max1[j]);
	}
	for(int j=1;j<=n;j++){
	  
	}
  }
return 0;
}
