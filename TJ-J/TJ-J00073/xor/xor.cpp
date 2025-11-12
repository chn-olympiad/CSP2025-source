#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
unsigned int n,k,r,x,maxi,prevr,nowl,nowr,sum,arr[500000],eq[500000][2],under;
bitset<500000> ic;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
        cin>>arr[i];
	}
    for(int i=0;i<n;i++){
        if(!arr[i]) continue;
        x=arr[i];
        r=i;
        while(x!=k&&r<n){
            r++;
            x^=arr[r];
        }
        if(r==n) continue;
        eq[under][0]=i;
        eq[under][1]=r;
        ic[under]=0;
        under++;
    }
    under--;
    for(int i=0;i<=under;i++){
        if(ic[i]) continue;
        prevr=eq[i][1];
        sum=1;
        for(int j=i+1;j<=under;j++){
            nowl=eq[j][0];
            nowr=eq[j][1];
            if(nowl>prevr){
                sum++;
                prevr=nowr;
                ic[j]=1;
            }
        }
        maxi=max(maxi,sum);
    }
    cout<<maxi;
	return 0;
}
