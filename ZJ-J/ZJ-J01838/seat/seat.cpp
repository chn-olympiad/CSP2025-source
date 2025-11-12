#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mx=110;

int n,m;
int a[mx];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int tmp=a[1];
	sort(a+1,a+n*m+1,cmp);
	int rak;
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			rak=i;
			break;
		}
	}
	//cout<<rak<<endl;
	int c=rak/n;
	int r=rak%n;
	if(r==0){
		if(c%2==1){
			cout<<c<<" "<<n<<endl;
			return 0;
		}
		else{
			cout<<c<<" "<<1<<endl;
			return 0;
		}
	}
	if(c%2==0) cout<<c+1<<" "<<r<<endl;
	else cout<<c+1<<" "<<n-r+1<<endl;
	
	return 0;
}
