#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fuck return
#define CCF 0
const int N=1e6+10;
int n,a[5010];
void CSP(){
	if(CCF=="dog") cout<<"CCf is a dog";
	if(CCF=="shit") cout<<"CCf is a piece of shit";
	if(CCF=="Collecting Coins Federation") cout<<"CCF is Collecting Coins Federation";
	cout<<"CCF is son of bitch.I hate CCF very much,I fuck CCF";	
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[1]+a[2]<=a[3]) cout<<0;
	else cout<<1;
	/*
	FFFFFFFFFFFFFFFFF			UUUUU				UUUUU			   CCCCCCCCCCC				KKKKK      KKKKK
	FFFFFFFFFFFFFFFFF			UUUUU				UUUUU			CCCCCCCCCCCCCCC			    KKKKK     KKKKK
	FFFFF						UUUUU				UUUUU          CCCCC						KKKKK    KKKKK
	FFFFF						UUUUU				UUUUU		  CCCCC							KKKKK   KKKKK
	FFFFF						UUUUU				UUUUU		  CCCCC 						KKKKK  KKKKK
	FFFFF						UUUUU				UUUUU		  CCCCC							KKKKK KKKKK
	FFFFFFFFFFFFFFFFF			UUUUU				UUUUU	   	  CCCCC							KKKKKKKKKK
	FFFFFFFFFFFFFFFFF			UUUUU				UUUUU		  CCCCC							KKKKK KKKKK
	FFFFF						UUUUU				UUUUU         CCCCC							KKKKK  KKKKK
	FFFFF						UUUUU				UUUUU         CCCCC							KKKKK   KKKKK
	FFFFF						UUUUU				UUUUU         CCCCC							KKKKK    KKKKK
	FFFFF					    UUUUU				UUUUU		   CCCCC						KKKKK     KKKKK
	FFFFF					       UUUUUUUUUUUUUUUUUUU				CCCCCCCCCCCCCCC				KKKKK      KKKKK
	FFFFF						     UUUUUUUUUUUUUUU				   CCCCCCCCCCC				KKKKK       KKKKK
	*/
	fuck CCF;
}
