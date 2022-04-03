#include<iostream>
using namespace std;

int main() {
    int a, b, r, r1, r2, q, s, s1 = 1, s2 = 0, t, t1 = 0, t2 = 1, ra;
    cin >> a >> b;
    if (a > b) ra = r1 = a, r2 = b;
    else ra = r1 = b, r2 = a;
    while (1) {
        q = r1 / r2; r = r1 % r2; s = s1 - q * s2; t = t1 - q * t2;
        r1 = r2; r2 = r; s1 = s2; s2 = s; t1 = t2; t2 = t;
        if (r == 0) break;
    }
    cout << "s = " << s1 << "\nt = " << t1;
    if (r1 == 1) cout << "\n역원 = " << ra + t1;
}