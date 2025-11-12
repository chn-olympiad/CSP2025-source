#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int score=a[1];
	sort(a+1,a+1+n*m);
	int pos;
	for(int i=n*m;i>=1;i--){
		if(a[i]==score){
			pos=i;
			break;
		}
	}
	pos=n*m-pos+1;
	int lie=pos/n;
	pos=pos%n;
	if(pos>=1){
		lie++;
	}
	if(lie%2==0){
		if(pos==0){
			pos=n;
		}
		cout<<lie<<" "<<n-(pos-1)<<endl;
	}else{
		if(pos==0){
			pos=n;
		}
		cout<<lie<<" "<<pos<<endl;
	}
	return 0;
}
