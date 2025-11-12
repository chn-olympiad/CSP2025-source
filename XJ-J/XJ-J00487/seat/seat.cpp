#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[150];
int main (){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin >>n>>m;
	int r;
	for (int i=1;i<=n*m;i++){
		cin >>arr[i];
	} 
	r=arr[1];
	sort (arr+1,arr+1+n*m,greater<int>());
	for (int i=1;i<=n*m;i++){
		if (arr[i]==r){
			r=i;
			break;
		}
	}
//	cout <<r<<' '<<n<<'\n';
	int tmp=(ceil)(r*1.0/n);
	int tmp2;
	if (r%n==0){
		tmp2=n;
	}else {
		tmp2=r%n;
	}
	if (tmp%2==0){
		tmp2=n+1-tmp2;
	}
	cout <<tmp<<' '<<tmp2;
	fclose (stdin);
	fclose (stdout);
	
	return 0;
}
