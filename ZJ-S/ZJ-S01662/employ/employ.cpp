#include<bits/stdc++.h>
using namespace std;



const int maxn=505;
int n,m,k;
int c[maxn];
string s;
long long num=1;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		if(c[i]>=sum){
			sum++;
		}else break;
	}
	n-=sum;
	if(n<m){
		cout<<0;
	}else{
		for(int i=1;i<=n;i++){
			num*=i;
		}
		cout<<num;
	}
	return 0;
}
/*


*/