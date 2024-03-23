#include <iostream>
#include <vector>

// Tulosta kaikki alkuluvut lukuun N saakka
void printPrimesUntilN(int N) {
    // Luodaan boolean-vektori alkulukujen merkitsemiseksi, alustetaan kaikki arvot todeksi.
    std::vector<bool> isPrime(N+1, true);
    
    // 0 ja 1 eivät ole alkulukuja
    isPrime[0] = isPrime[1] = false;

    for (int num = 2; num * num <= N; ++num) {
        // Jos num on merkitsemätön, se on alkuluku
        if (isPrime[num]) {
            // Merkitse numin monikerrat ei-alkuluvuiksi
            for (int multiple = num * num; multiple <= N; multiple += num) {
                isPrime[multiple] = false;
            }
        }
    }

    // Tulosta kaikki alkuluvut
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
