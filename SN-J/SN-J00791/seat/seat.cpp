#include<bits/stdc++.h>
using namespace std;
int a[115];
int main(){
	//freopen("seat.in","r",stdin)
	//freopen("seat.out","w",stdout)
	int m,n,max=0,min=100;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		if(a[i]>max)
		{
			a[i]=max;
		}
		if(a[i]<min)
		{
			a[i]=min;
		}	
	}
	int b=a[1];
	cout<<b;
	cout<<max<<min;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
