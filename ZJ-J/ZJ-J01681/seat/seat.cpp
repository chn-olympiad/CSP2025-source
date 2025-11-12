#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int arr[120];
int ans_list[20][20];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p=n*m;
	for(int i=1;i<=p;i++){
		cin>>arr[i];
	}
	int R=arr[1];
	sort(arr+1,arr+1+p,cmp);
	int dec=1;	//0up 1down
	int x=1,y=1;
	for(int i=1;i<=p;i++){
		ans_list[x][y]=arr[i];
		if(dec==1){
			x++;
		}
		else if(dec==0){
			x--;
		}
		if(x<=0){
			x++;
			y++;
			dec=1;
		}
		else if(x>n){
			x--;
			y++;
			dec=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans_list[i][j]==R){
				cout<<j<<' '<<i;
				break;
			}
//			cout<<ans_list[i][j]<<' ';
		}
//		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
