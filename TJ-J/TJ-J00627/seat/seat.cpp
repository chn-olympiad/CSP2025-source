#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	cout<<"Shao Yu niubi"<<endl;
	cout<<"Qiu Chenyang niubi"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
