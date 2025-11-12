#include<bits/stdc++.h>
using namespace std;
short q[104];
bool cmp(int z,int x){
	return z>x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int z,x;
	int c;
	cin>>z>>x;
	for(int i=1;i<=z*x;i++){
		cin>>q[i];
	}int flag=q[1];
	sort(q+1,q+1+z*x,cmp);
	for(int i=1;i<=z*x;i++){
		if(flag==q[i]){
			if(i%z==0){
				c=i/z;
				cout<<i/z<<" ";
			}else{
				c=i/z+1;
				cout<<i/z+1<<" ";
			}if(i%z==0){
				if(c%2!=0){
					cout<<z;
				}else{
					cout<<1;
				}
			}else{
				if(c%2!=0){
					cout<<i%z;
				}else{
					cout<<1+z-(i%z);
				}
			}
		}
	}
	return 0;
}