#include<bits/stdc++.h>
using namespace std;
const int N=15;
long long int n,m,a[N*N],hang=1,lie=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			cout<<hang<<" "<<lie;
			break;
		}
		if(hang%2==1)lie++;
		else lie--;
		if(lie>n){
			hang++;
			lie=n;
		}
		if(lie<1){
			hang++;
			lie=1;
		}
	}
	return 0;
} 
