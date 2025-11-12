#include<bits/stdc++.h>
#define int long long
#define mp(a,b) make_pair(a,b)
using namespace std;

inline int read(){
	int a=0,b=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	b=-1;
		c=getchar();
	}
	while(isdigit(c)){
		a=(a<<1)+(a<<3)+(c-'0');
		c=getchar();
	}
	return a*b;
}
inline void write(int x){
	if(x<0)	putchar('-'),x=-x;
	if(x>=10)	write(x/10);
	putchar(x%10+48); 
}
inline void write1(int x){
	write(x),putchar(' ');
}
inline void write2(int x){
	write(x),putchar('\n'); 
}
const int N=3*114514;
int n;
int a[N],b[N],c[N];
int cho[N];	//代表这里的选取结果  
int A,B,C;
void solve(){
	n=read();
	A=B=C=0;
	int include13=0;
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read(),c[i]=read();
		if(a[i]>=b[i]&&a[i]>=c[i]){
			cho[i]=1,A++,include13+=a[i];
		} 
		else if(b[i]>=a[i]&&b[i]>=c[i]){
			cho[i]=2,B++,include13+=b[i];
		}
		else{
			cho[i]=3,C++,include13+=c[i];
		}
	}
	if(A<=(n/2)&&B<=(n/2)&&C<=(n/2)){
//		cout<<"谭总的世界-033"<<endl;
		write2(include13);
		return;
	}
	priority_queue<int> q;
	if(A>(n/2)){
//		cout<<"谭总的世界-056"<<endl;
		int sum=A-(n/2);
		for(int i=1;i<=n;i++){
			if(cho[i]==1){
				q.push(-(a[i]-max(b[i],c[i])));
			}
		} 
		while(sum--){
			int now=q.top();
			q.pop();
			include13+=now;
		}
		while(!q.empty())	q.pop();
	}
	else if(B>(n/2)){
//		cout<<"谭总的世界-071"<<endl;
		int sum=B-(n/2);
		for(int i=1;i<=n;i++){
			if(cho[i]==2){
				q.push(-(b[i]-max(a[i],c[i])));
			}
		}
		while(sum--){
			int now=q.top();
			q.pop();
			include13+=now;
		}
		while(!q.empty())	q.pop();
	}
	else{
//		cout<<"谭总的世界-095"<<endl;
		int sum=C-(n/2);
		for(int i=1;i<=n;i++){
			if(cho[i]==3){
				q.push(-(c[i]-max(a[i],b[i])));
			}
		}
		while(sum--){
			int now=q.top();
			q.pop();
			include13+=now;
		}
		while(!q.empty())	q.pop();
	}
	write2(include13);
	return;
}
#undef int
int main(){
	#define int long long
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)	solve();
	putchar('\n');
	return 0;
} //CSP-S 2025 RP++ 