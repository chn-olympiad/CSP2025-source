#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
bool Men;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

const int N=25;

int cnt[N];

bool Mbe;
signed main(){
//	printf("%.8lfMB\n",(&Mbe-&Men)/1000000.0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//freopen("
//	freopen("number4.in","r",stdin);
//	freopen("test.ans","w",stdout);
	string s;cin>>s;
	
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[(int)(s[i]-'0')]++;
		}
	}
	
	for(int i=9;i>=0;i--){
		while(cnt[i]--) cout<<i;
	}
	cout<<endl;
	
	
	return 0;
} 
