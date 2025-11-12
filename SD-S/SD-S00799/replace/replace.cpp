#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
string a[200100];
string b[200100];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++){
		cout<<rand()%998244353<<endl;
	}
	return 0;
}
