#include<bits/stdc++.h> 
using namespace std;
int arr[1100];
int maze[110][110];
bool cmp(int a,int b){
	if(a==b){
		return false;
	}
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a=0;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
		if(i==1){
			a=arr[i];
		}
	}
	sort(arr+1,arr+1+n*m,cmp);
	int rk=0;
	for(int i=1;i<=n*m;i++){
		if(arr[i]==a){
			rk=i;
		}
	}
	int sum=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				maze[j][i]=sum;
				sum++;
			}
		}else{
			for(int j=1;j<=n;j++){
				maze[j][i]=sum;
				sum++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(maze[j][i]==rk){
				cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}
