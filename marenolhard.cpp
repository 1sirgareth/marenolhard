#include <iostream>
using namespace std;
long steps(int a, int b);  // Counts the number of steps to swap numbers at positions a and b.
void swap(char *a, char *b);

int main()
{
    int T; cin >> T;

    for (int i = 0; i < T; i++)
    {
        long long moves = 0;
        string a, b;
        int n; cin >> n;
        cin >> a >> b;
        int asumodd = 0; int asumeven = 0;
        int bsumodd = 0; int bsumeven = 0;
        for (int j = 0; j < n; j = j + 2)
        {
            asumeven = asumeven + a[j];
            bsumeven = bsumeven + b[j];
        }
        for (int j = 1; j < n; j = j + 2)
        {
            asumodd = asumodd + a[j];
            bsumodd = bsumodd + b[j];
        }
        if (asumodd != bsumodd || asumeven != bsumeven)
        {
            cout << -1 << '\n';
        }
        else 
        {
            for (int j = 0; j < n; j++)
            {
                if (a[j] != b[j])
                {
                    for (int k = j + 2; k < n; k = k + 2)
                    {
                        if (a[k] == b[j])
                        {
                            swap(&a[k], &a[j]);
                            moves =  moves + steps(j, k);
                            break;
                        }
                    }
                }
            }
            cout << moves << '\n';
        }
    }

}

long steps(int a, int b)
{
    if (b > a)
    {
        return (b - a)/2;
    }
    return (a - b)/2;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
