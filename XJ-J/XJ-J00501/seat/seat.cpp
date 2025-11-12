#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],v,ans=0,cnt=0;
int p=1,q=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    v=m*n;
    for(int i=1;i<=v;i++){
    	cin>>a[i];
    	
	}
	ans=a[1];
	sort(a+1,a+v+1);
	for(int i=1;i<=v;i++){
		if(ans==a[i])
		    cnt=i;	
	} 
	
	for(int i=1;i<=n*m-cnt;i++){
	    if(i%n==0||i%(2*n)==0&&p==n){
	    	q++;
		}else if(q%2==1){
			p++;
		}else{
			p--;
		}
	}  
	cout<<q<<" "<<p;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
