/*
 | |
(OHO)
*/
#include<bits/stdc++.h>
using namespace std;
const int X=998244353;
int n,m;
int s[1000];
int c[1000];
int flag=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	char sh;
    	cin>>sh;
    	if(sh=='1') s[i]=1;
    	else s[i]=0;
    	if(s[i]!=1) flag=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(flag==1){
		long long ans=1;
		for(int i=2;i<=n;i++){
			ans=(ans%X)*(i%X);
		}
		cout<<ans;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
