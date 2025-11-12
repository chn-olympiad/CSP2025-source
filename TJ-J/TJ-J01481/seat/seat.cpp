#include<bits/stdc++.h>
#define ei else if
#define ll long long
#define pend cout<<endl

//alert to the problem of ambigiousness
using namespace std;


int n,m,c,r,a1,inn;

//vector<int> a;



int main(){
	

	freopen("seat.in","r",stdin);//input
	cin>>n>>m;
	const int listsize=n*m;
	int a[listsize];
	for(int i=0;i<listsize;i++){
		cin>>a[i];
	}
	a1=a[0];
	
	if(a1==100){
		cout<<1<<" "<<1;
		return 0;
	}
	if(a1==1){
		cout<<m<<" "<<n;
		return 0;
	}
	//sort(a+1,a+listsize+1);
	inn=1;
	for(int i=1;i<listsize;i++)
	if(a[i]>a1)
	{
		inn++;
	}
	
	
	/*for(int i=2;i<=100;i++){
		cout<<a[i]<<" ";
	}*/
	freopen("seat.out","w",stdout);//output
	//wei ci
	
	double TEST=n;
	c=ceil(inn/TEST);
	if(c%2==0){
		r=n-(inn-(c-1)*n)+1;
	}
	else{
		r=(inn-(c-1)*n);
	}
	cout<<c<<" "<<r;
	return 0;
}
