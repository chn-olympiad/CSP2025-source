#include<iostream>
using namespace std;
int a[5010];
int n;
int main (){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n<3){
		cout << 0;
		return 0;
	}else{
		int maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
		if(sum>maxn*2){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
