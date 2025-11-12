#include<bits/stdc++.h>
using namespace std;
long long a[505],n,c,k,p[505],h[505],t,sum=0,f=0;
string s;
bool check(){
	long long h=0,t,flag=0;
	for(int i=1;i<=n;i++){
		if(n-h<k){
			flag=1;
			break;
		}
		if(p[i]<=h){
			h++;
		}
		else{
			t=s[i-1]-'0';
			if(t==0)h++;
		}
		
	}
	if(flag==0&&n-h>=k)return 1;
	else return 0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]>0)f=1;
		h[p[i]]++;
	}if(n>100){
		c=1;
		for(int i=1;i<=n;i++){
			if(p[i]==0)sum++;
		}n-=sum;
		for(int i=1;i<=n;i++){
			c*=i;
			c%=998244353;
		}cout<<c;
	}
	else {
		sort (p+1,p+n+1);
		if(check())c++;
		while(next_permutation(p+1,p+n+1)){
			//for(int i=1;i<=n;i++){
			//	cout<<a[i]<<" ";
			//}
			if(check())c++;
			c%=998244353;
		}for(int i=0;i<=n;i++){
			t=h[i];
			for(int j=1;j<=t;j++){
				c*=j;
				c%=998244353;
			}
		}
		cout<<c;
	}
	
	return 0;
}
