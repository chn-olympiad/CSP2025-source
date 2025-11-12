//姓名：杜悦菲
//考号：SN-J00594
//学校：西安市曲江第一学校

#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//仅处理测试点1，因为其他的我不会QAQ
	int n,k;
	cin>>n>>k;
	if((n<=2)&&(k==0)) {
		if(n==1) {
			int a;
			cin>>a;
			if(a!=k) {
				cout<<0;
				return 0;
			} else {
				cout<<1;
				return 0;
			}
		} else {
			int a,b;
			cin>>a>>b;
			int cnt=0;
			if(a==k)cnt++;
			if(b==k)cnt++;
			if(a^b==k)cnt++;
			cout<<cnt;
			return 0;
		}
	}
	return 0;
}
