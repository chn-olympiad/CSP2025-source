#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,t,cnt=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0&&j==0){
				cin>>r;
			}else{
				cin>>t;
				if(t>r) cnt++;
			}
		}
	}
	int n0,m0;
	n0=cnt/n;
	cnt-=n0*n;
	if(n0%2==0){
		m0=cnt+1;
	}else{
		m0=m-cnt;
	}
	n0++;
	cout<<n0<<" "<<m0;
	fclose(stdin); 
	fclose(stdout); 
	return 0;
}
