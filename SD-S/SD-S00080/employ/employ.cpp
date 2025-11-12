#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],b[501],p[501],ss;
long long c[501],ans;
string s;
void hi(int x){
	if(x>n){
		int sss=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||a[p[i]]<=sss)
				sss++;}
		if(n-sss>=m){
			ans++;}
		return;}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			c[i]=1;
			p[x]=i;
			hi(x+1);
			c[i]=0;}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			ss++;
			for(int j=1;j<=n;j++){
				if(a[j]==ss)
					b[j]=i+1;}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]>ss)
			b[i]=n;}
	if(n<=10){
		hi(1);
		cout<<ans;
		return 0;}
	if(ss==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)
				ss++;}
		ans=1;
		for(int i=1;i<=n-ss;i++){
			ans*=i;
			ans%=998244353;}
		cout<<ans;
		return 0;}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
