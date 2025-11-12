#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int myrand(int l,int r){
	return (rand()<<16|rand()<<1|rand()&1)%(r-l+1)+l;
}
int main(){
	freopen("xor.in","wb",stdout);
	srand(GetTickCount());
	int n=myrand(1,1000),m=rand()%10==0?0:myrand(0,7);
	cout<<n<<' '<<m<<endl;
	for(int i=1;i<=n;i++)cout<<myrand(0,7)<<' ';
	return 0;
}
