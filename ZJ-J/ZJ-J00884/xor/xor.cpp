#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s1[500010],s2[500010],ans,cnt,s3[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k){
			ans++;
		}
		s3[i]=a[i];
	}
	cnt=n-1;
	memset(s1,-1,sizeof(s1));
	memset(s2,-1,sizeof s2);
	for(int i=1;i<=n-1;i++){
		if(a[i]==k||a[i+1]==k){
			continue;
			cnt--;
		}
		s1[i]=a[i]^a[i+1];
	}
	while(cnt>1){
		for(int i=1;i<=cnt;i++){
			if(s1[i]==k){
				ans++;
			}
		}
		for(int i=1;i<=cnt-1;i++){
			if(s1[i]==k||s1[i+1]==k){
				continue;
				cnt--;
			}
			if(s1[i]!=-1&&s1[i+1]!=-1){
				s2[i]=s1[i]^s1[i+1]^s3[i+1];
			}
		}
		for(int i=1;i<=cnt;i++){
			s3[i]=s1[i];
			s1[i]=s2[i];
			s2[i]=-1;
		}
		cnt--;
	}
	cout<<ans;
}
