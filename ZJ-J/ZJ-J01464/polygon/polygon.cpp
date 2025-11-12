#include<bits/stdc++.h>
#define mod 998244353
#define int long long
//10:03-11:48,WA,hope score is 12
//242points 2=
using namespace std;
int arr[5010];long long jc[5050];int A[5050][5050];
signed main(){
	//freopen("polygon.in","r",stdin);oplygon ploygon poylgon polgyon polyogn polygno
	//freopen("polygon.out","W",stdout); feropen() froepen() frepoen() freoepn() feropne() rfeopen()
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","W",stdout);
	int n;
	cin>>n;
	int maxai=0;
	int sumai=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		maxai=max(maxai,arr[i]);
		sumai+=arr[i];
	}
	if(maxai<=1){ 	
		for(int i=1;i<=n;i++){
			A[i][1]=i;
		}
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				A[i][j]=A[i][j-1]*(i-j+1);
			}
		}
		return 0;
		
	}else{
		if(sumai>maxai*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	
	return 0;
}
   
         