#include<bits/stdc++.h>
using namespace std;
int a[5005],sum,cnt,b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,maxn=0; 
	cin>>n;
	b=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
		sum+=a[i];
	    if(sum>2*maxn){
		    cnt++;
	    }
	} 
	if(n>3){
		cout<<2*n-1;
	}
	else{
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
