#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int m,c=0;
		cin>>m;
		int a[m][3];
		for(int i=0;i<m;i++){
			int mx1=0;
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				mx1=max(mx1,a[i][j]);
			}
			c+=mx1;
		}
		cout<<c<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
