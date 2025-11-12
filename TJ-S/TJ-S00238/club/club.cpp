#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int T;
int sum,ans1,ans2,ans3;
int n;
int st1[10005],st2[10005],st3[10005];
int a[1000005],b[100005],c[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		sum,ans1,ans2,ans3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			st1[i]=i,st2[i]=i,st3[i]=i;
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++){
			if(ans1<=n/2){
				sum+=a[i];
				ans1++;
			}
			else if(ans2<=n/2){
				sum+=b[i];
				ans2++;
			}
			else if(ans3<=n/2){
				sum+=c[i];
				ans3++;
			}
		}
		cout<<sum;
	}
}

