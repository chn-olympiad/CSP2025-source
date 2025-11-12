#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],k,h=1,l=1,sh,sl;
//struct
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==k){
			sh=h;
			sl=l;
			break;
		}
		if(l%2==1){
			h++;
			if(h>n){
				h=n;
				l++;
			}
		}
		else{
			h--;
			if(h==0){
				h=1;
				l++;
			}
		}
		
	}
	cout<<sl<<" "<<sh;
	return 0;
}
