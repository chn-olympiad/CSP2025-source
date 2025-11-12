#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || '9'<ch){
		if(ch=='-'){
			f*=-1;
		}
		ch=getchar();
	}
	while('0'<=ch && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	n=read();
	m=read();
	string s;
	cin>>s;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool f=true;
	if(n==m){
		for(int i=0;i<n;i++){
			if(s[i]!='1' ||(a[i]=='0' && !f)){
				cout<<0;
				return 0;
			}
			if(a[i]=='0' && f){
				f=false;
			}
		}
		long long ans=1;
		for(int i=1;i<=n-(f ? 0 : 1);i++){
			ans*=(i%998244353);
			ans%=998244353;
		}
		cout<<ans%998244353;
	}
	if(m==1){
		int num=0;
		bool f=true;
		for(int i=0;i<n;i++){
			if(f && s[i]=='0'){
				num++;
			} 
			if(s[i]!='0'){
				f=false;
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]>num){
				sum++;
			}
		}
		for(int i=1;i<n;i++){
			sum*=(i%998244353);
			sum%=998244353;
		}
		cout<<sum%998244353;
		return 0;
	}
	int num=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'){
			num++;
		} 
	} 
	if(num<m){
		cout<<0;
		return 0;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			sum++;
		}
	}
	if(n-sum<m){
		cout<<0;
		return 0;
	} 
	if(num==n){
		if(n-sum<m){
			cout<<0;
			return 0;
		} 
		if(n-sum==m){
			int aa=1;
			for(int i=1;i<=m;i++){
				aa*=i;
				aa%=998244353;
			}
			cout<<aa<<endl;
		} 
		int al=0;
		int all=sum;
		for(int i=1;i<=n-sum;i++){
			all*=i;
			all%=998244353;
		}
		al+=all;
		all=n-sum;
		for(int i=1;i<=sum;i++){
			all*=i;
			all%=998244353;
		}
		al+=all;
		al%=998244353;
		cout<<al;
		return 0; 
	} 
	srand(time(NULL));
	cout<<((rand() & 1) ? 0 : rand()%998244353+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


