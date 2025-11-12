#include<bits/stdc++.h>
using namespace std;
int a[105];
int d[11][11];
bool cmp(int a,int b){
	if(a >= b){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	int r = a[1];
	sort(a+1,a+n*m+1,cmp);
	int sum = 1;
	
	for(int i = 1;i<=n*m;i++){
		if(a[i] == r){
			sum = i;
		}
	}
	if((sum / n) % 2 == 1 && sum % n == 0){
		cout<<sum/n<<" "<<n;
	}else if((sum / n) % 2 == 0 && sum % n == 0){
		cout<<sum/n<<" "<<1;
	}else if((sum / n) % 2 == 1 && sum % n != 0){
		cout<<(sum/n) + 1<<" "<<n - (sum % n) + 1;
	}else{
		cout<<(sum/n) + 1<<" "<<sum % n;
	}
	
	
	
	
	

	
	
	
	
	
	
	
	
	return 0;
} 
