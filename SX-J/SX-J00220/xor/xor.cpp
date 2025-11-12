#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","r",stdout);
    int n,k,cnt=0,sum=0;
    cin>>n>>k;
    bool flag=0;
    for(int i=1;i<=n;i++){
     cin>>a[i];
     if(a[i]==0){
       flag=1;
	   cnt++;
	 }else sum++;

	 if(a[i]==1 &&a[i]==a[i-1]) cnt++;
	}
    if(k==0&& !flag){
    	if(n<2) cout<<0;
		else cout<<n/2;
	}else if(k==0 && flag){
		cout<<cnt;
	}else if(k==1 && flag){
        cout<<sum;
	}
	return 0;
}