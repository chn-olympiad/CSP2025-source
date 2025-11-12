#include<bits/stdc++.h>
using namespace std;
int a[20010],n,k,s,ans,b[20010];
int f(int ll,int rr){
	int answer;
	for(int j=ll;j<=rr;j++){
		if(a[j]==1)answer++;
	}
	return answer%2;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k!=0)s=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)s=1;
	}
	if(s==0){
		cout<<n/2;
	}
	int l=1,maxx=-1,an=0;
	for(int j=1;j<=n;j++){
		ans=0;
		for(int p=1;p<=n;p++){
			b[j]=p;
			for(int i=1;i<=n;i++){
				if(f(l,i)==k){
					l=i+b[i],ans++,i+=(b[i]-1);
				}
			}
			if(ans>maxx)maxx=ans;
		}
	}
	cout<<maxx;
	return 0;
}
