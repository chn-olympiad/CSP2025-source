#include<bits/stdc++.h>
using namespace std;

int n,m,v,l=1;
int a[110];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	v=a[1];
	bool f=false;
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(a[l]==v){
					cout<<j<<' '<<i;
					f=true;
					break;
				}
				l++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(a[l]==v){
					cout<<j<<' '<<i;
					f=true;
					break;
				}
				l++;
			}
		}
		if(f)break;
	}
}

