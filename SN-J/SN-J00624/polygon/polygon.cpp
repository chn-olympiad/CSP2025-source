#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N],sum,maxx=INT_MIN,s[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=a[i]+s[i-1];
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	if(n==3){
		if(sum>2*maxx) cout<<1;
		else cout<<0;
	}else if(maxx==1){
		cout<<0;
	}else{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(s[i]-s[j-1]>2*a[max(i,j)]) ans++;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}
