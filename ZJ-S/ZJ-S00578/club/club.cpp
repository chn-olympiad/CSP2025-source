#include <bits/stdc++.h>
using namespace std;
struct node{
	int one,two,three;
};
bool cmp1(node x,node y){
	if(x.one==y.one){
		if(x.two==y.two)
			return x.three<y.three;
		return x.two<y.two;
	}
	return x.one<y.one;
}
bool cmp2(node x,node y){
	if(x.one==y.one){
		if(x.three==y.three)
			return x.two<y.two;
		return x.three<y.three;
	}
	return x.one<y.one;
}
bool cmp3(node x,node y){
	if(x.two==y.two){
		if(x.one==y.one)
			return x.three<y.three;
		return x.one<y.one;
	}
	return x.two<y.two;
}
bool cmp4(node x,node y){
	if(x.two==y.two){
		if(x.three==y.three)
			return x.one<y.one;
		return x.three<y.three;
	}
	return x.two<y.two;
}
bool cmp5(node x,node y){
	if(x.three==y.three){
		if(x.one==y.one)
			return x.two<y.two;
		return x.one<y.one;
	}
	return x.three<y.three;
}
bool cmp6(node x,node y){
	if(x.three==y.three){
		if(x.two==y.two)
			return x.one<y.one;
		return x.two<y.two;
	}
	return x.three<y.three;
}
bool cmp7(node x,node y){
	if(x.one==y.one){
		if(x.two==y.two)
			return x.three>y.three;
		return x.two>y.two;
	}
	return x.one>y.one;
}
bool cmp8(node x,node y){
	if(x.one==y.one){
		if(x.three==y.three)
			return x.two>y.two;
		return x.three>y.three;
	}
	return x.one>y.one;
}
bool cmp9(node x,node y){
	if(x.two==y.two){
		if(x.one==y.one)
			return x.three>y.three;
		return x.one>y.one;
	}
	return x.two>y.two;
}
bool cmp10(node x,node y){
	if(x.two==y.two){
		if(x.three==y.three)
			return x.one>y.one;
		return x.three>y.three;
	}
	return x.two>y.two;
}
bool cmp11(node x,node y){
	if(x.three==y.three){
		if(x.one==y.one)
			return x.two>y.two;
		return x.one>y.one;
	}
	return x.three>y.three;
}
bool cmp12(node x,node y){
	if(x.three==y.three){
		if(x.two==y.two)
			return x.one>y.one;
		return x.two>y.two;
	}
	return x.three>y.three;
}
void solve(){
	int cnt1,cnt2,cnt3,ans=0,sum=0,n;
	node a[100050];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].one>>a[i].two>>a[i].three;
	sort(a+1,a+1+n,cmp1);
	cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].one>=a[i].two&&a[i].two>=a[i].three){
			if(cnt1==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].one>=a[i].three&&a[i].three>=a[i].two){
			if(cnt1==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].two>=a[i].one&&a[i].one>=a[i].three){
			if(cnt2==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].two>=a[i].three&&a[i].three>=a[i].one){
			if(cnt2==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].three>=a[i].one&&a[i].one>=a[i].two){
			if(cnt3==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}else if(a[i].three>=a[i].two&&a[i].two>=a[i].one){
			if(cnt3==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}
	}
	ans=max(ans,sum);
	sort(a+1,a+1+n,cmp2);
	cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].one>=a[i].two&&a[i].two>=a[i].three){
			if(cnt1==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].one>=a[i].three&&a[i].three>=a[i].two){
			if(cnt1==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].two>=a[i].one&&a[i].one>=a[i].three){
			if(cnt2==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].two>=a[i].three&&a[i].three>=a[i].one){
			if(cnt2==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].three>=a[i].one&&a[i].one>=a[i].two){
			if(cnt3==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}else if(a[i].three>=a[i].two&&a[i].two>=a[i].one){
			if(cnt3==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}
	}
	ans=max(ans,sum);
	sort(a+1,a+1+n,cmp3);
	cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].one>=a[i].two&&a[i].two>=a[i].three){
			if(cnt1==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].one>=a[i].three&&a[i].three>=a[i].two){
			if(cnt1==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].two>=a[i].one&&a[i].one>=a[i].three){
			if(cnt2==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].two>=a[i].three&&a[i].three>=a[i].one){
			if(cnt2==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].three>=a[i].one&&a[i].one>=a[i].two){
			if(cnt3==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}else if(a[i].three>=a[i].two&&a[i].two>=a[i].one){
			if(cnt3==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}
	}
	ans=max(ans,sum);
	sort(a+1,a+1+n,cmp4);
	cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].one>=a[i].two&&a[i].two>=a[i].three){
			if(cnt1==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].one>=a[i].three&&a[i].three>=a[i].two){
			if(cnt1==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].two>=a[i].one&&a[i].one>=a[i].three){
			if(cnt2==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].two>=a[i].three&&a[i].three>=a[i].one){
			if(cnt2==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].three>=a[i].one&&a[i].one>=a[i].two){
			if(cnt3==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}else if(a[i].three>=a[i].two&&a[i].two>=a[i].one){
			if(cnt3==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}
	}
	ans=max(ans,sum);
	sort(a+1,a+1+n,cmp5);
	cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].one>=a[i].two&&a[i].two>=a[i].three){
			if(cnt1==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].one>=a[i].three&&a[i].three>=a[i].two){
			if(cnt1==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].two>=a[i].one&&a[i].one>=a[i].three){
			if(cnt2==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].two>=a[i].three&&a[i].three>=a[i].one){
			if(cnt2==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].three>=a[i].one&&a[i].one>=a[i].two){
			if(cnt3==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}else if(a[i].three>=a[i].two&&a[i].two>=a[i].one){
			if(cnt3==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}
	}
	ans=max(ans,sum);
	sort(a+1,a+1+n,cmp6);
	cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].one>=a[i].two&&a[i].two>=a[i].three){
			if(cnt1==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].one>=a[i].three&&a[i].three>=a[i].two){
			if(cnt1==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].two>=a[i].one&&a[i].one>=a[i].three){
			if(cnt2==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].two>=a[i].three&&a[i].three>=a[i].one){
			if(cnt2==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].three>=a[i].one&&a[i].one>=a[i].two){
			if(cnt3==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}else if(a[i].three>=a[i].two&&a[i].two>=a[i].one){
			if(cnt3==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}
	}
	ans=max(ans,sum);
	sort(a+1,a+1+n,cmp7);
	cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].one>=a[i].two&&a[i].two>=a[i].three){
			if(cnt1==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].one>=a[i].three&&a[i].three>=a[i].two){
			if(cnt1==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].two>=a[i].one&&a[i].one>=a[i].three){
			if(cnt2==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].two>=a[i].three&&a[i].three>=a[i].one){
			if(cnt2==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].three>=a[i].one&&a[i].one>=a[i].two){
			if(cnt3==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}else if(a[i].three>=a[i].two&&a[i].two>=a[i].one){
			if(cnt3==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}
	}
	ans=max(ans,sum);
	sort(a+1,a+1+n,cmp8);
	cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].one>=a[i].two&&a[i].two>=a[i].three){
			if(cnt1==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].one>=a[i].three&&a[i].three>=a[i].two){
			if(cnt1==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].two>=a[i].one&&a[i].one>=a[i].three){
			if(cnt2==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].two>=a[i].three&&a[i].three>=a[i].one){
			if(cnt2==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].three>=a[i].one&&a[i].one>=a[i].two){
			if(cnt3==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}else if(a[i].three>=a[i].two&&a[i].two>=a[i].one){
			if(cnt3==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}
	}
	ans=max(ans,sum);
	sort(a+1,a+1+n,cmp9);
	cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].one>=a[i].two&&a[i].two>=a[i].three){
			if(cnt1==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].one>=a[i].three&&a[i].three>=a[i].two){
			if(cnt1==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].two>=a[i].one&&a[i].one>=a[i].three){
			if(cnt2==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].two>=a[i].three&&a[i].three>=a[i].one){
			if(cnt2==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].three>=a[i].one&&a[i].one>=a[i].two){
			if(cnt3==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}else if(a[i].three>=a[i].two&&a[i].two>=a[i].one){
			if(cnt3==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}
	}
	ans=max(ans,sum);
	sort(a+1,a+1+n,cmp10);
	cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].one>=a[i].two&&a[i].two>=a[i].three){
			if(cnt1==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].one>=a[i].three&&a[i].three>=a[i].two){
			if(cnt1==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].two>=a[i].one&&a[i].one>=a[i].three){
			if(cnt2==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].two>=a[i].three&&a[i].three>=a[i].one){
			if(cnt2==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].three>=a[i].one&&a[i].one>=a[i].two){
			if(cnt3==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}else if(a[i].three>=a[i].two&&a[i].two>=a[i].one){
			if(cnt3==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}
	}
	ans=max(ans,sum);
	sort(a+1,a+1+n,cmp11);
	cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].one>=a[i].two&&a[i].two>=a[i].three){
			if(cnt1==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].one>=a[i].three&&a[i].three>=a[i].two){
			if(cnt1==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].two>=a[i].one&&a[i].one>=a[i].three){
			if(cnt2==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].two>=a[i].three&&a[i].three>=a[i].one){
			if(cnt2==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].three>=a[i].one&&a[i].one>=a[i].two){
			if(cnt3==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}else if(a[i].three>=a[i].two&&a[i].two>=a[i].one){
			if(cnt3==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}
	}
	ans=max(ans,sum);
	sort(a+1,a+1+n,cmp12);
	cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i].one>=a[i].two&&a[i].two>=a[i].three){
			if(cnt1==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].one>=a[i].three&&a[i].three>=a[i].two){
			if(cnt1==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt1++;
				sum+=a[i].one;
			}
		}else if(a[i].two>=a[i].one&&a[i].one>=a[i].three){
			if(cnt2==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].two>=a[i].three&&a[i].three>=a[i].one){
			if(cnt2==n/2){
				cnt3++;
				sum+=a[i].three;
			}else{
				cnt2++;
				sum+=a[i].two;
			}
		}else if(a[i].three>=a[i].one&&a[i].one>=a[i].two){
			if(cnt3==n/2){
				cnt1++;
				sum+=a[i].one;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}else if(a[i].three>=a[i].two&&a[i].two>=a[i].one){
			if(cnt3==n/2){
				cnt2++;
				sum+=a[i].two;
			}else{
				cnt3++;
				sum+=a[i].three;
			}
		}
	}
	ans=max(ans,sum);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
