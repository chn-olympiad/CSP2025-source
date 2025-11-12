#include<iostream>
#include<algorithm>
#include<cmath>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<vector>
using namespace std;
long long a[500005];
long long s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,lastI=0,sum=0,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=lastI;j<i;j++){
			if((s[i]^s[j])==k){
				lastI=i;
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}

