#include<bits/stdc++.h>
string namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,a[5000],x=0,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		x=a[1]+a[2]+a[3];
		if(2*a[3]<x)  cout<<1<<endl;
		else  return 0;
	}
	for(l=3;l<=n;l++){
		for(r=l+2;r<=n;r++){
			for(int i=l;i<=l;i++){
				x+=a[i];
				if(m<a[i])  m=a[i];
			}
			if(x>2*m)  ans++;
			x=0;
			m=0;
		}
	}
	
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
