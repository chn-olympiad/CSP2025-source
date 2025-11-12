#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],sum,c=0,p=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
     cin>>n>>m;
     long long w=m;
     cin>>s;
     for(int i=1;i<=m;i++){
     	cin>>a[i];
	 }
	 for(int i=0;i<s.size();i++){
	 	if(s[i]==0) c++;
	 }
	 sort(a+1,a+m+1);
	 for(int i=2;i<=m;i++){
	 	if(a[i-1]==a[i]) w--;
	 }
	 if(c==0){
	 	for(int i=w;i<=n;i++){
	 		p*=i;
	 		p%=998224353;
		 }
		 cout<<p<<endl;
		 return 0;
	 } 
	return 0;
}
