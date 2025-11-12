#include<bits/stdc++.h>
using namespace std;
const int Maxn=5e5+7;
int n;
bool only_zero_and_one=1;
unsigned int a[Maxn],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!(a[i]==0||a[i]==1))only_zero_and_one=0;
	}
	if(only_zero_and_one&&k==0){
		int cnt=0,t=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt+=t/2+1,t=0;
			else{
				t++;
			}
			
		}
		cnt+=t/2;
		printf("%d",cnt);
		return 0;
	}
	int cnt,minn=INT_MAX;
	for(int i=1;i<=20;i++){
		cnt=0;
		int t=0;
		int goal=(k>>(i-1))&1;
		for(int j=1;j<=n;j++){
			t^=(a[j]>>(i-1))&1;
			if(t==goal){
				t=0;
				cnt++;
			}
		}
		minn=min(minn,cnt);
	}
	printf("%d",minn);
	return 0;
}
