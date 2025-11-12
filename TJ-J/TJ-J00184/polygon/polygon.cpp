#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);//1+1=3我不会 
	freopen("polygon.out","w",stdout);//服了，8点半才开始12点整收卷，30分钟被吃了 
	int n,a[5005],ans=0,zh;
	cin>>n;
	sort(a,a+n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n-2;i++){
		zh=a[i]+a[i+1];
		for(int ii=i+2;ii<n;ii++){
			zh+=a[ii];
			if(zh>a[ii]*2)ans++;
		}
	}
	cout<<ans;
	return 0;
}
