#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);//1+1=3我不会 
	freopen("xor.out","w",stdout);//服了，8点半才开始12点整收卷，30分钟被吃了 
	int a[500005],n,k,ans=0,jg=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int oi=i;oi<n;oi++){
			jg=a[i];
			for(int oo=i;oo<oi;oo++)jg=jg|a[oo];
			if(jg==k){
				ans++;
				i=oi;
			}
		}
	}
	cout<<ans;
	return 0;
}
