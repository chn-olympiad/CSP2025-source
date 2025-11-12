//SN-J00678 ¶ÎÑÅçÍ ¸¨ÂÖÖĞÑ§  
#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		a[i]=-a[i];
	}
	p=a[1];
	sort(a+1,a+n*m+1);
	int l=1,r=1,cnt=1;
	if(a[1]==p){
		cout<<1<<' '<<1;
		return 0;
	}
	while((m%2==1&&l!=n||r!=m)||(m%2==0&&l!=1||r!=m)){
		if(r%2==1){
			if(l==n){
				r++;
			}
			else{
				l++;
			}
		}
		else{
			if(l==1){
				r++;
			}
			else{
				l--;
			}
		}
		cnt++;
		if(a[cnt]==p){
			cout<<r<<' '<<l;
			return 0;
		}
	}
	return 0;
}

