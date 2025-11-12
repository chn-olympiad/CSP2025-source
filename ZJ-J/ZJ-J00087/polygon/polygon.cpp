#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e4+1,mod=998244353;
int a[N+5],t[N+5],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	t[0]++;
	t[a[1]]++;
	t[a[2]]++;
	t[a[1]+a[2]]++;
	for(int i=3;i<=n;i++){
//		for(int j=0;j<=N;j++)cout<<t[j]<<' ';
		for(int j=a[i]+1;j<=N;j++)ans+=t[j],ans%=mod;
		for(int j=N;j>=0;j--){
			if(j+a[i]>=N)t[N]+=t[j],t[N]%=mod;
			else t[j+a[i]]+=t[j],t[j+a[i]]%=mod;
		}
//		cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
//O(n^2) tai da,guo bu liao 5e4,zen mei ban miao
//suan la,AC T4 hui ying lai P hua ge(
//hai shi yi han li chang ba
//bu zhi bu jue,yi jing yao AFO le miao
//hai mei shang guo mi huo xing wei da shang,xi wang zhe ci neng shang miao

//Goodbye OI
//Goodbye CSP
//I loved OI
//OI don't love me
//I loved CSP
//CSP AK me
//This is my story
//This is my dream
//To AK IOI
//Not by JCing
//Goodbye lougu
//For chao ji ma li
//Goodbye moxiong
//With nai long not for me
//And I'll be AFO
//I don't have choices to be
//The one that I loved
//And the one that I dreamed

//By yzc001,miao

//zhu everyone saw this:
//CSP 2025 rp++!

