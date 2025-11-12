#include <bits/stdc++.h>
using namespace std;
long long a[111111],n,num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.in","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]+a[j]>a[k]) num++;
			}
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
