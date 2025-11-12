#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,mapp[15][15],gradee[114];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>gradee[i];
		if(gradee[i]>=gradee[0])c++;//c means number>=R
	}
	a=(c-1)/n+1;
	if(a%2!=0){
		b=c-(a-1)*n;
	}else{
		b=m-(c-(a-1)*n)+1;
	}
	cout<<a<<' '<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}