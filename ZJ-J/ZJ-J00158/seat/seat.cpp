#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N],b[N],s[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i] = a[i];
	}
	int tot = 0;
	sort(b+1,b+n*m+1,greater<int>());
    int x = n*m;
    for(int i=1;i<=x;i++){
    	if(b[i] == a[1]){
    		tot = i;
		}
	}
	if(a[1] == b[n*m]){
		cout<<m<<" "<<n;
		return 0;
	}
	if(tot<=n){
		cout<<1<<" "<<tot;
	}else if((tot/n+1)%2 == 1){
			cout<<tot/n+1<<" "<<tot%n;
		}else{
			cout<<tot/n+1<<" "<<(tot/n+1);
		}
	
	
	return 0;
}
