#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[105],my,nans=0,mans=0,b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	my=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1,j=n*m;i<=n*m;i++,j--){
		b[i]=a[j];
	}
	for(int i=1;i<=n*m;i++){
		if(b[i]==my){
			my=i;
			break;
		}
	}
	if(m==1){
		cout<<"1"<<" "<<my<<endl;
	}
	else{
		if(my%n==0){
			mans=my/n;
		}
		else{
			mans=my/n+1;
		}
		if(mans%2==1){
			nans=my-(mans-1)*n;
		}
		else{
			nans=n+1-(my-(mans-1)*n);
		}
	}
	cout<<mans<<" "<<nans;
	
	return 0;
} 
