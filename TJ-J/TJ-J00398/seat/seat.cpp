#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,c=1,r=1;
	cin>>n>>m;
	int a[n*m+1];
	
	for(int i = 0;i<n*m;i++){
		cin>>a[i];
	}
	
	for(int i = 1;i<n*m;i++){
		if(a[i]>a[0]){
			if(c==n&&r%2!=0){
				r++;
				continue;
			}else if(c==1&&r%2==0){
				r++;
				continue;
			}if(r%2==0){
				c--;
			}else if(r%2!=0){
				c++;
			}
		}
	}
	
	cout<<r<<" "<<c<<endl;
	return 0;
}
