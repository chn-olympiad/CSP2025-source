#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,Num=(1<<21)+5;
int a[N],cnt[Num];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,k,num=0,p=0,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num^=a[i];
		if(cnt[num^k] || (num^k)==0){
			int tmp=0;
			for(int j=p+1;j<i;j++) tmp^=a[j],cnt[tmp]--;
			ans++,num=0,p=i;
		}
		else cnt[num]++;
	}
	cout<<ans<<endl;
	return 0;
}
