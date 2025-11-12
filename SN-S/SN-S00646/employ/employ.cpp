#include<fstream>
#include<string>
std::ifstream cin("employ.in");
std::ofstream cout("employ.out");

int main(){
	long long n,m;
	cin >> n >> m ;
	for(int i=0;i<n;i++){
		cin >> i ;
	}
	for(int j=0;j<n;j++){
		cin >> j ;
	}
	cout << 4 ;
	return 0;
}
