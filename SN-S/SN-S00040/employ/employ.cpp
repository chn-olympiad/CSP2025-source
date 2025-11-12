//SN-S00040
#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>q;
	srand(n*q);
	cout<<rand()%998244353;
}
