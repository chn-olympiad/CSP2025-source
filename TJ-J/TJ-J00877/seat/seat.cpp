# include<bits/stdc++.h>
using namespace std;
int n,m,g,cnt=1,c,r;
int a[1010],b[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==1&&m==1){
		cout<<1<<' '<<1;
		return 0;
	}else if(n==1){
		for(int i=1;i<=n*m;i++){
			cin>>a[i];
		}
		g=a[1];
		sort(a,a+n*m+1);
		for(int i=n*m;i>=1;i--){
			b[cnt]=a[i];
			cnt++;
		}
		for(int i=1;i<=m;i++){
			if(b[i]==g){
				cout<<i<<' '<<1;
			}
		}
		return 0;
	}

	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	g=a[1];
	sort(a,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		b[cnt]=a[i];
		cnt++;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;i++){
			if(g==a[i]){
				cout<<i<<' '<<j<<'Yes';
				return 0;
			}else{
				cout<<i<<' '<<j<<endl;
			}
		}
		for(int j=n;j>=1;i--){
			if(g==a[i]){
				cout<<i<<' '<<j;
				return 0;
			}else{
				cout<<i<<' '<<j<<endl;
			}
		}
	}
	return 0;
}
