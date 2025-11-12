#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b,v=1,z,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n*m-1;i++){
		cin>>b;
		if(b>a){
			v++;
		}
	}
	if(v%n==0){
		cout<<v/n<<" ";
		if(v/n%2==0){
			cout<<1;
		}else{
			cout<<n;
		}
		
	}else{
		cout<<(v/n)+1<<" ";
		if(v/n%2==0){
			cout<<v%n;
		}else{
			cout<<n-(v%n)+1;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
