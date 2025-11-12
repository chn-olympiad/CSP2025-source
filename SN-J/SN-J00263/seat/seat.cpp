#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105]={},ii=1;;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	int aa=a[1];
	sort(a+1,a+n*m+1);
//	cout<<a[1]<<' '<<a[n*m];
	for(int i=n*m;i>=1;i--){
		if(a[i]==aa){
			break;
		}
		ii++;
	}
	if(ii%n==0){
		cout<<"1";
		cout<<' '<<(ii/n)+1;
	}
cout<<ii%n<<" "<<(ii/n)+1;
	//cout<<ii;
	return 0;
}

