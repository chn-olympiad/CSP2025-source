 #include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	int n,m,j,k,g=0,h=0,d=0,c=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>n;
	while(n--){
		cin>>m; 
		for(int i=1;i<=3;i++){
			for(int j=1;j<=m;j++){
				cin>>k;
				if(k%2==0){
					d=h;
					h=g;
					g=k/2;
				}
			}
			c=g+h+d;
			for(int j=1;j<=n;j++){
				a[j]=c;
				c=0;
				continue;
			}
		}
			
	}

	return 0;
}
