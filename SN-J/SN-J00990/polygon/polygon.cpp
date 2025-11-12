//谢翔宇 西安市曲江第一学校 SN-J00990 
#include<bits/stdc++.h> 
using namespace std;
const int N=1e4+10;
string s;
int a[N],n,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=-1;
	for(int i=1;i<=n;i++)
		maxn=max(maxn,a[i]);
	if(maxn=1){
		cout<<(n-3)*(n-2)%99824435;
		return 0;
	}
		
	if(maxn>1&&maxn<=10){
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
		if(sum>2*maxn){
			cout<<1;
			return 0;
		}
	}
	
	return 0;
}
