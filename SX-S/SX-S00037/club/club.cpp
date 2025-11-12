#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,max=-0x3f3f3f3f,num=0;
	int m[10][11000],flag[3];
	int c;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> n;

		for(int j=0; j<n; j++){
			max=-0x3f3f3f3f;
			for(int k=0; k<3; k++){
				cin >> m[j][k];
				if(m[j][k]>max){
					if(flag[k] <= n/2){
						max=m[j][k];
						c=k;


					}

				}

			}

			num+=max;
			flag[c]++;


		}
		flag[0]=0;
		flag[1]=0;
		flag[2]=0;
		cout << num << endl;
		num=0;
	}

	return 0;
}