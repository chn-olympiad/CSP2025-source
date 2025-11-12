#include <iostream>
#include <algorithm>
using namespace std;
int a[225];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n*m;i++)cin >> a[i];
	int t=a[0];
	sort(a,a+n*m,cmp);
	int p;
	for(int i=0;i<n*m;i++){
		if(a[i]==t){
			p=i;
			break;
		}
	}
	int s=0;
	for(int i=0,j=0,cnt=0;i<n&&j<m;cnt++){
		if(cnt==p){
			cout << j+1 << ' ' << i+1 << endl;
			return 0;
		}
		if(i==n-1 && s==0){
			j++;s=1;
		}else if(i==0 && s==1){
			j++;s=0;
		}else if(s==0){
			i++;
		}else if(s==1){
			i--;
		}
	}
	return 0;
}
