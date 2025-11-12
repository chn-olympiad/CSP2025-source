#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int a[105];
int myrand(int l,int r){
	return rand()%(r-l+1)+l;
}
int main(){
	freopen("seat.in","wb",stdout);
	srand(GetTickCount());
	int n=myrand(1,10),m=myrand(1,10);
	for(int i=1;i<=100;i++)a[i]=i;
	random_shuffle(a+1,a+100+1);
	cout<<n<<' '<<m<<endl;
	for(int i=1;i<=n*m;i++)cout<<a[i]<<' ';
	return 0;
}
