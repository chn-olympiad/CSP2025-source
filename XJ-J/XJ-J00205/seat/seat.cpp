#include<bits/stdc++.h>
using namespace std;
int arr[11][11]={0};
int arr1[110]={0};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,x=1;
	bool a=true;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> arr1[i];
	}
	a1=arr1[1];
	sort(arr+1,arr+1+(n*m),cmp);
	for(int i=1;i<=n;i++){
		if(a){
			for(int j=1;j<=m;j++){
				arr[i][j]=arr1[x];
				if(arr[i][j]==a1){
					cout << i << " " << j;
					break;
				}
				x++;
			}
			a=false;
		}else{
			for(int j=m;j>=1;j--){
				arr[i][j]=arr1[x];
				if(arr[i][j]==a1){
					cout << i << " " << j;
					break;
				}
				x++;
			}
			a=true;
		}
	}
	return 0;
} 
