#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	int a[105];
	int x,y;
	int ans=0;
	cin>>m>>n;
	int z=m*n;
	for(int i=1;i<=z;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+z+1);
	for(int i=1;i<=z;i++){
		if(a[i]==r){
			ans++;
			break;
		}
		else{
			ans++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

