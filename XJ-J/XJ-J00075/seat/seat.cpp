#include<iostream>
using namespace std;
int b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int s;
		cin>>s;
		b[s]++;
		if(i==1)
			t=s;
	}
	int i=1,j=1;
	for(int z=100;z>=1;z--){
		if(b[z]!=0)
			if(z==t){
				cout<<j<<" "<<i;
				break;
			}else{
				if(j%2==1){
					if(i!=n)
						i++;
					else j++;
				}else{
					if(i!=1)
						i--;
					else j++;
				}
			}
	}
	return 0;
}
