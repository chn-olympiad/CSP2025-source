//wsli 2025
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,a[110];

bool cmp(int a,int b) {
	return a>b;
} 
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		scanf("%d",&a[i]);
	}
	int e=a[1],k=1;

	sort(a+1,a+1+n*m,cmp);

//	for(int i=1;i<=n*m;i++) cout<<a[i]<<' ';
//	cout<<endl;
	for(int i=1; i<=m; i++) {
		if(i%2==0) {
			for(int j=n; j>=1; j--) {
//				cout<<"in "<<a[k]<<'\n';
				if(a[k]==e) {
					printf("%d %d",i,j);
					exit(0);
				}
				k++;
			}
		} else {
			for(int j=1; j<=n; j++) {
//				cout<<"in "<<a[k]<<'\n';
				if(a[k]==e) {
					printf("%d %d",i,j);
					exit(0);
				}
				k++;
			}
		}
	}
	return 0;
}
