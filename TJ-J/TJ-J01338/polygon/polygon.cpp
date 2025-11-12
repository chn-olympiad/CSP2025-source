#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,m[5001],sum=0,ssum=0;
cin>>n;
for(int i=1;i<=n;i++){
	cin>>m[i];
}

if(n<3){
	cout<<0;
}
 
fclose(stdin);
fclose(stdout);
	return 0;
}
