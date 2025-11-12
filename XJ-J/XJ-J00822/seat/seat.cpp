#include<bits/stdc++.h>

using namespace std;

const int N=20;
int n,m;
int a[N*N];

bool cmp(int p,int q){
	return p>q;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k,grade=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==grade){
			k=i;
			break;
		}
	}
	int cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				cnt++;
				if(cnt==k){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				cnt++;
				if(cnt==k){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
	return 0;
} 
