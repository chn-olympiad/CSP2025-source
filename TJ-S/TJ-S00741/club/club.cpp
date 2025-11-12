#include <bits/stdc++.h> 
using namespace std;
int n,t,s1,s2,s3,s;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		s=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s1>>s2>>s3;
			s+=max(s1,max(s2,s3));
		}
		cout<<s<<endl;
	}
	return 0;
}
