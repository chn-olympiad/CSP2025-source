#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[200];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int a1=a[1],mc;
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			mc=n*m+1-i;
		}
	}
	long long shang=mc/n;
	long long yu=mc%n;
	if(yu==0){
		if(shang%2==0){
			cout<<shang<<' '<<1;
			return 0;
		}else{
			cout<<shang<<' '<<n;
			return 0;
		}
	}else{
		if(shang%2==0){
			cout<<shang+1<<' '<<yu;
			return 0;
		}else{
			cout<<shang+1<<' '<<n+1-yu;
			return 0;
		}
	}
	return 0;
}
