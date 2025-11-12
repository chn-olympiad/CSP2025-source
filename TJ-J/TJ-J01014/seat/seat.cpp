#include <iostream>
#include <algorithm>
using namespace std;
int arr[125][125];
int brr[10005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>brr[i];
	}
	int r=brr[1];
	sort(brr+1,brr+(n*m)+1,cmp);
	int f=1,tx=1,ty=1;
	for(int i=1;i<=n*m;i++){
		if(brr[i]==r){
			cout<<ty<<" "<<tx;
			break;
		}
		tx+=f;
		if(tx==(n+1)||tx==0){
			ty++;
			if(tx==(n+1)) tx=n;
			if(tx==0) tx=1;
			f=-f;
		}
	}
	return 0;
}
