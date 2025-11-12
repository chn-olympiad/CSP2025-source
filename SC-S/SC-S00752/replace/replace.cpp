#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,q,a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		a[i]=0;
		b[i]=0;
		for(int j=0;j<s1.size();j++){
			a[i]+=int(s1[i]);
			b[i]+=int(s2[i]);
		}
	}
	long long ans=0;
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		long long cnt=0,cnt1=0;
		for(int j=0;j<s1.size();j++){
			cnt+=int(s1[i]);
			cnt1+=int(s2[i]);
		}
		if((max(cnt,a[i])-min(cnt,a[i]))%(max(cnt1,b[i])-min(cnt1,b[i]))==0){
			cout<<0<<endl;
			continue;
		}else{
			ans++;
		}
		cout<<ans<<endl;
	}
} 