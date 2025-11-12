#include<bits/stdc++.h>
string namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k,a[500000],ans=0,l=0,r=0,m=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]==k){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
			return 0;
		}
	}
	for(l=1;l<=n;l++){
		for(r=l;r<=n;r++){
			for(int i=l;i<=l;i++){
				m+=a[i];
			}
			if(m==k)  ans++;
		}
	}
	 
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
