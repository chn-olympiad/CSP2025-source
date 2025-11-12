#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long sum=0,num=0;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
			if(b[1]==0&&c[1]==0){
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;i--)
			sum+=a[i];      
			cout<<sum<<endl;
		}else{
			for(int i=1;i<=n;i++)
				num+=max(a[i],b[i]);   
				 cout<<num<<endl;     
			}
		}
			 return 0;
}