//SN-J00397 张秦硕 高新一中沣东中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,nm,a[1005],f,r=1,x,y;
    cin>>n>>m;
    nm=n*m;
    cin>>f;
    for(int i=1;i<nm;i++){
        cin>>a[i];
        }
    for(int i=1;i<nm;i++){
       if(f<a[i])
       r++;
    }
    x=r/n+1;
    if(r%n==0){
    x=x-1;
    }  
    if(x%2==0){
    if(r%n==0){
       y=1;
    }else{
    y=n-r%n+1;
}
    }else{
    if(r%n==0){
    y=n;
    }else{
    y=r%n;
    }
    }    
    cout<<x<<" "<<y;
    fclose(stdin);
	fclose(stdout);
    return 0;
}

