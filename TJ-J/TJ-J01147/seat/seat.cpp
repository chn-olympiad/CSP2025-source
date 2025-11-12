#include<bits/stdc++.h>

using namespace std;

int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int a[n*m+10],n1,m1,s;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    s=a[1];
    for(int i=m*n;i>=0;i--){
        for(int j=1;j<i;j++){
            if(a[i-1]<a[i])
                swap(a[i],a[i-1]);
        }
    }
    int h=0;
    for(int i=1;i<=n*m;i++){
    	if((i-1)%n==0)
        	h++;
        if(a[i]==s){
        	if(h%2==0)
        		cout<<h<<" "<<n-(i+1%n)+1;
        	else
            	cout<<h<<" "<<i%n;
        }

    }


return 0;
}
