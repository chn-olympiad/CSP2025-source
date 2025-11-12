#include<bits/stdc++.h>
using namespace std;
int s[110];
int a[110];
int e[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b,f=0,ans=1;
	int c=1,d=1;
	cin>>n>>m;
	b=n*m;
	for(int i=1;i<=b;i++){
		cin>>s[i];	
		a[i]=s[i];
	} 
	int g=s[1];
	sort(a,a+b+1);
	for(int i=b;i>=1;i--){
		f++;
		e[f]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(e[ans]==g){
				cout<<d<<" "<<c;
			}
			c++;
			ans++;
		}
		d++;
		for(int k=1;k<=n;k++){
			if(e[ans]==g){
				cout<<d<<" "<<c;
			}
			c--;
			ans++;
		}
		d++;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
