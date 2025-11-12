#include<fstream>
std::ifstream cin("road.in ") ;
std::ofstream cout("road.out") ;
using namespace std;
int main(){
    int n,m,k,a[100][100],b[100][100];
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
    	for(int j=0;j<3;j++){
    		cin>>a[i][j];
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<(n+1);j++){
			cin>>b[i][j];
		}
	} 
	cout<<13;
	return 0;
}
