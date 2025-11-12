#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m],b;
    cin>>b;
    a[0]=b;
    for(int i=1;i<n*m;i++){
        cin>>a[i];
    }
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i]==b){
            cout<<i/n+1<<" ";
            if(i/n%2==0){
                cout<<i%n+1;
            }else{
                cout<<m-i%n;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

