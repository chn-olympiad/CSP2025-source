/*
#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
// #define int long long
using namespace std;
int s[500010],top;
pair<int,int> a[1000010];
bool cmp(pair<int,int> x,pair<int,int> y){
	return (x.fi==y.fi?x.se<y.se:x.fi<y.fi);
}
int main(){
    freopen("xor3.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		s[i]=s[i-1]^x;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				a[++top]={i,j};
			}
		}
	}
	sort(a+1,a+top+1,cmp);
	for(int i=1;i<=top;i++){
		cout<<a[i].fi<<" "<<a[i].se<<endl;
	}
	//I forget how to solve this part.
//	cout<<(s[n]^s[1])<<endl;
    return 0;
}
*/
#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k,cnt1=0;
	cin>>n>>k;
	bool all1=1,allb=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			all1=0;
		}
		if(a[i]>1){
			allb=0;
		}
		if(a[i]==1){
			cnt1++;
		}
	}
	if(all1){
		cout<<n/2<<endl;
		return 0;
	}
	if(allb){
		if(k==0){
			cout<<max(n-cnt1,cnt1/2)<<endl;
		}else{
			cout<<cnt1<<endl;
		}
	}
	return 0;
}
//AFO.
//only pass "A" and "B" special test.
//only 30 pts.
//Why only 30 pts???
//65pts->30pts(I forgot how to solve a part)
//CSP-S rp++ QAQ