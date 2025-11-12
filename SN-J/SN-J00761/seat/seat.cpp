#include <bits/stdc++.h>
using namespace std;
int n,m,s[11],a[105],b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];a[i]=b[i];
	}
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(a[j]<a[j+1])
			swap(a[j+1],a[j]);
		}
	}
	cout<<b[0]/n<<" "<<"1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
