#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int l[5001],a[5001];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	if(n<3){
		//cout<<0;
		return 0;
	}
	if(n==3){
		int maxn=0,cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=l[i];
			if(l[i]>maxn) maxn=l[i];
		}
		if(cnt>2*maxn) //cout<<1;
		else //cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(l[i]+l[j]+l[k]>2*max(l[i],max(l[j],l[k]))){
					ans++;
				}
				for(int q=k+1;q<=n;q++){
					if(l[i]+l[j]+l[k]+l[q]>2*max(max(l[i],l[q]),max(l[j],l[k]))){
					    ans++;
				    }
				}
			}
		}
	}
	if(l[1]+l[2]+l[3]+l[4]+l[5]>2*max(max(l[1],max(l[2],l[3])),max(l[4],l[5]))){
		ans++;
	}
	//cout<<ans;
	return 0;
}
