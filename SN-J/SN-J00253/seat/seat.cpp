#include<iostream>
using namespace std;
int s[110];
int main()
{
	freopen("seat2.in","r",stdin);
	freopen("seat2.out","w",stdout);
	
	int n,m,tot=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n*m;i++){
			if(s[1]<s[i]) tot++;
		
	}
	if(tot<n) cout<<1<<" "<<(1+tot)<<endl;
	else{
		if(tot>=n){
			if(((tot+1)/n)%2==0){
				cout<<1+((tot+1)/n)<<" "<<(tot+1)%n;
		}
		else cout<<1+((tot+1)/n)<<" "<<n-(tot%n);
	}
	}
	return 0;
}
