#include<bits/stdc++.h>
#define ei else if
#define ll long long
#define pend cout<<endl
//be alert to the problem of ambigiousness
using namespace std;

long long quick(ll a,ll b,ll modvalue){
	ll result=1;
	a%=modvalue;
	while(b>0){
		
		if(b%2==1){
			result=(result*a)%modvalue;
		}
		a=(a*a)%modvalue;
		b/=2;
	}
	return result;
}
unsigned int n,k,Li[500020];
bool ifzip=0;
int count_of_1=0,count_of_zip=0;
int main(){
	
	freopen("xor.in","r",stdin);//input
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>Li[i];
		if(Li[i]==1){
			
			count_of_1++;
		}
		ei(Li[i]==0){
			count_of_zip++;
			ifzip=1;
		}
	}
	
	
	
	
	freopen("xor.out","w",stdout);//output
	if(k==0){
		if(ifzip){
			
		cout<<count_of_zip;	
		}
		else cout<<n/2;
	}
	ei(k==1){
		if(ifzip){
			cout<<count_of_1;
		}
		else cout<<n;
	}
	return 0;
}
