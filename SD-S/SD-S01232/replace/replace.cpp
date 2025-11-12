#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	string s1,s2;
	long long a[10004],b[10004];
	long long l[10004]=0;
	for(long long i=1;i<=n;i++){
		cin>>s1>>s2;
		l[i]=strlen(s1);
		for(long long j=0;j<=strlen(s1);j++){
			if(s1[j]=='b') break;
			a[i]++;
		}
		for(long long j=0;j<=strlen(s1);j++){
			if(s2[j]=='b') break;
			a[i]--;
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>s1>>s2;
		if(strlen(s1)!=strlen(s2)){
			cout<<'0'<<endl;
			continue;
		}
		for(long long j=0;j<=strlen(s1);j++){
			if(s1[j]=='b') break;
			b[i]++;
		}
		for(long long j=0;j<=strlen(s2);j++){
			if(s2[j]=='b') break;
			b[i]--;
		}
		long long ans=0;
		for(long long j=1;j<=n;j++){
			if(b[i]==a[i]&&l[j]<=strlen(s1)) ans++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

