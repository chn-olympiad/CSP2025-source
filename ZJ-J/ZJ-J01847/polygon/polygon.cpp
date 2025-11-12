#include<bits/stdc++.h>
using namespace std;
int n,s[5010],cnt;
void d(long long xzsl,long long zh,long long zdz,long long sl){
	//选择的数量，    选择的总和,	选择的最大值，总数数量 
//	cout<< xzsl<<" "<<zh<<" "<<zdz<<" "<<sl<<"\n";
	if(sl==n){
		if(zh>zdz*2&&xzsl>=3){
			cnt=(cnt+1)%998244353;
		}
		return;
	}
	d(xzsl+1,zh+s[sl],s[sl],sl+1);
	d(xzsl,zh,zdz,sl+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n);
	d(0,0,0,0);
	cout<<cnt;
	return 0;
}  	
