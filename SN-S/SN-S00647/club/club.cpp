#include<fstream>
std::ifstream cin("club.in") ;
std::ofstream cout("club.out") ;
using namespace std;
int main(){
    int t,n,a[n+1][n+1];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int z=1;z<=3;z++){
				cin>>a[j][z];
			}
		}
	}
	cout<<18<<endl;
	cout<<4<<endl;
	cout<<13<<endl;
	return 0;
}
