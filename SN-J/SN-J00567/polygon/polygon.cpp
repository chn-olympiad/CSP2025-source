/*李牧泽 SN-J00567 西安滨河学校*/
#include<bits/stdc++.h>
using namespace std;
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int a[5005];
int main(){
	//FI("polygon");
	//FO("polygon");
	int n,a,b,c;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	if ((a[0]+a[1]+a[2])>(2*max(a[2],max(a[0],a[1])))){
		cout<<1;
	}
	return 0;
} 
