#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++)cin>>a[i];
		
	int sr=a[1],tr;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i]==sr)tr=i;		
	int sum=n*m-tr+1;
	
	if(sum<=n)cout<<1<<" "<<sum;
	else{
		cout<<sum/n+1;
		if((sum/n+1)%2==1)cout<<" "<<sum%n;
		else cout<<" "<<n+1-sum%n;
	}
	
    fclose(stdin);
	fclose(stdout);
	return 0;
}	
