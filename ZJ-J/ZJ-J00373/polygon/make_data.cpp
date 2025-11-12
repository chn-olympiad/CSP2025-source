#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int myrand(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	freopen("polygon.in","wb",stdout);
	srand(GetTickCount());
	int n=myrand(1,20);
	cout<<n<<endl;
	for(int i=1;i<=n;i++)cout<<myrand(0,100)<<' ';
	return 0;
}
