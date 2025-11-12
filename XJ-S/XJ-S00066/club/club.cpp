#include<bits/stdc++.h>
using namespace std;
long long a[100010];
bool maxn(long long a,long long b,long long c){
	if(a>b>c){
		return 1;
	}else if(b>a>c){
		return 2;
	}else if(c>b>a){
		return 3;
	}
}
bool big(long long s,long long ss,long long sss){
	if(s>ss>sss){
		return s;
	}else if(ss>s>sss){
		return ss;
	}else if(sss>ss>s){
		return sss;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n,t;
	long long a1=0,a2=0,a3=0;
	long long num=0;
	cin>>t>>n;
	for(int i=1;i<=t;i++){
		for(int j=2;j<=n;j++){
			cin>>a[i];
			maxn(a[i],a[i+1],a[i+1+n]);
			if(a[i]==1){
				a1++;
			}else if(a[i]==2){
				a2++;
			}else if(a[i]==3){
				a3++;
			}
			if(n/2>=a1||n/2>=a2||n/2>=a3){
				num=num+big(a[i],a[i+1],a[i+1+n]);
			}
		}
		cout<<num;
	} 
	return 0;
} 
