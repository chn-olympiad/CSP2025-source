#include<bits/stdc++.h>
using namespace std;
int s[105],a[105],b[105],cnt,ming;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
		a[s[i]]=s[i]; 
	}
	for(int i=100;i>=1;i--){
		if(a[i]>0){
			cnt++;
			b[cnt]=a[i];
			if(a[i]==s[1]){
				ming=cnt;
				break;
			}
		}
	}
	int h=ming%n,l=ming/n;
	if(ming<=n*l) c=l;
	else{
		c=l+1;
	}
	if(c%2==0){
		r=1+(n-h);
	} 
	else if(c%2!=0){
		if(h==0){
			r=n;
		}
		else{
			r=h;
		}
	}
	cout<<c<<' '<<r;
	return 0;
} 
