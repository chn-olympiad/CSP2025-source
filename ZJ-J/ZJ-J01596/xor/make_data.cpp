#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
int brand(){
	return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int rand_(int l,int r){return brand()%(r-l+1)+l;}
signed main(){
	freopen("xor.in","w",stdout);
	srand(GetTickCount());
	int n=rand_(1,1000),k=rand_(1,1024575);
	cout<<n<<" "<<k<<endl;
	for(int i=1;i<=n;i++)cout<<rand_(1,1024575)<<" ";cout<<endl;
	return 0;
}