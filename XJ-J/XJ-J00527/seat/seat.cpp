#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[n+5][m+5];
	cin>>n>>m;
	int j,c=0,q=1,mut=1;
	int p[n*m+5];
	for(int i=1;i<=n*m;i++){
		cin>>p[i];
		if(i!=1&&p[1]>p[i]){
			q++;
		}
		if(i!=1&&p[1]<p[i]){
			mut++;
		}
	}
	if(mut==n*m){
		cout<<n<<' '<<m;
		return 0;
	}
	else if(q==n*m){
		cout<<1<<' '<<1;
		return 0;
	}
	int t=p[1];
	sort(p+1,p);
	for(int i=1;i<=n;i++){
		for(j=1;;){
			if(i%2==0){
				a[j][i]=p[c];
				c++;
				j--;
			}
			else if(i%2!=0){
				a[j][i]=p[c];
				c++;
				j++;
			}
			if(j==m||j==0)break; 
		}
	}
	for(int i=1;i<=n;i++){
		for(int z=1;z<=m;z++){
			if(a[i][z]==t){
				cout<<i<<' '<<z;
				return 0;
			}
		}
	}
}
