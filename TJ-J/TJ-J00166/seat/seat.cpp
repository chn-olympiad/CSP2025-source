#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],t,k;
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++){
		if(t==a[i]){
			k=i;
			break;
		}
	}
	if (k%n==0){
		if ((k/n)%2==0){
			cout<<k/n<<' '<<1;
		}else{
			cout<<k/n<<' '<<m;
		}
	}else{
		int lie=k/n+1;
		if (lie%2==0){
			cout<<lie<<' '<<m-k%n+1;
		}else{
			cout<<lie<<' '<<k%n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

