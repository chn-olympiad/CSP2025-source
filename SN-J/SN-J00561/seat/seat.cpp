#include<bits/stdc++.h>
string namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,a[101]={},x=0,ans=0,c=0,r=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=i;j<=n*m;j++){
			if(a[j]>a[i]){
				c=a[j];
				a[j]=a[i];
				a[i]=c;
				c=0;
			}
		}
	}
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j+=2){
			ans++;
			if(a[ans]==x){
				c=i;
				r=j;
			}
		}
		for(int j=2;j<=n;j+=2){
			ans++;
			if(a[ans]==x){
				c=i;
				r=j;
			}
		}
	}
	cout<<c<<" "<<r<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
