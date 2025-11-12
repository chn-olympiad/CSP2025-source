#include<bits/stdc++.h>
using namespace std;
int s;
int pd(int x,int y){
    if(x==1 && y==1){
        cin>>s;
        cout<<1<<" "<<1;
        return 1;
        }
    return 0;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int x,y;
    cin>>x>>y;
    if(pd(x,y)){
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    int aaa=x*y;
    int a[aaa+1]={};
    for(int i=1;i<=x*y;i++){
        cin>>a[i];
    }
    int R=a[1];
        if(x==1 && y==2){
        if(a[1]<a[2]){
            cout<<1<<" "<<2;
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
        cout<<1<<" "<<1;
            fclose(stdin);
            fclose(stdout);
            return 0;
    }
    if(x==2 && y==1){
        if(a[1]<a[2]){
            cout<<2<<" "<<1;
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
        cout<<1<<" "<<1;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    int abc;
    for(int i=1;i<=aaa;i++){
        for(int j=1;j<=aaa;j++){
            if(a[i]>a[j]){
                abc=a[i];
                a[i]=a[j];
                a[j]=abc;
            }
        }
    }
    for(int i=1;i<=aaa;i++){
        if(R==a[i]){
            R=i;
            break;
        }
    }
    if(R==1){
        cout<<1<<" "<<1;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(x==2 && y==2){
        switch(R){
            case 1:cout<<1<<" "<<1;break;
            case 2:cout<<1<<" "<<2;break;
            case 3:cout<<2<<" "<<2;break;
            case 4:cout<<2<<" "<<1;break;
        }
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    int wz_1=-1,wz_2=-1;
    wz_1=(R/x);
    if((R/x)%2!=0){
        wz_2=y-(R%y)+1;
    }
    if((R/x)%2==0){
        wz_2=R%y;
    }
    cout<<wz_1+1<<" "<<wz_2;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
