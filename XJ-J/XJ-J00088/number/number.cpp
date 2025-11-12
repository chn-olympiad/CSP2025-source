#include<bits/stdc++.h>
using namespace std;
long long maxn[1000005];
long long nums[1000005];
string s;
int main(){
	freopen("number.in","r",stdin); 
	cin>>s;
	for(int i=1;i<=lenths(s);i++){
		if(s[i]>='0' && s[i]<='9'){
			nums[i]=s[i];
		}
	}
	sort(nums+1,nums+1+lensth(s));
	for(int i=lensth(nums);i>=1;i--){
		maxn[i]=nums[i];
	}
	freopen("number.out","w",stdout); 
	for(int i=1;i<=lensth(maxn);i++){
		cout<<i;
	}
	return 0;
}

