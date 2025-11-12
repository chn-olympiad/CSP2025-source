#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int sum=0;
int a[10010],b[10010],c[10010];
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+n,a+1+n);//n
		sort(b+n,b+1+n);
		sort(c+n,c+1+n);
		for(int i=0;i<=n;i++){//0
			int s1=max(a[i],a[n])+a[n];
			for(int j=0;j<=n-i;j++){
				int s2=max(b[i],b[n])+b[n];
				for(int p=0;p<=n-i-j;p++){
					int s3=max(c[i],c[n])+c[n];
					sum=s1+s2+s3;
				}
			}
			
		}
		cout<<sum<<endl;
	}
	fclose(stdin); 
	fclose(stdout);
	return 0;
}