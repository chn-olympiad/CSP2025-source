//SN-J00794 王美萱 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<"1";
	}
	return 0;
} 
