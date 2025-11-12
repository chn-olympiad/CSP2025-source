//Ñ¦ŞÈÆ½   ¸¨ÂÖÖĞÑ§    SN-S00640
#include <bits/stdc++.h>
using namespace std;

int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; 
	cin>>t;
	int n; 
	cin>>n;
	int a[10005],b[10005],c[10005];
	for (int i=1; i<=n; i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int sum=0;
	for (int i=1; i<=n; i++){
		if (a[i]>b[i]){
			if (a[i]>c[i]){
				sum+=a[i];
			}
			else 
			{
				sum+=c[i];
			}
		}
		else if(b[i]>a[i])
		{
			if (b[i]>c[i]){
				sum+=b[i];
			}
			else{
				sum+=c[i];
			}
		}
		else if (c[i]>b[i]){
			if (c[i]>a[i]){
				sum+=c[i];
			}
			else {
				sum+=a[i];
			}
		}
		else if (c[i]<b[i]){
			if (b[i]>a[i]){
				sum+=b[i];
			}
			else {
				sum+=a[i];
			}
		}
		else if (c[i]>a[i]){
			if (c[i]>b[i]){
				sum+=c[i];
			}
			else {
				sum+=b[i];
			}
		}else if (c[i]<a[i]){
			if (b[i]>a[i]){
				sum+=b[i];
			}
			else {
				sum+=a[i];
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
