#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

bool simulate(int n) {
    vector<bool> taken(n + 1, false);

    // перший пасажир обирає місце навмання
    int firstSeat = rand() % n + 1;
    taken[firstSeat] = true;

    // пасажири 2..n-1
    for (int i = 2; i < n; i++) {
        if (!taken[i]) {
            taken[i] = true; // сидить на своєму місці
        }
        else {
            // вибрати випадкове вільне місце
            int freeCount = 0;

            for (int j = 1; j <= n; j++)
                if (!taken[j]) freeCount++;

            int r = rand() % freeCount;

            for (int j = 1; j <= n; j++) {
                if (!taken[j]) {
                    if (r == 0) {
                        taken[j] = true;
                        break;
                    }
                    r--;
                }
            }
        }
    }
    // останній пасажир перевіряє місце n
    return !taken[n];
}

int main() {
    srand(time(0));

    int n = 100;
    int trials = 20000;

    int success = 0;

    for (int i = 0; i < trials; i++) {
        if (simulate(n)) success++;
    }

    cout << "Airplane boarding simulation\n";
    cout << "Number of seats: " << n << endl;
    cout << "Number of trials: " << trials << endl;

    cout << "Probability that last passenger sits in his own seat: "
        << (double)success / trials << endl;

    return 0;
}