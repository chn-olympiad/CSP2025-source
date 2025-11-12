#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int num[105],nm[11][11];
	for(int i=1;i<=n*m;i++){
		cin >> num[i];
	}
	int ming=num[1];
	sort(num+1,num+n*m+1);
	queue<int> numb;
	for(int i=n*m;i>=1;i--){
		numb.push(num[i]);
	}
	int sum;
	for(int i=1;i<=n*m;i++){
		num[i] = numb.front();
		numb.pop();
		if(num[i]==ming) sum=i;
	}
	
	int hang = sum%n;
	int lie = sum/n;
	if(hang==0){
		if(lie%2 ==0) cout<<lie<<" "<<1;
		else cout << lie<<" "<<n;
	}
	else{
		if((lie+1)%2==0) cout<<lie+1<<" "<< n-hang+1;
		else cout<<lie+1<<" "<<hang;
    }
	
	return 0;
}
