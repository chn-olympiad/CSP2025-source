#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct str{
	int sum;
	int id;
};
bool cmp(str a,str b){
	return a.sum>b.sum;
}
int n,m;
str a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i].sum;
		a[i].id = i;
	}
	sort(a+1,a+n*m+1,cmp);
	int l;
	for(int i = 1;i<=n*m;i++){
		if(a[i].id==1){
			l = i;
			break;
		}
	}
	if(l%n==0){
		cout<<l/n<<" ";
		if(l/n%2){
			cout<<n;
		}
		else{
			cout<<1;
		}
	}
	else{
		cout<<(l/n+1)<<" ";
		if((l/n+1)%2==0){
			cout<<n-(l%n)+1;
		}
		else{
			cout<<(l%n);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
