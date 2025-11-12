#include<bits\stdc++.h>
using namespace std;
int a[2000];
int b[2000];
int c[2000];
int t;
int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
while(t--){
	int n;
	cin>>n;
	int a1=0,b1=0,c1=0,ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];	
	}
	sort(a+0,a+n+1);
	sort(b+0,b+n+1);
	sort(c+0,c+n+1);
	for(int i=0;i<n;i++){
		if(a1+1<=n/2){
			ans=a[n];
			a[n]=0;
			a1++;
		}
	else if(b[n]>c[n]){
		if(b1+1<=n/2){
			ans=b[n];
			b[n]=0;
			b1++;
	
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
}
}
}
}

