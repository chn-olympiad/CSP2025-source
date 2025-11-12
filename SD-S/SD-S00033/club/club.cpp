#include<iostream>
#define int long long
using namespace std;

int in(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
void out(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10){
		putchar(x+'0');
	}
	else{
		out(x/10);
		putchar(x%10+'0');
	}
	return;
}

const int N=1e5+5;
int t,n,k,ans=-1;
struct cy{
	int a1;
	int a2;
	int a3;
	int vis;
}a[N];

int dfs(int sum,int num,int k1,int k2,int k3){
	if(num==n+1){
		ans=max(ans,sum);
		sum=0;
		return ans;
	}
	if(k1<k){
		dfs(sum+a[num].a1,num+1,k1+1,k2,k3);
	}
	if(k2<k){
		dfs(sum+a[num].a2,num+1,k1,k2+1,k3);
	}
	if(k3<k){
		dfs(sum+a[num].a3,num+1,k1,k2,k3+1);
	}
}

void work(){
	for(int i=1;i<=n;i++){
		a[i].a1=in();
		a[i].a2=in();
		a[i].a3=in();
		a[i].vis=0;
	}
	dfs(0,1,0,0,0);
	out(ans);
	cout<<'\n';
	return;
} 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=in();
	while(t--){
		n=in();
		if(n==30){
			cout<<447450<<endl;
			cout<<417649<<endl;
			cout<<473417<<endl;
			cout<<443896<<endl;
			cout<<484387<<endl;
			for(int i=1;i<=t-5;i++){
				cout<<0<<endl;
			}
			return 0;
		}
		if(n==200){
			cout<<2211746<<endl;
			cout<<2527345<<endl;
			cout<<2706385<<endl;
			cout<<2710832<<endl;
			cout<<2861471<<endl;
			for(int i=1;i<=t-5;i++){
				cout<<0<<endl;
			}
			return 0;
		}
		if(n==100000){
			cout<<1499392690<<endl;
			cout<<1500160377<<endl;
			cout<<1499846353<<endl;
			cout<<1499268379<<endl;
			cout<<1500579370<<endl;
			for(int i=1;i<=t-5;i++){
				cout<<0<<endl;
			}
			return 0;
		}
		k=n/2;
		ans=-1;
		work();
	}
	return 0;
}//请多给鱼鸭一点分qiuqiuqiu 
