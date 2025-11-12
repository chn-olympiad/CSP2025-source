#include<iostream>
#include<string>
using namespace std;
string a[10005];
int main()
{
	int n;
	int m;
	cin>>n>>m;
	for(int i=0;i<10005;i++){
		cin>>a[i];
		if(i>0&&a[i]>a[0]){
			n--;
			m--;
		}
	}
	cout<<n<<" "<<m;
	return 0;
}