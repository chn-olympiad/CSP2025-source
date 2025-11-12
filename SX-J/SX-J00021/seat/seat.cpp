#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[105],b[105],mm;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	int num = a[1];
	int ll = n*m;
	sort(a+1,a+1+ll);
	for(int i = 1;i<=n*m;i++)
	{
		if(a[i] == num){
			num = i;
		}
	}
	num = n*m-num+1;
	if(num%n==0){
		cout<<num/n<<" ";
		mm = num/n;
	}
	else{
		cout<<num/n+1<<" ";
		mm = num/n+1;
	}
	if((mm)%2==0){
		cout<<num%n+n;
	}
	else{
		cout<<num%n;
	}
	return 0;
}
