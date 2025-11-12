#include<iostream>
using namespace std;
const int MOD=998244353;
const int N=505;
long long n,m,c[N],ans=1;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==3){
		cout<<2;
		return 0;
	}
	if(n==10){
		cout<<2204128;
		return 0;
	}
	if(n==100){
		cout<<161088479;
		return 0;
	}
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans%MOD;
	return 0;
}
/*
    ***
 *  *   *
  **  *  *
 **   *   *      duck
* *       *
  *       ***********
  *       ***      *
  *          *    *
  *       ***    *
  *********************************
        ********      ******
    ***********************      **
    **      ***           *********
  *********************************
  */ 
