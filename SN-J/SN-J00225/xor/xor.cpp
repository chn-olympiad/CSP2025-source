//XTBT    
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=1e9+7;
const int maxn=5e5+5;
int n,m,t,k;
int a[maxn];
int b[maxn];
map<int,int>mp;
//9:34
//成FW了，1h未能AT3
//9:46
//唐了，貌似想出解法了，不会树状数组了qwq
//后悔昨晚没复习了qwq 
//树个* 
//假了qwq 
//唐了真假了
//假个*，除了k=0都过了
//滚去特判 
//~~完了不会写特判~~
//试图不特判把正解炸了，sweet
//话说应该没人做SN迷惑行为大赏吧…… 
//10:20
//应该能A吧，真成FW了，一道橙题做50min 
//有概率挂20pts 
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=b[i-1]^a[i];
//	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
//	cout<<endl; 
	int num=0;
	int ans=0;
if(k==0){
	for(int i=1;i<=n;i++){
		int sum=b[i]^b[num];
		mp[sum]++;
		if(sum==k){
			ans++;
			mp.clear();
			num=i;
			continue;
		} 
		int tot=k^sum;
		if(mp[tot]>1){
			ans++;
			mp.clear();
			num=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
	for(int i=1;i<=n;i++){
		int sum=b[i]^b[num];
		mp[sum]++;
		if(sum==k){
			ans++;
			mp.clear();
			num=i;
			continue;
		} 
		int tot=k^sum;
//		cout<<i<<" "<<num<<" "<<tot<<endl;
		if(mp[tot]){
			ans++;
			mp.clear();
			num=i;
		}
	}
	cout<<ans<<endl;
	
	
	return 0;
}

