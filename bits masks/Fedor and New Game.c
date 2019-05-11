#include <iostream>
using namespace std;

int main() {
	int n, m, k;
    cin >> n >> m >> k;
    int a [m+1];
    for(int i=0; i<m+1;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i=0; i<m; i++) {
        int x = a[i] ^ a[m];
        int num = 0;
        while (x) {
            num+= x&1;
            x >>=1;
        }
        if (num <= k) ans++;
    }
    cout << ans << endl;
}
