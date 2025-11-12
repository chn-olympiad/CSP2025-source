#include<bits/stdc++.h>

using namespace std;

int main(){
//刘家豪 SN-00096 延安市新区第三中学
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,r=1,c=1,m,a1,a2;
	cin>>n>>m>>a1;
	for(long long i=1;i<=n*m-1;i++){
		cin>>a2;
		if(r%2!=0){
			if(a2>a1 && c!=m)
				c++;
			else if(a2>a1 && c==m)
				r++;
		}
		else if(r%2==0){
			if(a2>a1 && c!=1)
				c--;
			else if(a2>a1 && c==1){
				r++;
			}	 
		}	
	} 
	cout<<r<<' '<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

