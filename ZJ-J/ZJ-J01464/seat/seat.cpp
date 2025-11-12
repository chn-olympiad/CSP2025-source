#include<bits/stdc++.h>
// I am Zha4 Pian4 Fan4
using namespace std;
int arr[110];
//9:03~9:38 ,AC?
//9:31 chong2 zuo4
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//freopen("seat.in","r",stdin); esat saet seta
	//freopen("seat.out","W",stdout); feropen() froepen() frepoen() freoepn() feropne() rfeopen()
	freopen("seat.in","r",stdin);
	freopen("seat.out","W",stdout);
	int n,m;
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>arr[i];
	}
	int xr=arr[1];
	sort(arr+1,arr+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(arr[i]==xr){
			xr=i;
			break;
		}
	}
	int l_xr=(xr-1)/n+1;
	int h_xr=(xr-1)%n+1;
	if(l_xr%2==1){
		cout<<l_xr<<' '<<h_xr;
	}else{
		cout<<l_xr<<' '<<(n-h_xr+1);
	}
	return 0;
}
