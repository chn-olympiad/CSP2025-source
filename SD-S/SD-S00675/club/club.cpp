#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100010],b[100010],c[100010],w[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int j=1;
	while(t){
		cin>>n;
		int ans=0;
		int sum[5]={0},cha1[100010]={0},cha2[100010]={0};
		int ge1=1,ge2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]){
				ans+=a[i];
				cha1[ge1]=a[i]-b[i];
				ge1++;
				sum[1]++;
			}
			else {
				ans+=b[i];			
				cha2[ge2]=b[i]-a[i];
				ge2++;
				sum[2]++;
			}
		}
		sort(cha1+1,cha1+ge1);
		sort(cha2+1,cha2+ge2);
		int k=1;
		while(sum[1]>(n/2)){
			sum[1]--;
			ans-=cha1[k];
			k++;
		}
		while(sum[2]>(n/2)){
			sum[2]--;
			ans-=cha2[k];
			k++;
		}
		w[j]=ans;
		j++;
		t--;
	}
	for(int i=1;i<j;i++){
		cout<<w[i]<<'\n';
	}
	return 0;
}

