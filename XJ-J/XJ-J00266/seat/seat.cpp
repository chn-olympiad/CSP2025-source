#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[100];
  for(int i=1;i<=n;i++){
  	for(int j=1;j<=m;j++){
  		cin>>a[i];
  	a[i]=n*m-i+1;
	  }
  }
   for(int i=1;i<=n;i++){
  	for(int j=1;j<=m;j++){
  		cout<<a[i];
    }
    cout<<a[i];
}
	return 0;
}

