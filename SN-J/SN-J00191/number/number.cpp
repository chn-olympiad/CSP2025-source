#include <bits/.stdc++h>
using namespace std;

int main()
{
	
	int n,m;
	cin >> n >m;
	int maxn = 0;
	int a[1000];
	int b [1000][1000];
	for(int i=0;i<= n*m;i++){
		cin >> a[i];
	}
	for(int i=0;i <=n;i++){
		for(int j=0;j<=m;j++){
			if(a[i] > maxn){
				b[i][j]=a[i];
				cout << b[i][j];
			}
		}
	}
	return 0;
}
