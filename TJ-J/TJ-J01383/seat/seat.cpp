#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    int a[105]={0};
    cin>>a[1];
    int r=a[1];
    for(int i=2;i<=m*n;i++){
        cin>>a[i];
    }
    int p=1;
    sort(a+1,a+m*n+1,cmp);
    for(int i=1;i<=n*m;i++){

        if(a[i]==r){
            p=i;
            break;
        }
    }
    int l;
    l=(p+n-1)/n;
    cout<<l<<" ";
    if(l%2==1){
    	if(p%n==0) cout<<n;
        else cout<<p%n;
    }else{
    	if(p%n==0) cout<<1;
        else cout<<n-p%n+1;
    }
    fclose(stdin);
	fclose(stdout);
	return 0;
}
