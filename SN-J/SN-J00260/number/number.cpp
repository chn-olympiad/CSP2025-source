#include<bits/stdc++.h>
using namespace std;
string num,ans;
long long tmp=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>num;
	for(int i=0;i<num.size();i++){
		if(num[i]>='0'&&num[i]<='9'){
			ans[tmp]=num[i];
			tmp++;
		}
	}
	for(int i=0;i<tmp;i++){
		for(int j=0;j<i;j++){
			if(ans[j]<ans[i]){
				swap(ans[j],ans[i]);
			}
		}
	}
	for(int i=0;i<tmp;i++){
		cout<<ans[i];
	}
	return 0;
}

