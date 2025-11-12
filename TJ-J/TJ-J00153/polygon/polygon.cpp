#include<bits/stdc++.h>
using namespace std;
long long a[111111]={0};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
        cin>>a[i];
	}
	if(n==3){
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
