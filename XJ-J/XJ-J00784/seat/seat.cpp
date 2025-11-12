#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[n*m];
	cin>>n>>m;
	int max_num=0;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		int s=100-a[0]+1;
		if(a[i]>max_num){
			max_num=a[i];
		}
		if(a[0]==max_num){
			cout<<1<<' '<<1<<endl;
		}
		else if(s<=n && n-s=0){
			cout<<1<<' '<<n<<endl;
		}
		else if(s<=n && n-s=1){
			cout<<1<<' '<<n-1<<endl;
		}
		else if(s>n && 2n-s=0){
			cout<<2<<' '<<1<<endl;
		}
		else if(s>n && 3n-s=0){
			cout<<3<<' '<<1<<endl;
		}
		else if(s>n && 4n-s=0){
			cout<<4<<' '<<1<<endl;
		}	
		else if(s>n && 5n-s=0){
			cout<<5<<' '<<1<<endl;
		}
		else if(s>n && 6n-s=0){
			cout<<6<<' '<<1<<endl;
		}	
		else if(s>n && 7n-s=0){
			cout<<7<<' '<<1<<endl;
		}
		else if(s>n && 8n-s=0){
			cout<<8<<' '<<1<<endl;
		}	
		else if(s>n && 9n-s=0){
			cout<<9<<' '<<1<<endl;
		}	
		else if(s>n && 10n-s=0){
			cout<<10<<' '<<1<<endl;
		}			
	}
	return 0;
}
