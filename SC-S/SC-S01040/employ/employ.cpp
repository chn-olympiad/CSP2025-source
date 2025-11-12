#include<bits/stdc++.h>
using namespace std;

const int M=998244353;
const int N=1000;

int n,m;
int a[N];//耐心 
long long b[N];//全排列 
string s,s1;
int ans=0;
int book[N];

void dfs(int x,int num,int cnt){//第num个位置放x 统计了cnt个 放弃的就是num-cnt 
//			for(int i=1;i<=n;i++) cout << book[i] << " ";
//	cout << "cnt=" << cnt;cout << '\n';
	if(num==n){
		if(cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){//还没有被访问 
			book[i]=1;
			if(a[i]>(num-cnt)&&s[i-1]=='1'){//能够承受并且简单 统计起来 
				dfs(i,num+1,cnt+1);
			}else{
				dfs(i,num+1,cnt);
			}
			book[i]=0;
		}
	}
}


int main(){
	freopen("employ.in ","r",stdin);	
	freopen("employ.out ","w",stdout);	
	cin >> n >>m;
	cin >> s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==0) cnt++; 
		s1=s1+'1';
	}
	b[1]=1;
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]*i%M;
	}
	
	if(s==s1) cout << b[n-cnt] << '\n';
	else if(m==n){
		if(s!=s1) cout << 0 << '\n';
	}
	else{
//		s=' '+s;
//		cout << s; 
		for(int i=1;i<=n;i++){
			book[i]=1;
			if(a[i]==0||s[i-1]=='0') dfs(i,1,0);
			else dfs(i,1,1);
			book[i]=0;
		}
		cout << ans-1;
	}
	return 0;
}
//3 2
//101
//1 1 2
//
//10 5
//1101111011
//6 0 4 2 1 2 5 4 3 3
//2204128

