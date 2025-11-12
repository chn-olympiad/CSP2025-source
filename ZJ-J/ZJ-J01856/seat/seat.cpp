#include<bits/stdc++.h>
using namespace std;
int n,m;
int grade_R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>grade_R;
	int weici=1;
	for(int i=1;i<n*m;i++){
		int x;
		cin>>x;
		if(x>grade_R){
			weici+=1;
		}
	}
	int zu=weici/(2*n);
	if(weici%(2*n)!=0){
		zu+=1;
	}
	int ci=weici%(2*n);

	if(ci<=n && ci>0){
		cout<<zu*2-1<<" "<<ci;
	}
	else if(ci>n){
		cout<<zu*2<<" "<<2*n-ci+1;
	}
	else if(ci==0){
		cout<<zu*2<<" "<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
