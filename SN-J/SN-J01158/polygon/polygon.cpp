#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,a[1000]={0};
    cin>>n;
    if(n==3){
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0]+a[1]>a[2]){
    cout<<"1";
    }
    else
    {
    cout<<"0";
    }
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
