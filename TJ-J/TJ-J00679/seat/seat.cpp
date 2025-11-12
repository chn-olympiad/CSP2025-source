#include<bits/stdc++.h>
using namespace std;
long long n,m,l,j=1,u=1,st,nst,fu,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	long long k=n*m;
	long long a[k+9]={};
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+2+n);
	for(int i=k;i>0;i--){
		if(a[i]==l){
			st=i;
			break;
		}
	}
	nst=k-st;
	if(nst<n){
		cout<<1<<' '<<nst;
		return 0;
    }else{
    	while(nst){
    		if(j%2){
    			u=1;
    			while(u<n){
    				u++;
    				nst--;
    				if(u==n){
    					j++;
					    nst--;
					    break;
				    }
				}
				
			}else{
				u=n;
				while(u>=0){
					u--;
					nst--;
				}
				if(u==0){
					j++;
					nst--;
				}
			}
		}
	}
	cout<<j<<' '<<u;
	return 0;
}
