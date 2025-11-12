#include<bits/stdc++.h>
using namespace std;
struct node{
	int yi,er,san;
	int mx;
}a[1000000];
int n;
namespace in{
	void inp(){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].yi>>a[i].er>>a[i].san;
			if(a[i].yi>a[i].er and a[i].yi>a[i].san)a[i].mx=1;
			else if(a[i].er>a[i].san and a[i].er>a[i].yi)a[i].mx=2;
			else if(a[i].san>a[i].er and a[i].san>a[i].yi)a[i].mx=3;
		}
	} 
}
namespace teshuA{
	bool cmp(node a,node b){
		return a.yi>b.yi;
		
	}
	bool check(){
		for(int i=1;i<=n;i++){
			if(a[i].er!=0 or a[i].san!=0){
				return false;
			}
		}	return true;
	}void mmain(){
		int ans=0;
		sort(a+1,a+n+1,cmp);
		int maxn=n/2;
		for(int i=1;i<=maxn;i++){
			ans+=a[i].yi;
		}cout<<ans<<"\n";
	}
}
namespace teshuB{
	bool cmp(node a,node b){
		if(a.yi==b.yi)return a.er<b.er;
		else if(a.yi!=b.yi)return a.yi>b.yi;
	}bool cmp1(node a,node b){
		if(a.er==b.er)return a.yi<b.yi;
		else if(a.er!=b.er)return a.er>b.er;
	}bool check(){
		for(int i=1;i<=n;i++){
			if(a[i].san>0){
				return false;
			}
		}return true;
	}void mmain(){
		int ans=0;
		int maxn=n/2;
		int maxa=maxn,maxb=maxn;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=maxa;i++){
			ans+=a[i].yi;
			a[i].yi=0,a[i].er=0,a[i].san=0;
		}sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=maxb;i++){
			ans+=a[i].er;
			a[i].yi=0,a[i].er=0,a[i].san=0;
		}cout<<ans<<'\n';
	}
}
namespace baoli{
	bool cmp(node a,node b){
		int maxa=max(a.yi,max(a.er,a.san));
		int maxb=max(a.yi,max(a.er,a.san));
		return maxa>maxb;
	}
	void mmain(){
		int ans=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].mx==1){
				ans+=a[i].yi;
			}else if(a[i].mx==2){
				ans+=a[i].er;
			}else if(a[i].mx==3){
				ans+=a[i].san;
			}
		}cout<<ans<<'\n';
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		n=0;
		memset(a,0,sizeof(a));
		in::inp();
		if(teshuA::check()){
			teshuA::mmain();
		}else if(teshuB::check()){
			teshuB::mmain();
		}else{
			baoli::mmain();
		}
	}return 0;
}

/*
       ____              ____   ____   ____      /
     /    /  /    /    /      /      /    /     /
    /    /  /  /      /      /      /    /     /
   /____/  / /\      /      /____  /____/     /
  /    /  /    \    /           / /
 /    /  /     \   /____   ____/ /          .
 
kkksc03 请助我 ak csp！
luogu 请助我上人类迷惑行为！ 
（有没有发现这个和我J组t2的字符画一样？答案就是：） 
我的J组准考证号是 SD-J01509，欢迎参观那里的人类迷惑行为，编者们！
我的 luogu uid 是 1099109，欢迎关注，必定壶关！
对了，这是我的退役之战（或许吧），但愿不要 AFO。 
顺便，我能表达一个小小的请求吗？就是如果编者大佬们看到我的人类迷惑行为，
请别忘了把他记录到您们的文章里，我会来认领并感谢的！ 
*/
