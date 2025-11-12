#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 20001
#define mod 998244353
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0'; ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int n;
int ans=0;
int a[maxn];
int f[maxn]={0}; //>5000 is special
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	f[0]=1;
	for(int i=1;i<=n;i++){
		int res=0;
		for(int j=a[i]+1;j<=5001;j++)res+=f[j],res%=mod;
		ans+=res;  ans%=mod;  f[5001]*=2; f[5001]%=mod;
		for(int j=5000;j>=5001-a[i];j--)f[5001]=(f[5001]+f[j])%mod;
		for(int j=5000;j>=a[i];j--)f[j]=(f[j]+f[j-a[i]])%mod;
	}
	write((ans%mod+mod)%mod); cout<<'\n';
	return 0;
}
/* 9:40 AK 
Participant Reflection:
The difficulty rate of the exam is disgusting,why I paid 310 rmb for this extrmely easy exam?
I surely predict that the 1 = line will lie at 400pts in explain of the low difficulty rate.
Because I have AK this exam and hold too much time,I decide to write editorials for this contest.
Problem 1:number
Rate Prediction: red
It's easy to find that every number in the string is useful because the problem guarunteed that there exists at least one number from 1 to 9,
in that case,put the bigger number ahead to make the biggest number,the algorthim is greedy.
Problem 2:seat
Rate Prediction: red
I don't know why the problem provider had exceeded both n,m no bigger than 10.
It's obviois that you need to input n*m numbers in total so you have to save time for inputing,but in my perspective,the range of n,m
could be lift up to 10000 because the const number of the code is too small.
First,put the inputed numbers into the structs and then use customized sorting fuction to sort them in the decreasing order,then find the rank
of our character,by easy calculation of maths,you'll truly get the position.
Algorthim ? No algorthims !
Problem 3:xor
Rate Prediction: orange
To solve this problem,you need to firstly notice that xor is also the opposite calculation of itself.
So that the xor sum of [l,r] becomes the xor of qz[r] and qz[l-1]
We calculate the prefix xor sums,and could use dynamic programming to solve it easily.
And to better speed it up,use g_i to record the max number where the positon's val is i.
Time Complexion: O(n)
Algorhthim:predix,dp.
Problem 4:polygon
Rate Rrediction: orange
It's easy to have O(n^3) dp because the maximum of a_i and n is 5000.
But it will be too difficult to get through.
We noticed that the maximum of a_i if 5000,and the pending way is to sum the f[i] where i > a_i.
So we just need to record the ways where i<=5001
Especailly f[5001] represents all the f[i] where i>5000.
We just need to dp it for solving.
Time Complexion: O(n^2).
Algorthim:dp,adhoc(Probably not).
Elysia !!!!!!!!!!!!!!!!!!!!!!
I love Elysia forever !!!!!!!!!!!!!!!!!!!!!!
I hate whk !!!!!!!!!!!!!!!!!!!!!!!!!
My dream locates in zju !!!!!!!!!!!!!!!!!
*/
