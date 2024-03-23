#include <iostream>
#include <vector>


void printPrimesUntilN(int N) {
    // Alustetaan bit-vektori, jossa jokainen bitti edustaa yhtä lukua.
    std::vector<bool> isPrime(N + 1, true);

    // 0 ja 1 eivät ole alkulukuja.
    isPrime[0] = isPrime[1] = false;

    // Käydään läpi luvut 2:sta sqrt(N) saakka.
    for (int num = 2; num * num <= N; ++num) {
        // Jos luku on alkuluku...
        if (isPrime[num]) {
            // Merkitään sen monikerrat ei-alkuluvuiksi.
            for (int multiple = num * num; multiple <= N; multiple += num) {
                isPrime[multiple] = false;
            }
        }
    }

    for (int num = 2; num <= N; ++num) {
        if (isPrime[num]) {
            std::cout << num << " ";
        }
    }
}

int main() {
    int N;
    std::cout << "Anna N: ";
    std::cin >> N;

    std::cout << "Alkuluvut lukuun " << N << " saakka ovat: ";
    printPrimesUntilN(N);
    std::cout << std::endl;

    return 0;
}
