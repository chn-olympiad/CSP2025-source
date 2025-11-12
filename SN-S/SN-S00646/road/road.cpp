#include<fstream>
using namespace std;
std::ifstream cin("club.in");
std::ofstream cout("club.out");
int main(){
	int long long t,n;
	int a[0][0];
	cin >> t >> n;	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin >> a[i][j];
			cout << a[1][1]+a[2][3]+a[3][1]+a[4][2] << endl;
		}
	}
	return 0;
}
