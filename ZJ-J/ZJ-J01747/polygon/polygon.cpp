#include<bits/stdc++.h>
using namespace std;
long long n,a[50001],s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];	
			s+=a[i];
		}
		if(s>2*a[1]&&s>2*a[2]&&s>2*a[3])cout<<1;
		else cout<<0;
	}
	else if(n<3)cout<<0;
	else {
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=i;j++){
				s+=j;
			}
		}
		cout<<s;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
