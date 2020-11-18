#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef vector<ull> vull;

// Complete the pythagoreanTriple function below.
vull pythagoreanTriple(ull a) {
    vull v;
    v.push_back(a);
    ull A = a*a;
    ull b = (A-1)/2;
    ull c = b+1;
        
    if(a%2 == 0){
        b = (A-4)/4;
        c = b+2;
    }
    
    v.push_back(b);
    v.push_back(c);
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    ull a;
    cin >> a;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vull triple = pythagoreanTriple(a);

    for (int i = 0; i < triple.size(); i++) {
        fout << triple[i];

        if (i != triple.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
