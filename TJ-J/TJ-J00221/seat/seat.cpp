#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	int fid=a[0];
	sort(a,a+n*m,cmp);
	int cnt=0;
	int j=1;
	bool flag=0;//0:1~n, 1:n~1
	//for(int i=0;i<n*m;i++)cout<<a[i]<<' ';
	for(int i=1;i<=n;i++){
		for(;;){
			if(j==0||j==m+1)break;
			//cout<<a[cnt]<<':'<<i<<','<<j<<endl; 
			if(a[cnt++]==fid){
				//cout<<"yes";
				cout<<i<<' '<<j<<endl;
				return 0;
			}
			//cout<<44;
			if(flag){
				j--;
				//cout<<33<<endl;
			}
			else {
				j++;
				//cout<<55<<endl;
			}
		}
		if(flag){
			flag=0;
			j=1;
		}
		else{
			flag=1;
			j=m;
		}
	}
	return 0;
}
