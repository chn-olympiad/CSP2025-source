#include<bits/stdc++.h>
using namespace std;
long long n=0,a[99999],k=0,s=0,m=3,z=0;
int main(){
	freopen("polygon.in",'r',stdin);
	freopen("polygon.out",'w',stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int g=m;g<=n;g++){
		for(int i=n;i>=1;i--){
			k=a[i];
			for(int j=i-1;j>=1;j--){
				for(int z=1;z<g;z++){
					k+=a[j];
					j--;
				}
				j+=g-2;
				if(k>a[i]*2){
					cout<<a[i]<<a[j]<<k<<a[i]*2<<' ';
					s++;
				}
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

