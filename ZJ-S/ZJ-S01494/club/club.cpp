#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=1e5+5;
int n,_,a1[N],a2[N],a3[N],f1,ans,cnt1,cnt2,cnt3,maxx,t[N],rep,cmp;
void ad1(int idx){
	rep=cmp=0;
	if(cnt1<(n/2)){
		cnt1++;
		ans+=a1[idx];
		t[idx]=1;
	}
	else{
		for(int i=1;i<idx;i++){
			if(t[i]==1){
				if(a1[idx]-a1[i]+max(a2[i],a3[i])>cmp){
					cmp=a1[idx]-a1[i]+max(a2[i],a3[i]);
					rep=i;
				}
			}
		}
		if(rep){
			ans+=cmp;
			t[idx]=1;
			if(a2[rep]>=a3[rep]){
				cnt2++;
				t[rep]=2;
			}
			else{
				cnt3++;
				t[rep]=3;
			}
		}
		else{
			if(a2[idx]>=a3[idx]){
				cnt2++;
				t[idx]=2;
				ans+=a2[idx];
			}
			else{
				cnt3++;
				t[idx]=3;
				ans+=a3[idx];
			}
		}
	}
}
void ad2(int idx){
	rep=cmp=0;
	if(cnt2<(n/2)){
		cnt2++;
		ans+=a2[idx];
		t[idx]=2;
	}
	else{
		for(int i=1;i<idx;i++){
			if(t[i]==2){
				if(a2[idx]-a2[i]+max(a1[i],a3[i])>cmp){
					cmp=a2[idx]-a2[i]+max(a1[i],a3[i]);
					rep=i;
				}
			}
		}
		if(rep){
			ans+=cmp;
			t[idx]=2;
			if(a1[rep]>=a3[rep]){
				cnt1++;
				t[rep]=1;
			}
			else{
				cnt3++;
				t[rep]=3;
			}
		}
		else{
			if(a1[idx]>=a3[idx]){
				cnt1++;
				t[idx]=1;
				ans+=a1[idx];
			}
			else{
				cnt3++;
				t[idx]=3;
				ans+=a3[idx];
			}
		}
	}
}
void ad3(int idx){
	rep=cmp=0;
	if(cnt3<(n/2)){
		cnt3++;
		ans+=a3[idx];
		t[idx]=3;
	}
	else{
		for(int i=1;i<idx;i++){
			if(t[i]==3){
				if(a3[idx]-a3[i]+max(a2[i],a1[i])>cmp){
					cmp=a3[idx]-a3[i]+max(a2[i],a1[i]);
					rep=i;
				}
			}
		}
		if(rep){
			ans+=cmp;
			t[idx]=3;
			if(a2[rep]>=a1[rep]){
				cnt2++;
				t[rep]=2;
			}
			else{
				cnt1++;
				t[rep]=1;
			}
		}
		else{
			if(a2[idx]>=a1[idx]){
				cnt2++;
				t[idx]=2;
				ans+=a2[idx];
			}
			else{
				cnt1++;
				t[idx]=1;
				ans+=a1[idx];
			}
		}
	}
}
void ad(int idx){
	if(maxx==a1[idx]) ad1(idx);
	else if(maxx==a2[idx]) ad2(idx);
	else if(maxx==a3[idx]) ad3(idx);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>_;
	while(_--)
	{
		cin>>n;
		f1=1;
		ans=cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]||a3[i]) f1=0;
			t[i]=0;
		}
		if(f1)
		{
			sort(a1+1,a1+n+1);
			for(int i=n;i>n/2;i--) ans+=a1[i];
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			maxx=max(a1[i],max(a2[i],a3[i]));
			ad(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
