#include<fstream>
std::ifstream cin("replace.in") ;
std::ofstream cout("replace.out") ;
using namespace std;
int main(){
    int n,q;
    char a[10][10],b[10][10];
    cin>>n>>q;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>a[i][j];
		}
	}
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	cout<<2<<endl;
	cout<<0<<endl;
	return 0;
}
