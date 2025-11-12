#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct ey{
	string s1,s2;
};
ey s[100010];
struct que{
	string t1,t2;
};
que qu[100010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	for(long long i=0;i<n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	for(long long i=0;i<q;i++){
		cin>>qu[i].t1>>qu[i].t2;
	}
	for(long long i=0;i<q;i++){
		long long ans=0;
		for(long long j=0;j<n;j++){
			if(qu[i].t1!=s[j].s1) continue;
			else if(qu[i].t1==s[j].s1&&qu[i].t2==s[j].s2) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
