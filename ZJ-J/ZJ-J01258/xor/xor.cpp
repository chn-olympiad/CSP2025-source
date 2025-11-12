#include<bits/stdc++.h>
using namespace std;
bool now[30],sk[30],z[30];
int a[500010];
void s_xor(int o){
	int s=20;
	while(o){
		bool f=o%2;
		o/=2;
		if(now[s]==f)	now[s--]=0;
		else	now[s--]=1;
	}
}
bool check(){
	bool flag=1;
	for(int i=1;i<=20;i++){
		if(now[i]!=sk[i]){
			flag=0;
			break;
		}
	}
	return flag;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,l=1;
	cin>>n>>k;
	int s=20;
	int tk=k;
	while(tk){
		sk[s--]=tk%2;
		tk/=2;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k){
			l=i+1;
			ans++;
			memset(now,0,sizeof(now));
			continue;
		}
		s_xor(a[i]);
		if(check()){
			l=i+1;
			ans++;
			memset(now,0,sizeof(now));
			continue;
		}
		for(int j=1;j<=20;j++)	z[j]=now[j];
		bool flag=1;
		for(int j=l;j<i-1;j++){
			s_xor(a[j]);
			if(check()){
				flag=0;
				l=i+1;
				ans++;
				memset(now,0,sizeof(now));
				break;
			}
		}
		if(flag){
			for(int j=1;j<=20;j++)	now[j]=z[j];
		}
	}
	cout<<ans;
	return 0;
}
