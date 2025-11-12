#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int a[maxn],n,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<3){
		cout<<ans<<endl;
		return 0;
	}else{
		if(n==3){
			sort(a+1,a+1+n);
			if(a[1]+a[2]>a[3])ans++;
			cout<<ans<<endl;
			return 0;
		}else{
			for(int i=1;i<=n;i++)
			for(int j=i+2;j<=n;j++){
				int Max=-(1<<30),sum=0;
				for(int c=i;c<=j;c++)sum+=a[c],Max=max(Max,a[c]);
				if(Max*2<sum)ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
