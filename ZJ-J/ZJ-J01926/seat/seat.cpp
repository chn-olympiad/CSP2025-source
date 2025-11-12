#include<iostream>
#include<algorithm>
using namespace std;
int a[110];
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n>>m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int num=a[1];
	sort(a+1,a+n*m+1 ,greater<int>());
	int idx;
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			idx=i;
		}
	}
	if(idx%n==0){
		if((idx/n)%2){
			cout << idx/n<<" "<<n;
		}else{
			cout << idx/n<<" "<<1;
		}
	}else{
		if((idx/n)%2==0){
			cout << idx/n+1<<" "<<idx%n;
		}else{
			cout << idx/n+1<<" "<<n-idx%n+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
