//SN-J00663  樊思航  西安高新一中沣东中学初中校区
#include <fstream>
std::ifstream cin("seat.in");
std::ofstream cout("seat.out ");
int a[105];
int main(){
	
	int n,m,x=1,b=0,c=0;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m*n;i++){
		if(a[i]>a[1]){
			x++;
		}
		
	}
    if(x%n==0){
       c=x/n;
	}
	else
	{c=x/n+1;
	}
	if(c%2==0){
	    
	b=n-x%n+1;
	}
	if(x%n==0&&c%2==0){
		    b=1;
		}
	if(c%2==1){      
	    
	b=x%n;
	}
	if(x%n==0&&c%2==1){
		    b=n;
	    }
	cout<<c<<" "<<b;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}


