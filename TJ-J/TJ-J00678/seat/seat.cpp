#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int a1=a[1],j=0;
    sort(a+1,a+1+n*m,cmp);
    /*for(int i=1;i<=n*m;i++){
        cout<<a[i]<<" ";
    }*/
    for(int i=1;i<=n*m;i++){
        if(a[i]==a1){
            j=i;
            break;
        }
    }
    //cout<<endl<<j<<endl;
    int c,r;
    if(j%n==0){
    	c=j/n;
    	if(c%2==1) r=n;
    	else if(c%2==0) r=1;
	}else{
		c=j/n+1;
		if(c%2==1) r=j%n;
    	else if(c%2==0) r=n-j%n+1;
	}
    cout<<c<<' '<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}//#Shang4Shan3Ruo6Shui4
/*
2 2
99 100 97 98
*/
/*
2 2
98 99 100 97 
*/
/*
3 3
94 95 96 97 98 99 100 93 92
*/
