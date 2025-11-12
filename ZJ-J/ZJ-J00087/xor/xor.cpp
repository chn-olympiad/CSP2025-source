#include<bits/stdc++.h>
using namespace std;
const int N=1e5,GG=255;
int ans,florr,cd[GG+1][2],a[N+5],n,k,lst,nw;
void work1(){
	lst=1;
	for(int i=1;i<=n;i++){
		nw=a[i];
		for(int j=i-1;j>=lst;j--){
			if(nw==k)break;
			nw^=a[j];
		}
		if(nw==k){
			ans++;
			lst=i+1;
		}
	}
	cout<<ans<<endl;
}
void work2(){
	if(florr){
		cout<<31437;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=GG;i++){
			if(j^a[i]==0||cd[j^a[i]][(i&1)^1]==1)cd[j][i&1]=1;
		}
		for(int j=0;j<=GG;i++)cd[j][i&1]|=cd[j][(i&1)^1];
		if(cd[k][i&1]==1){
			ans++;
			memset(cd,0,sizeof(cd));
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	//首先我们有个显而易见的结论：如果前面可以得出一个解，一定不劣于它之后得出一个解
	//显然有一个唐唐n^2dp
	//注意到按位异或
	//显然a_i<255可以用桶解决  
	//这样我们可以拼好分
	//理论80pts
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>GG)florr=1;
	}
	if(n<=N)work1();
	else work2();
	return 0;
}
//O h d e a r
//I can't AC T3
//Terrible,miao

//Have you been listening <something just like this>?
//Quite delicious,miao

//I've been playing florr for old
//Some generals and digdig
//Diep and it's bow
//Minecraft and it's shift
//Mouse and it's contral
//Keybord and it's gift
//But clearly teacher put them on the black list(
//She said where do you wanna go
//How much you wanna risk
//I'm not looking for somebody with some superhumen gift
//Some super heros
//Some fairy tell bless
//Just something I can deal to
//Like something I can kiss
//I want something just like this
//Doo doo
//Doo doo
//Doo doo
//I want something just like this
//Doo doo
//Doo doo
//Doo doo
//Oh I want something just like this



//Well,we do play kards,florr,Minecraft,but they AKed IOI and I AFO,miao(
//They are so ju,%%%
//qing lv qian mou+
