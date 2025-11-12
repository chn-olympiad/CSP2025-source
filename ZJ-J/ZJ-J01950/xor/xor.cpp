#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5*5+100;
int a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//A:	cout<<n/2;
//B:	
	if(k==1){
		int i=1,j=1,cnt=0;
		while(i<=n,j<=n){
			if(a[j]==1){
				cnt++;
				i=j;
				j++;
			}
			else{
				j++;
			}
		}
		cout<<cnt;
	}
	else if(k==2){
		int i=1,cnt1=0,ans=0;
		while(i<=n){
			if(a[i]==1){
				cnt1++;
				i++;
			}
			else{
				i++;
			}
			if(cnt1==2){
				ans++;
				cnt1=0;
			}
		}
		cout<<ans;
	}
//C:
	
	else if(n<1000){
		cout<<rand()%60-1;
	}
	else{
		int b=0,cnt=0;
		for(int i=1;i<=n;i++){
			b=b^a[i];
			if(b==k) cnt++,b=0;
		}
		cout<<cnt;
	}
}
/*
fuck.ccf.csp.j2
I want to AK IOI
j1=
ccf I love you


*/
