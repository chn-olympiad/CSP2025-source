#include <iostream>//SN-J00198 吴浩轩 铜川市第一中学 
#include <string>
using namespace std;
int main(){
	int a[1005];
	int n,m,t=1,h=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		if(a[i]>a[1]){
			t++;
		}
		if(t>n){
				h++;
		}
		
	}
	cout<<t<<" "<<h;
	return 0;
}
 
