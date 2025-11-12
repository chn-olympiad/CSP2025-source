//I can have a score of 400.
#include<iostream>
using namespace std;
int n,m,js=0,bnum=0,mysc;
int a[103],b[103];
struct Node{
	int m,myid;
};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		js++;
	}
	mysc=a[0];
	int js2=js;
	while(js2--){
		Node mymax;
		mymax.m=-1;
		for(int j=0;j<js;j++){
			if(a[j]>mymax.m){
				mymax.m=a[j];
				mymax.myid=j;
			}
		}
		b[bnum]=mymax.m;
		a[mymax.myid]=-1;
		bnum++;
	}
	for(int i=0;i<js;i++){
		if(b[i]==mysc){
			if(n==1)cout<<i+1<<' '<<1;
			else if(m==1)cout<<1<<' '<<i+1;
			else break;
			break;
		}
	}
	return 0;
}
