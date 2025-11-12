#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[5005],js=0;
	cin>>n;
	long long c=0,op=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c+=a[i];
		op=max(op,a[i]);
	}
	if(c>op*2) js++;
	long long mox=-1,he=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j+=i){
			for(int k=1;k<=n;k++){
				if(j==1 && k>=j+i && k>=3 || k<=j-i && k>=j+i && k>=3 || j==n && k<=j-i && k>=3){
					he+=a[k];
					mox=max(mox,a[k]);
				}
			}
			if(he>mox*2){
				js++;
			}
		}
	}
	cout<<js%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

