#include<bits/stdc++.h>
using namespace std;
int n,cnt,maxx;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		if(a[i]>maxx){
			maxx=a[i];
		}
	} 
	if(cnt>2*maxx){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
