#include<bits/stdc++.h>
using namespace std;
int n,m,c=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    int b[n*m+1];
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
        c=b[1];
    }
    sort(b+1,b+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(c==b[i]){
            if(i==m){
            	cout<<"1 ";
			}else{
				cout<<i/m+1<<" ";
			}
        	if((i/m+1)%2==0){
        		i=i%n;
            	if(i==0){
            		i=n;
				}
				cout<<n-i+1;
        	}else{
        		i=i%n;
        	    if(i==0){
        	    	i=n;
				}
				cout<<i;
        	}
        	break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
