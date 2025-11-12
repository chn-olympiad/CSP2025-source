#include<bits/stdc++.h>
using namespace std;
int n,m,a=1,b=1,f=1,num,x,arr[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
	}
	num=n*m;
	x=arr[1];
	sort(arr+1,arr+(n*m)+1);
	while(x!=arr[num]){
		if(f==1){
			a++;
			if(a==n+1 && b%2==1){
				a=n;
				b++;
				f=0;
			}
		}
		else{
			a--;
			if(a==0 && b%2==0){
				a=1;
				b++;
				f=1;
			}
		}
		num--;
	}
	cout<<b<<" "<<a<<endl;
	return 0;
}
