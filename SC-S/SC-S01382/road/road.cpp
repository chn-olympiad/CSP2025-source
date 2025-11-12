#include<bits/stdc++.h>
using namespace std;

int n,m,k,p;
const int N=1e6+100;
const int N1=1e4+100;
long long v[N],u[N],w[N];
long long c[N],a[N];


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out ","w",stdout);
	cin >> n >> m >> k ;
	for (int i=1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i] ;
	}
	for (int i=1;i<=k;i++){
		cin >> c[i] ;
		for (int j=1;j<=n;j++){
			cin >> a[i] ;
		}
	}
	if (k==0){
		sort(w+1,w+1+m);
		int f=0;
		for (int i=1;i<=m;i++){
			for (int j=1;j<i;j++){
				if ((u[j]==u[i] && v[j]==v[i])||(u[j]==v[i] && u[i]==v[j])){
					f=1;
				}
			}
			if (f==1){
				f=0;
			}else{
				p+=w[i];
			}
		}
	}
	cout << p ;
	return 0;
}