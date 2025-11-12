#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long s,n,m,na=0,ma=1,cnt=0,f=0;
	cin>>n>>m;
	s=n*m;
	int a[s+5];
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	int sc=a[1];
	sort(a+1,a+s,greater<int>());


	for(int i=1;i<=s;i++){
		if(f==0) na++;
		else na--;
		cnt++;

		if(a[cnt]==sc){
			cout<<ma<<' '<<na;
			break;
		}

		if(na==n&&(cnt!=1&&cnt%n==0)){
			f=1;
			na++;
			ma++;
		}
		if(na==1&&(cnt!=1&&cnt%n==0)){
			f=0;
			ma++;
			na--;
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}