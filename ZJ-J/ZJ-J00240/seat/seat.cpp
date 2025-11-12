#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],n,m,a1,ansn,ansm;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	a1=a[1];
	int x=1;
	sort(a,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		
		if(a[i]==a1){
			break;
		}
		x+=1;
	}
	ansm=x/n;
	if(x%n!=0){
		ansm++;
		if(ansm%2==1){
			ansn=0+x%n;
			cout<<ansm<<" "<<ansn;
		}else {
			ansn=n+1-x%n;
			cout<<ansm<<" "<<ansn;
		}

	}else{
		if(ansm%2==1){
			cout<<ansm<<" "<<n;
		}else cout<<ansm<<" "<<"1";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}