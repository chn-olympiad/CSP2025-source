#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,t,ans;
struct stu{
	long long a=0,b=0,c=0;
};		
stu s[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			ans+=max(s[i].c,max(s[i].a,s[i].b));
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
