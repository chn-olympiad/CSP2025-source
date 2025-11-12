#include<bits/stdc++.h>//100pts
#define int long long
using namespace std;
long long n,m,a[1005],rk;
inline void get_rk(){
	int qwq=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		rk++;
		if(a[i]==qwq){
			break;
		}
	}
	return;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	system("fc seat1.ans seat.out");
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	get_rk();
	int k=2*n;
	int lie=rk/k*2;
	rk%=k;
	if(rk==0){
		rk=k;
	}
	if(1<=rk&&rk<=n){
		lie++;
	}
	else{
		lie+=2;
	}
	cout<<lie<<" ";
	if(1<=rk&&rk<=n){
		cout<<rk<<endl;
	}
	else{
		cout<<k-rk+1<<endl;
	}
	return 0;
}
