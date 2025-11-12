#include<bits/stdc++.h>
using namespace std;
int n,m,s=1,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			s++;
		}
	}
	int s1=s/m;
	int s2=s%m;
	if(s2!=0){
		s1++;
	}else{
		s2=n;
	}
	if(s1%2==1){
		cout<<s1<<" "<<s2<<"\n";
	}else{
		cout<<s1<<" "<<m-s2+1<<"\n";
	}
	return 0;
}
