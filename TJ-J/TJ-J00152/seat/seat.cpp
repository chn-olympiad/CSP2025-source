#include <bits/stdc++.h>
using namespace std;
int n,m;
int g[105][105];
struct node{
    int id,scr;
    bool operator==(const node &x)const{
        if(x.id==id&&x.scr==scr) return true;
        else return false;
    }
}a[1005];
node r;
bool cmp(node x,node y){
    return x.scr>y.scr;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) a[i].id=i,cin>>a[i].scr;
    r.id=1,r.scr=a[1].scr;
    sort(a+1,a+n*m+1,cmp);
    /*
    for(int i=1;i<=n*m;i++){
        cerr<<a[i].id<<' '<<a[i].scr<<"\n";
    }
    */
    int rk=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            rk=i;
            break;
        }
        /*
        cerr<<a[i].id<<' '<<a[i].scr<<' '<<rk<<'\n';
        */
    }
    /*
    cerr<<r.id<<' '<<r.scr<<' '<<rk<<'\n';
    */
    if(n==1){
        cout<<rk<<' '<<n<<endl;
        return 0;
    }
    if(m==1){
        cout<<m<<' '<<rk<<endl;
        return 0;
    }
    //int col=ceil(rk/n);
    //int zhouqi=rk/(2*n),more=rk%(2*n);
    int ans1,ans2;
    ans1=ans2=-1;
    /*
    for(int q=1;q<=m;q+=2){
        if(rk<=0)break;
        cerr<<rk<<endl;
        for(int w=1;w<=n;w++){
            rk--;
            if(rk==0){
                ans1=q,ans2=w;
                break;
            }
        }
        cerr<<rk<<endl;
        q++;
        for(int w=n;w>=1;w--){
            rk--;
            if(rk==0){
                ans1=q,ans2=w;
                break;
            }
        }
    }
    */
    for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			rk--;
			if(rk==0){
				ans1=i,ans2=j;
			}
		}
		i++;
		for(int j=n;j>=1;j--){
			rk--;
			if(rk==0){
				ans1=i,ans2=j;
			}
		}
    }
    cout<<ans1<<' '<<ans2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
