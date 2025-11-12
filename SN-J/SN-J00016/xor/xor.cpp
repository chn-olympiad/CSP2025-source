//SN-J00016
//我有预感今年1=线要上200(恐
//完了异或是啥来着 
//算了不管了不可以,总司令！ 
#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
int n,k,a[5000005],b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	cout<<"RP++";
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)b++;
	}
	cout<<b;
	return 0;
}
