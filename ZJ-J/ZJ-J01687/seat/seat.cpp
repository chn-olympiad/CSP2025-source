#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int tmp=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	tmp=a[1];
	sort(a+1,a+1+n*m,greater<int>() );
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp){
			int t1=i%n,t2=i/n;
			if(t1==0) t1=n;
			else t2++;
			if(!(t2%2)) t1=n-t1+1;
			cout<<t2<<" "<<t1;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
