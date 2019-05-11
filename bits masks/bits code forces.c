#include"bits/stdc++.h"
#define ll long long
#define clr(a,b) memset(a,b sizeof a)
#define inf 1e18+1
#define lld I64d
using namespace std;
int t;
ll l,r;
int main(){
    ///freopen("test.txt","r",stdin);
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&l,&r);
		while((l|(l+1))<=r)
            l|=(l+1);
		printf("%lld\n",l);
	}
	return 0;
}
