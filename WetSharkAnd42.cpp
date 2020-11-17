#include <bits/stdc++.h>

using namespace std;

#define MOD (1000000000 + 7)
typedef unsigned long long ull;

// Complete the solve function below.
int solve(long s) {
    ull i=1;
    ull x = (s-1)/20;
    return ((s+x)*2) %MOD;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = solve(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
