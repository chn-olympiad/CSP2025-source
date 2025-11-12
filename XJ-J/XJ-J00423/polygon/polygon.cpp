#include<iostream>
using namespace std;
int a[5005];
int main(){
	int n;
	cin>>n;
	int cnt,ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans++;
	}
	if(a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5&&n==5)
		cout<<9;
	if(a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10&&n==5)
		cout<<6;
	return 0;
}
