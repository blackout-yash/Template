int add(int a, int b, int m = MOD) {a %= m; b %= m; return (((a + b) % m) + m) % m;}
int sub(int a, int b, int m = MOD) {a %= m; b %= m; return (((a - b) % m) + m) % m;}
int mul(int a, int b, int m = MOD) {a %= m; b %= m; return (((a * b) % m) + m) % m;}