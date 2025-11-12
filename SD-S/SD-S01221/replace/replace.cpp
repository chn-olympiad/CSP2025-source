#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
pair<int,int> s[400010];
int read(){
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	int sum=0;
	while(c>='0'&&c<='9'){
		sum=(sum<<1)+(sum<<3)+(c-'0');
		c=getchar();
	}
	return sum;
}
pair<int,int> readst(){
	char c=getchar();
	while(c<'a'||c>'z') c=getchar();
	int sum=0,flag;
	while(c>='a'&&c<='z'){
		if(c=='b') flag=sum;
		sum++;
		c=getchar();
	}
	return make_pair(flag,sum);
}
void write(int res){
	if(res==0) return ;
	write(res/10);
	putchar(res%10+'0');
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		s[i*2-1]=readst();
		s[i*2]=readst();
	}
	while(q--){
		int ans=0;
		pair<int,int> t1=readst(),t2=readst();
		for(int i=1;i<=n;i++){
			if(s[i*2-1].first<t1.first&&t2.second-t2.first>s[i*2].second-s[i*2].first&&s[i*2].first-s[i*2-1].first==t2.first-t1.first) ans++;
		}
		if(ans!=0) write(ans);
		else putchar('0');
		putchar('\n');
	}
	return 0;
}
