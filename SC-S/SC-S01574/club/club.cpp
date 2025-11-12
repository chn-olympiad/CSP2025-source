#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int a[n][4]={};
		int a1=0,a2=0,a3=0;
		for (int i=0;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			a[i][0]=max(a[i][1],a[i][2]);
			a[i][0]=max(a[i][0],a[i][3]);
			for(int b=0;b<1;b++){
				if (a[i][1]=a[i][0]){
					a1+=a[i][1];
					break;
				}
				else if(a[i][2]=a[i][0]){
					a2+=a[i][2];
					break;
				}
				else{
					a3+=a[i][3];
				}
			}	
		}
		cout << a1 << endl << a2 << endl << a3;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}