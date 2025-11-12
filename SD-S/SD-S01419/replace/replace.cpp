#include<bits/stdc++.h>
#define ll unsigned long long

using namespace std;
const int N=1e6+9;
int n,q;
multiset<ll> a;
ll decode(string s){
	ll sum=0;
	for(int i=0;i<s.size();i++){
		sum=sum*233+s[i];
	}
	return sum;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string t1,t2;
		cin>>t1>>t2;
		ll t3=decode(t1),t4=decode(t2);
		a.insert(t3-t4);
	}
	cout<<" ----\n";
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()==s2.size()){
			ll ans=0;
			ll s3=decode(s1),s4=decode(s2);
			ll o=s3-s4;
			ans+=a.count(o);
			while(o%233==0){
				o/=233;
				ans+=a.count(o);
			}
			cout<<ans<<"\n";
		}else{
			cout<<0<<"\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

