#include<bits/stdc++.h>
using namespace std;
int arr[114],n,m,id=0,point;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>arr[i];
	point=arr[0];
	sort(arr,arr+n*m,cmp);
	while(arr[id]!=point)id++;
	int colume=id/n+1;int line=id%n+1;
	if(!(colume&1))line=n-line+1;
	cout<<colume<<" "<<line;
}