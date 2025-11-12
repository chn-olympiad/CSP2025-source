#include<bits/stdc++.h> 
using namespace std;
int x_1[10000000][3],x_2=0,x_3=0,x_4=0;

int main() {
	//freopen("club.in","r","stdin");
	//freopen("club.out","w","stdout");
	int n;
	for(int i=0;i<n;i++)
	{
		cin >> n;
		if (n != 10000000)
		{
			for(int j;j<n;j++)
			cin >> x_1[j][0] >> x_1[j][1] >> x_1[j][2];
			x_2 = n;
			x_3 = n/2;
			cout << x_3 << endl;	
		}
		else if (n == 10000000)
		{
			int x_4[n];
			for(int j;j<n;j++)
			{
				cin >> x_1[j][0] >> x_1[j][1] >> x_1[j][2];
				x_4[j] = x_1[j][0];
				cout << x_3 << endl;	
			}
		}
	
	}
	
	
	
	
	return 0;
	
}
