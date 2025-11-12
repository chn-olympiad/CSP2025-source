#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const long long N=5e6+6;
long long n,m;
string sa,sb;
struct node{
	long long qian,hou;
	long long cha;
}a[N];
string ta,tb;
long long ans;
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sa>>sb;
		for(int j=0;j<sa.length();j++){
			if(sa[j]=='b')
				a[i].qian=j,a[i].hou=sa.length()-j-1;
		}
		for(int j=0;j<sb.length();j++){
			if(sb[j]=='b')
				a[i].cha=j-a[i].qian;
		}
	}
	if(m==1){
		cin>>ta>>tb;
		cout<<0;
		return 0;
	} 
	for(int i=1;i<=m;i++){
		ans=0;
		cin>>ta>>tb;
		node t;
		for(int j=0;j<ta.length();j++){
			if(ta[j]=='b')
				t.qian=j,t.hou=ta.length()-j-1;
		}
		for(int j=0;j<tb.length();j++){
			if(tb[j]=='b')
				t.cha=j-t.qian;
		}
		for(int i=1;i<=n;i++)
			if(t.qian>=a[i].qian&&t.hou>=a[i].hou&&t.cha==a[i].cha) ans++;
		cout<<ans<<"\n";
	}
	return 0; 
} 
